//
// File created by Jesper on 8/10/2020.
//

#include "VulkanWindow.h"

#include "Data/BindingData.h"
#include "Debug/DebugLog.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            VulkanWindow::VulkanWindow(const std::string& title, int w, int h) {
                this->width = w;
                this->height = h;
                this->title = title;

                initialize();
            }

            void VulkanWindow::initialize() {
                if (glfwInit() != GLFW_TRUE) {
                    Debug::DebugLog::log_error("Failed to initialize GLFW", true);
                } else {
                    Debug::DebugLog::log_message("Initialized GLFW");
                }

                glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

                windowHandle = glfwCreateWindow(width, height, title.c_str(), nullptr,nullptr);

                if (windowHandle == nullptr) {
                    Debug::DebugLog::log_error("Failed to create GLFW window", true);
                } else {
                    Debug::DebugLog::log_message("Created GLFW window");
                }

                Data::BindingData::windowWidth = width;
                Data::BindingData::windowHeight = height;
                Data::BindingData::window = this;
            }

            bool VulkanWindow::is_Closing() {
                return glfwWindowShouldClose(windowHandle);
            }

            void VulkanWindow::poll_window_events() {
                glfwPollEvents();
            }

            GLFWwindow *VulkanWindow::get_handle() const {
                return windowHandle;
            }

            void VulkanWindow::on_resize_window_callback(int newWidth, int newHeight) {

            }
        }
    }
}