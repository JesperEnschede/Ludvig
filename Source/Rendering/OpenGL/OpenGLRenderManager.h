//
// File created by Jesper on 8/6/2020.
//

#ifndef LUDVIG_OPENGLRENDERMANAGER_H
#define LUDVIG_OPENGLRENDERMANAGER_H

#include "Rendering/RenderManager.h"
#include "Rendering/Window.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            class OpenGLRenderManager : public RenderManager
            {
            public:
                OpenGLRenderManager(Window* window);

                void render() override;

            private:

            };
        }
    }
}

#endif //LUDVIG_OPENGLRENDERMANAGER_H
