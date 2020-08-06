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
            std::string API = "OpenGL"; // TODO(Jesper) read the API from a config file

            Debug::DebugLog::log_message("Initializing Ludvig " + this->version + " | Graphics API: " + API);

            if (API == "OpenGL") {
                window = std::make_unique<Rendering::OpenGL::OpenGLWindow>("Ludvig | OpenGL", 800,600);
                renderManager = std::make_unique<Rendering::OpenGL::OpenGLRenderManager>(window.get());
            } else {
                Debug::DebugLog::log_error("Given API not available.", true);
            }
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
            this->isRunning = true;
            while (!window->is_Closing())
            {
                window->poll_window_events();

                renderManager->render();
            }
            this->isRunning = false;
        }
    }
}

