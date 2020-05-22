//
// Created by Jesper on 5/11/2020.
//

#include "Application.h"

#include "imgui.h"

Ludvig::Core::Application::Application()
{
    this->window = std::make_unique<Rendering::Window>(800,600,true);
    this->renderer = std::make_unique<Rendering::Renderer>(this->window.get());
    this->scene = std::make_unique<Scene::Scene>();
    this->guiManager = std::make_unique<GUI::GUIManager>();
}

void Ludvig::Core::Application::start()
{
    runtime();
}

void Ludvig::Core::Application::runtime()
{
    while (!this->window->is_closing())
    {
        this->renderer->clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        this->window->poll_events();

        // Temp input system for camera movement.
        float forwardInput = -glfwGetKey(window->get_context(),GLFW_KEY_W);
        float backwardsInput = glfwGetKey(window->get_context(),GLFW_KEY_S);
        float rightInput = glfwGetKey(window->get_context(),GLFW_KEY_D);
        float leftInput = -glfwGetKey(window->get_context(),GLFW_KEY_A);
        float upInput = -glfwGetKey(window->get_context(),GLFW_KEY_SPACE);
        float downInput = glfwGetKey(window->get_context(),GLFW_KEY_LEFT_SHIFT);

        // Temp cameras movement.
        scene->camera->transform->translate(
                (rightInput + leftInput) / 150,
                (upInput + downInput) / 150,
                (forwardInput + backwardsInput) / 150);

        this->renderer->render_scene(this->scene.get());

        this->renderer->create_gui_frame();
        this->guiManager->draw_windows();

        ImGui::Begin("Camera");
        float cpos[3] = { scene->camera->transform->position.x,scene->camera->transform->position.y,scene->camera->transform->position.z };
        ImGui::DragFloat3("Position",cpos,0.1f);
        scene->camera->transform->position = { cpos[0], cpos[1], cpos[2] };

        float crot[3] = { scene->camera->transform->rotation.x,scene->camera->transform->rotation.y,scene->camera->transform->rotation.z };
        ImGui::DragFloat3("Rotation",crot,0.1f);
        scene->camera->transform->rotation = { crot[0], crot[1], crot[2] };

        float cfov = scene->camera->fieldOfView;
        ImGui::DragFloat("Field of view",&cfov,0.1f,1,179.99f);
        scene->camera->fieldOfView = cfov;

        float cnear = scene->camera->nearClipping;
        ImGui::DragFloat("Near clipping",&cnear,0.01f,0.0001,INT_MAX);
        scene->camera->nearClipping = cnear;

        float cfar = scene->camera->farClipping;
        ImGui::DragFloat("Far clipping",&cfar,0.01f,0.0001,INT_MAX);
        scene->camera->farClipping = cfar;
        ImGui::End();

        ImGui::Begin("Light");

        float lpos[3] = { scene->light->transform->position.x,scene->light->transform->position.y,scene->light->transform->position.z };
        ImGui::DragFloat3("Position",lpos,0.1f);
        scene->light->transform->position = { lpos[0], lpos[1], lpos[2] };

        float lrot[3] = { scene->light->transform->rotation.x,scene->light->transform->rotation.y,scene->light->transform->rotation.z };
        ImGui::DragFloat3("Rotation",lrot,0.1f);
        scene->light->transform->rotation = { lrot[0], lrot[1], lrot[2] };

        float color[3] = { scene->light->color.x,scene->light->color.y,scene->light->color.z };
        ImGui::ColorEdit3("Light color",color);
        scene->light->color.x = color[0];
        scene->light->color.y = color[1];
        scene->light->color.z = color[2];

        ImGui::DragFloat("Light intensity",&scene->light->intensity,0.25f,0,INT_MAX);

        ImGui::End();

        ImGui::Begin("Mesh");

        float mpos[3] = { scene->meshes[0]->transform->position.x,scene->meshes[0]->transform->position.y,scene->meshes[0]->transform->position.z };
        ImGui::DragFloat3("Position",mpos,0.1f);
        scene->meshes[0]->transform->position = { mpos[0], mpos[1], mpos[2] };

        float mrot[3] = { scene->meshes[0]->transform->rotation.x,scene->meshes[0]->transform->rotation.y,scene->meshes[0]->transform->rotation.z };
        ImGui::DragFloat3("Rotation",mrot,0.1f);
        scene->meshes[0]->transform->rotation = { mrot[0], mrot[1], mrot[2] };

        float mscl[3] = { scene->meshes[0]->transform->scale.x,scene->meshes[0]->transform->scale.y,scene->meshes[0]->transform->scale.z };
        ImGui::DragFloat3("Scale",mscl,0.1f);
        scene->meshes[0]->transform->scale = { mscl[0], mscl[1], mscl[2] };

        ImGui::End();

        this->renderer->draw_gui_frame();

        this->window->swap_buffers();
    }
}
