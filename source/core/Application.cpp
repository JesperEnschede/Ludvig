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

        float yawPlusInput = -glfwGetKey(window->get_context(),GLFW_KEY_R);
        float yawMinusInput = glfwGetKey(window->get_context(),GLFW_KEY_F);
        float pitchPlusInput = glfwGetKey(window->get_context(),GLFW_KEY_T);
        float pitchMinusInput = -glfwGetKey(window->get_context(),GLFW_KEY_G);
        float rollPlusInput = -glfwGetKey(window->get_context(),GLFW_KEY_Y);
        float rollMinusInput = glfwGetKey(window->get_context(),GLFW_KEY_H);

        // Temp cameras movement.
        scene->camera->transform->translate(
                (rightInput + leftInput) / 150,
                (upInput + downInput) / 150,
                (forwardInput + backwardsInput) / 150);

        scene->meshes[0]->transform->set_scale(
                (yawPlusInput + yawMinusInput) / 150,
                (pitchPlusInput + pitchMinusInput) / 150,
                (rollPlusInput + rollMinusInput) / 150);

        this->renderer->render_scene(this->scene.get());

        this->renderer->create_gui_frame();
        // this->guiManager->draw_windows();

        ImGui::Begin("profiler");
        ImGui::Text("%.3f ms/frame | %.3f FPS", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
        ImGui::End();

        ImGui::Begin("Camera");
        ImGui::Text("Position | %.2f %.2f %.2f", scene->camera->transform->get_position().x,scene->camera->transform->get_position().y,scene->camera->transform->get_position().z);
        ImGui::Text("Rotation | %.2f %.2f %.2f", scene->camera->transform->get_rotation().x,scene->camera->transform->get_rotation().y,scene->camera->transform->get_rotation().z);
        ImGui::Text("Scale | %.2f %.2f %.2f", scene->camera->transform->get_scale().x,scene->camera->transform->get_scale().y,scene->camera->transform->get_scale().z);
        ImGui::End();

        this->renderer->draw_gui_frame();

        this->window->swap_buffers();
    }
}
