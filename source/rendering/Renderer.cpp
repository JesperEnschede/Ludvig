//
// Created by Jesper on 5/11/2020.
//

#include "Renderer.h"

#include "../debug/DebugLog.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

Ludvig::Rendering::Renderer::Renderer(Window* window)
{
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        Debug::DebugLog::log_error("Failed to load openGL | GLVersion.major: " + std::to_string(GLVersion.major) + " GLVersion.minor: "+ std::to_string(GLVersion.minor));
    }
    else
    {
        Debug::DebugLog::log_message("Successfully initialized renderer");
    }

    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    ImGui_ImplGlfw_InitForOpenGL(window->get_context(), true);
    ImGui_ImplOpenGL3_Init("#version 130");

    glClearColor(0.1f,0.1f,0.1f,1);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_CULL_FACE);

    this->shaders.push_back(std::make_unique<Core::Scene::Shader>("assets/shaders/default_vertex.glsl","assets/shaders/default_fragment.glsl"));
    this->shaders.push_back(std::make_unique<Core::Scene::Shader>("assets/shaders/skybox_vertex.glsl","assets/shaders/skybox_fragment.glsl"));
    this->shaders.push_back(std::make_unique<Core::Scene::Shader>("assets/shaders/framebuffer_vertex.glsl","assets/shaders/framebuffer_fragment.glsl"));

    this->textures.push_back(std::make_unique<Core::Scene::Texture>("assets/textures/monkey.jpg"));

    std::vector<const char*> faces = { "assets/skybox/right.jpg",
                                       "assets/skybox/left.jpg",
                                       "assets/skybox/top.jpg",
                                       "assets/skybox/bottom.jpg",
                                       "assets/skybox/front.jpg",
                                       "assets/skybox/back.jpg"};

    this->cubeMaps.push_back(std::make_unique<Cubemap>(faces));

    this->frameBuffer = std::make_unique<FrameBuffer>();
}

void Ludvig::Rendering::Renderer::clear(int mask)
{
    glClear(mask);
}

void Ludvig::Rendering::Renderer::render_scene(Ludvig::Core::Scene::Scene *scene)
{
    frameBuffer->bind(GL_FRAMEBUFFER);
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // glPolygonMode(GL_FRONT, GL_LINE);

    scene->camera->calculate_view_projection_matrix();
    glm::mat4 viewProjectionMatrix = scene->camera->get_view_projection_matrix();

    glUseProgram(this->shaders[0]->get_program());
    this->shaders[0]->set_mat4x4("view",scene->camera->get_view_matrix());
    this->shaders[0]->set_mat4x4("projection",scene->camera->get_projection_matrix());
    this->shaders[0]->set_vec3("directionalLight.direction", scene->light[0]->transform->rotation);
    this->shaders[0]->set_vec3("directionalLight.ambient", scene->lightSettings->ambientLightColor * scene->lightSettings->intensity);
    this->shaders[0]->set_vec3("directionalLight.diffuse", scene->light[0]->color - glm::vec3(0.1f, 0.1f, 0.1f) * scene->light[0]->intensity);
    this->shaders[0]->set_vec3("directionalLight.specular", scene->light[0]->color * scene->light[0]->intensity);
    this->shaders[0]->set_vec3("viewPosition",scene->camera->transform->position);
    this->shaders[0]->set_texture("material.diffuse",this->textures[0]->id);
    this->shaders[0]->set_texture("material.specular",this->textures[0]->id);
    this->shaders[0]->set_float("material.shininess",32.0f);

    glUseProgram(frameBuffer->get_screen_shader()->get_program());
    this->frameBuffer->get_screen_shader()->set_bool("post_kernel", scene->postProcessingVolume->enable_kernel);
    for (int j = 0; j < 9; ++j)
    {
        this->frameBuffer->get_screen_shader()->set_float(std::string("kernel[ " + std::to_string(j) + " ]").c_str(), scene->postProcessingVolume->kernel[0]);
    }

    this->frameBuffer->get_screen_shader()->set_bool("post_colorShift", scene->postProcessingVolume->enable_colorShift);
    this->frameBuffer->get_screen_shader()->set_vec3("colorShift", glm::vec3(scene->postProcessingVolume->colorShift[0],scene->postProcessingVolume->colorShift[1],scene->postProcessingVolume->colorShift[2]));
    this->frameBuffer->get_screen_shader()->set_bool("post_invert", scene->postProcessingVolume->enable_invert);

    glUseProgram(this->shaders[0]->get_program());

    for (int i = 0; i < scene->meshes.size(); ++i)
    {
        Core::Scene::Mesh* mesh = scene->meshes[i].get();

        glm::mat4 mvp = viewProjectionMatrix * mesh->transform->get_trs();

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, this->textures[0]->id);
        this->shaders[0]->set_mat4x4("model",mesh->transform->get_trs());

        //todo: fix vertex attrib array enable : disable :(
        mesh->get_vao()->bind();
        //glDrawElements(GL_TRIANGLES, mesh->get_vertices_size(), GL_UNSIGNED_SHORT, (void*)0);
        glDrawArrays(GL_TRIANGLES,0,mesh->get_vertices_size()); // todo FIX INDICES!

        glBindVertexArray(0);
    }

    glBindFramebuffer(GL_FRAMEBUFFER,0);
    // glPolygonMode(GL_FRONT, GL_LINE);
    glDisable(GL_DEPTH_TEST);
    glClearColor(0.1f,0.1f,0.1f,1);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(frameBuffer->get_screen_shader()->get_program());

    frameBuffer->get_screen_quad_mesh()->get_vao()->bind();
    glBindTexture(GL_TEXTURE_2D, frameBuffer->get_color_buffer_texture()->id);

    glDrawArrays(GL_TRIANGLES,0,6);
}

void Ludvig::Rendering::Renderer::create_gui_frame()
{
    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();
}

void Ludvig::Rendering::Renderer::draw_gui_frame()
{
    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}


