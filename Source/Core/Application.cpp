//
// Created by Jesper on 5/11/2020.
//

#include <Scene/Scene.h>
#include "Application.h"
#include "Debug/DebugLog.h"
#include "Scene/SceneManager.h"
using namespace Ludvig::SceneManagement;

#include "DearImGui/imgui.h" // FIXME: remove later!

#include "chrono"

namespace Ludvig
{
    namespace Core
    {
        Application::Application()
        {
            Debug::DebugLog::log_message("Initializing Ludvig " + this->version);

            this->window = std::make_unique<Rendering::Window>(1280,720, false);
            this->renderer = std::make_unique<Rendering::Renderer>(this->window.get());
        }

        void Application::start()
        {
            Debug::DebugLog::log_message("Starting Ludvig runtime");

            if (!isRunning)
                runtime();
            else
                Debug::DebugLog::log_error("Attempting to start runtime whilst runtime is already active!", true);
        }

        void Application::runtime()
        {
            auto timePoint1 = std::chrono::system_clock::now();
            auto timePoint2 = std::chrono::system_clock::now();

            this->isRunning = true;
            while (!this->window->is_closing())
            {
                timePoint2 = std::chrono::system_clock::now();
                std::chrono::duration<float> deltaTime = timePoint2 - timePoint1;
                timePoint1 = timePoint2;

                this->renderer->clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                // FIXME: Temp input system for camera movement.
                float forwardInput = glfwGetKey(window->get_context(),GLFW_KEY_W);
                float backwardsInput = -glfwGetKey(window->get_context(),GLFW_KEY_S);
                float rightInput = -glfwGetKey(window->get_context(),GLFW_KEY_D);
                float leftInput = glfwGetKey(window->get_context(),GLFW_KEY_A);
                float upInput = glfwGetKey(window->get_context(),GLFW_KEY_SPACE);
                float downInput = -glfwGetKey(window->get_context(),GLFW_KEY_LEFT_SHIFT);

                // FIXME: Temp cameras movement.

                SceneManager::get_current_scene()->camera->transform->translate(
                        (rightInput + leftInput) * 30.0f * deltaTime.count(),
                        (upInput + downInput) * 30.0f * deltaTime.count(),
                        (forwardInput + backwardsInput) * 30.0f * deltaTime.count());

                this->renderer->render_scene(SceneManager::get_current_scene());

                this->renderer->create_gui_frame();
                ImGui::Begin("Profiler");
                ImGui::Text("%.3f ms/frame | %.3f FPS", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
                ImGui::End();
                this->renderer->draw_gui_frame();

                this->window->swap_buffers();
                this->window->poll_events();
            }
            this->isRunning = false;
        }
    }
}

