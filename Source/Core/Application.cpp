//
// Created by Jesper on 5/11/2020.
//

// General
#include "Application.h"
#include "Debug/DebugLog.h"
#include "Data/UserConfig.h"

// D3D general
#include "Rendering/D3D/Win32Window.h"

// D3DX11
#include "Rendering/D3D/D3DX11/D3DX11RenderManager.h"

// OpenGL renderer
#include "Rendering/OpenGL/OpenGLRenderManager.h"
#include "Rendering/OpenGL/OpenGLWindow.h"

// Vulkan renderer
#include "Rendering/Vulkan/VulkanRenderManager.h"
#include "Rendering/Vulkan/VulkanWindow.h"

namespace Ludvig
{
    namespace Core
    {
        Application::Application() {
            /*
             * Maybe these values from the config file should be passed as params of the Application class
             * -Jesper 8/20/2020
             */
            std::string API = Data::UserConfig::get_string("API");
            int windowWidth = Data::UserConfig::get_int("WIDTH");
            int windowHeight = Data::UserConfig::get_int("HEIGHT");

            Debug::DebugLog::log_message("Initializing Ludvig " + this->version + " | Graphics API: " + API);

            scene = std::make_unique<Core::Scene>();

            if (API == "OpenGL") {
                window = std::make_unique<Rendering::OpenGL::OpenGLWindow>("Ludvig | OpenGL", windowWidth,windowHeight);
                renderManager = std::make_unique<Rendering::OpenGL::OpenGLRenderManager>(window.get());
            } else if (API == "Vulkan") {
                window = std::make_unique<Rendering::Vulkan::VulkanWindow>("Ludvig | Vulkan", windowWidth,windowHeight);
                renderManager = std::make_unique<Rendering::Vulkan::VulkanRenderManager>();
            } else if (API == "Direct3D12") {
                Debug::DebugLog::log_warning("Direct3D 12 is not implemented yet.");
            } else if (API == "Direct3D11") {
                window = std::make_unique<Rendering::D3D::Win32Window>("Ludvig | DirectX 11", windowWidth, windowHeight);
                renderManager = std::make_unique<Rendering::D3DX11::D3DX11RenderManager>();
            } else {
                Debug::DebugLog::log_error("Given API '" + API + "' is not available.", true);
            }

            guiManager = std::make_unique<GUI::GUIManager>(scene.get());

            renderManager->set_active_camera(scene->camera.get());
            renderManager->create_mesh_renderer(scene->mesh.get());
        }

        void Application::start() {
            Debug::DebugLog::log_message("Starting Ludvig runtime");

            if (!isRunning)
                runtime();
            else
                Debug::DebugLog::log_error("Attempting to start runtime whilst runtime is already active!", true);
        }

        void Application::runtime() {
            this->isRunning = true;
            while (!window->is_Closing()) {
                window->poll_window_events();

                renderManager->render(scene.get());
            }
            this->isRunning = false;
        }
    }
}

