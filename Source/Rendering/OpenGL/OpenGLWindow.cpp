//
// File created by Jesper on 8/6/2020.
//

#include "OpenGLWindow.h"

#include "Data/BindingData.h"
#include "Debug/DebugLog.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            OpenGLWindow::OpenGLWindow(std::string title, int w,int h) {
                this->title = title;
                width = w;
                height = h;

                initialize();
            }

            void OpenGLWindow::poll_window_events() {
                glfwPollEvents();
            }

            bool OpenGLWindow::is_Closing() {
                return glfwWindowShouldClose(window);
            }

            GLFWwindow *OpenGLWindow::get_handle() const {
                return window;
            }

            void OpenGLWindow::initialize() {
                if (glfwInit() != GLFW_TRUE) {
                    Debug::DebugLog::log_error("Failed to initialize GLFW", true);
                } else {
                    Debug::DebugLog::log_message("Initialized GLFW");
                }

                window = glfwCreateWindow(width,height,title.c_str(), nullptr, nullptr);

                if (window == nullptr) {
                    Debug::DebugLog::log_error("Failed to create GLFW window", true);
                } else {
                    Debug::DebugLog::log_message("Created GLFW window");
                }

                glfwSetWindowUserPointer(window, this);

                Data::BindingData::windowWidth = width;
                Data::BindingData::windowHeight = height;

                glfwSetWindowSizeCallback(
                        window,
                        [](GLFWwindow* window, int nw, int nh)
                        {
                            reinterpret_cast<OpenGLWindow*>(glfwGetWindowUserPointer(window))->on_resize_window_callback(nw,nh);
                        });
            }

            void OpenGLWindow::on_resize_window_callback(int newWidth, int newHeight) {
                width = newWidth;
                height = newHeight;
                Data::BindingData::windowWidth = newWidth;
                Data::BindingData::windowHeight = newHeight;

                glViewport(0,0,newWidth, newHeight);
            }
        }
    }
}
