//
// File created by Jesper on 8/6/2020.
//

#ifndef LUDVIG_OPENGLRENDERCONTEXT_H
#define LUDVIG_OPENGLRENDERCONTEXT_H

#include "Rendering/RenderContext.h"

#include "GLFW/glfw3.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            class OpenGLRenderContext : public RenderContext
            {
            public:
                OpenGLRenderContext(GLFWwindow* window);

                void prepare_frame() override;

                void finish_frame() override;

            private:
                GLFWwindow* window;
            };
        }
    }
}

#endif //LUDVIG_OPENGLRENDERCONTEXT_H
