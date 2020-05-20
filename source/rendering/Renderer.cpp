//
// Created by Jesper on 5/11/2020.
//

#include "Renderer.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

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

    this->shaders.push_back(std::make_unique<Core::Scene::Shader>("default_vertex.glsl","default_fragment.glsl"));
    this->textures.push_back(std::make_unique<Core::Scene::Texture>("grey.jpg"));
}

void Ludvig::Rendering::Renderer::clear(int mask)
{
    glClear(mask);
}

void Ludvig::Rendering::Renderer::render_scene(Ludvig::Core::Scene::Scene *scene)
{
    scene->camera->calculate_view_projection_matrix();
    glm::mat4 viewProjectionMatrix = scene->camera->get_view_projection_matrix();

    for (int i = 0; i < scene->meshes.size(); ++i)
    {
        Core::Scene::Mesh* mesh = scene->meshes[i].get();

        glm::mat4 mvp = viewProjectionMatrix * mesh->transform->get_trs();

        glUseProgram(this->shaders[0]->get_program());

        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, this->textures[0]->id);
        this->shaders[0]->set_texture("textureSampler",this->textures[0]->id);

        this->shaders[0]->set_mat4x4("MVP",mvp);
        this->shaders[0]->set_mat4x4("M",mesh->transform->get_trs());
        this->shaders[0]->set_mat4x4("V",scene->camera->get_view_matrix());
        this->shaders[0]->set_vec3("lightPosition_worldSpace",scene->light->transform->get_position());

        // Vertex buffer
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, mesh->vbo);
        glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE,0,(void*)0);

        // UV buffer
        glEnableVertexAttribArray(1);

        glBindBuffer(GL_ARRAY_BUFFER, mesh->ubo);
        glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,0,(void*)0);

        // Normal buffer
        glEnableVertexAttribArray(2);

        glBindBuffer(GL_ARRAY_BUFFER, mesh->nbo);
        glVertexAttribPointer(2,3,GL_FLOAT,GL_FALSE,0,(void*)0);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->ebo);
        //glDrawElements(GL_TRIANGLES,mesh->get_mesh_indices().size(), GL_UNSIGNED_INT, nullptr);
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


