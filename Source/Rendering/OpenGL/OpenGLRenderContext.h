//
// File created by Jesper on 8/6/2020.
//

#ifndef LUDVIG_OPENGLRENDERCONTEXT_H
#define LUDVIG_OPENGLRENDERCONTEXT_H

#include "Rendering/RenderContext.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            class OpenGLRenderContext : public RenderContext
            {
            public:
                void prepare_frame() override;

                void finish_frame() override;
            };
        }
    }
}

#endif //LUDVIG_OPENGLRENDERCONTEXT_H
