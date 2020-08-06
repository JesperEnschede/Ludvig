//
// Created by Jesper on 5/11/2020.
//

#include <Scene/Scene.h>
#include "Application.h"
#include "Debug/DebugLog.h"
#include "Scene/SceneManager.h"

// OpenGL renderer
#include "Rendering/OpenGL/OpenGLWindow.h"
#include "Rendering/OpenGL/OpenGLRenderManager.h"

using namespace Ludvig::SceneManagement;

#include "DearImGui/imgui.h" // FIXME: remove later!

#include "chrono"

namespace Ludvig
{
    namespace Core
    {
        Application::Application()
        {
            std::string API = "OpenGL";

            Debug::DebugLog::log_message("Initializing Ludvig " + this->version + " | Graphics API: " + API);

            if (API == "OpenGL") {
                window = std::make_unique<Rendering::OpenGL::OpenGLWindow>("Ludvig | OpenGL", 800,600);
            } else {
                Debug::DebugLog::log_warning("Given API not available, defaulting to OpenGL");
            }

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
            while (isRunning)
            {
                timePoint2 = std::chrono::system_clock::now();
                std::chrono::duration<float> deltaTime = timePoint2 - timePoint1;
                timePoint1 = timePoint2;

                this->renderer->clear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                this->renderer->render_scene(SceneManager::get_current_scene());

                this->renderer->create_gui_frame();
                ImGui::Begin("Profiler");
                ImGui::Text("%.3f ms/frame | %.3f FPS", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
                ImGui::End();
                this->renderer->draw_gui_frame();
            }
            this->isRunning = false;
        }
    }
}

