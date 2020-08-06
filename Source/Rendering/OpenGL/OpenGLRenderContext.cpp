//
// File created by Jesper on 8/6/2020.
//

#include "OpenGLRenderContext.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            OpenGLRenderContext::OpenGLRenderContext(GLFWwindow *window) {
                this->window = window;
            }

            void OpenGLRenderContext::prepare_frame() {
                // glClear(GL_COLOR_BUFFER_BIT);
            }

            void OpenGLRenderContext::finish_frame() {
                glfwSwapBuffers(window);
            }
        }
    }
}
