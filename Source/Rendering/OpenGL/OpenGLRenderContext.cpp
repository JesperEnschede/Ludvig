//
// File created by Jesper on 8/6/2020.
//

#include "OpenGLRenderContext.h"

#include "Debug/DebugLog.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            OpenGLRenderContext::OpenGLRenderContext(GLFWwindow *window) {
                this->window = window;

                glfwMakeContextCurrent(window);

                Debug::DebugLog::log_message("Created OpenGL render context");
            }

            void OpenGLRenderContext::prepare_frame() {
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            }

            void OpenGLRenderContext::finish_frame() {
                glfwSwapBuffers(window);
            }
        }
    }
}
