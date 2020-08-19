//
// Created by Jesper on 5/11/2020.
//

#include "Application.h"
#include "Debug/DebugLog.h"

// OpenGL renderer
#include "Rendering/OpenGL/OpenGLRenderManager.h"
#include "Rendering/OpenGL/OpenGLWindow.h"

// Vulkan renderer
#include "Rendering/Vulkan/VulkanRenderManager.h"
#include "Rendering/Vulkan/VulkanWindow.h"

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

            scene = std::make_unique<Core::Scene>();

            // TODO(Jesper) get window initial width/height from a config file.
            if (API == "OpenGL") {
                window = std::make_unique<Rendering::OpenGL::OpenGLWindow>("Ludvig | OpenGL", 1280,720);
                renderManager = std::make_unique<Rendering::OpenGL::OpenGLRenderManager>(window.get());
            } else if (API == "Vulkan") {
                window = std::make_unique<Rendering::Vulkan::VulkanWindow>("Ludvig | Vulkan", 1280,720);
                renderManager = std::make_unique<Rendering::Vulkan::VulkanRenderManager>();
            } else if (API == "Direct3D12") {
                Debug::DebugLog::log_error("Direct3D 12 API is not implemented yet.", true);
            } else if (API == "Direct3D9") {
                Debug::DebugLog::log_error("Direct3D 9 API is not implemented yet.", true);
            } else {
                Debug::DebugLog::log_error("Given API is not available.", true);
            }

            guiManager = std::make_unique<GUI::GUIManager>(scene.get());

            renderManager->set_active_camera(scene->camera.get());
            renderManager->create_mesh_renderer(scene->mesh.get());
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

                renderManager->render(scene.get());
            }
            this->isRunning = false;
        }
    }
}

