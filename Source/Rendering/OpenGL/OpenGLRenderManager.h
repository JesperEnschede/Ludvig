//
// File created by Jesper on 8/6/2020.
//

#ifndef LUDVIG_OPENGLRENDERMANAGER_H
#define LUDVIG_OPENGLRENDERMANAGER_H

#include "Rendering/RenderManager.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            class OpenGLRenderManager : public RenderManager
            {
            public:
                void render() override;
            };
        }
    }
}

#endif //LUDVIG_OPENGLRENDERMANAGER_H
