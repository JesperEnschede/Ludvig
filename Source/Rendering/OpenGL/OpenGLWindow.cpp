//
// File created by Jesper on 8/6/2020.
//

#include "OpenGLWindow.h"

#include "Debug/DebugLog.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            OpenGLWindow::OpenGLWindow(std::string title, int w,int h) {
                width = w;
                height = h;

                initialize();
            }

            void OpenGLWindow::initialize() {
                if (glfwInit() != GLFW_TRUE) {
                    Debug::DebugLog::log_error("Failed to initialize GLFW", true);
                } else {
                    Debug::DebugLog::log_message("Initialized GLFW");
                }

                window = glfwCreateWindow(width,height,"@temp@", nullptr, nullptr);

                if (window == nullptr) {
                    Debug::DebugLog::log_error("Failed to create GLFW window", true);
                } else {
                    Debug::DebugLog::log_message("Created GLFW window");
                }
            }
        }
    }
}
