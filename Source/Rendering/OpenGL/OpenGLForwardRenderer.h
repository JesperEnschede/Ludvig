//
// File created by Jesper on 8/6/2020.
//

#ifndef LUDVIG_OPENGLFORWARDRENDERER_H
#define LUDVIG_OPENGLFORWARDRENDERER_H

#include "Rendering/RenderTechnique.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            class OpenGLForwardRenderer : public RenderTechnique
            {
            public:
                void render_scene() override;
            };
        }
    }
}

#endif //LUDVIG_OPENGLFORWARDRENDERER_H
