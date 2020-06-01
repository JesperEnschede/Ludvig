//
// Created by Jesper on 5/11/2020.
//

#include "Renderer.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "gtc/matrix_transform.hpp"

Ludvig::Rendering::Renderer::Renderer(Window* window)
{
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::printf("Error: failed to load openGL!");
        std::printf("OpenGL: major: %d  minor: %d", GLVersion.major, GLVersion.minor);

        return;
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

    this->textures.push_back(std::make_unique<Core::Scene::Texture>("assets/textures/grey.jpg"));

    std::vector<const char*> faces = { "assets/skybox/right.jpg",
                                       "assets/skybox/left.jpg",
                                       "assets/skybox/top.jpg",
                                       "assets/skybox/bottom.jpg",
                                       "assets/skybox/front.jpg",
                                       "assets/skybox/back.jpg"};

    this->cubeMaps.push_back(std::make_unique<Cubemap>(faces));
}

void Ludvig::Rendering::Renderer::clear(int mask)
{
    glClear(mask);
}

void Ludvig::Rendering::Renderer::render_scene(Ludvig::Core::Scene::Scene *scene)
{
    glPolygonMode(GL_FRONT, GL_FILL);

    scene->camera->calculate_view_projection_matrix();
    glm::mat4 viewProjectionMatrix = scene->camera->get_view_projection_matrix();

    this->shaders[0]->set_vec3("lightPosition_worldSpace",scene->light->transform->get_position());
    this->shaders[0]->set_float("lightPower",scene->light->intensity);
    this->shaders[0]->set_vec3("lightColor",scene->light->color);
    this->shaders[0]->set_vec3("ambientColor",scene->lightSettings->ambientLightColor);
    this->shaders[0]->set_mat4x4("V",scene->camera->get_view_matrix());

    for (int i = 0; i < scene->meshes.size(); ++i)
    {
        Core::Scene::Mesh* mesh = scene->meshes[i].get();

        glm::mat4 mvp = viewProjectionMatrix * mesh->transform->get_trs();

        glUseProgram(this->shaders[0]->get_program());

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, this->textures[0]->id);
        this->shaders[0]->set_texture("textureSampler",this->textures[0]->id);
        this->shaders[0]->set_mat4x4("M",mesh->transform->get_trs());
        this->shaders[0]->set_mat4x4("MVP",mvp);

        //todo: fix vertex attrib array enable : disable :(
        glEnableVertexAttribArray(0);
        glEnableVertexAttribArray(1);
        glEnableVertexAttribArray(2);

        mesh->get_vao()->bind();

        glDrawArrays(GL_TRIANGLES,0,mesh->get_vertices_size()); // todo FIX INDICES!

        glDisableVertexAttribArray(0);
        glDisableVertexAttribArray(1);
        glDisableVertexAttribArray(2);
    }
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


