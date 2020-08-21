//
// File created by Jesper on 8/21/2020.
//

#ifndef LUDVIG_D3DX11FORWARDRENDERER_H
#define LUDVIG_D3DX11FORWARDRENDERER_H

#include "Rendering/RenderTechnique.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace D3DX11
        {
            class D3DX11ForwardRenderer : public RenderTechnique
            {
            public:
                void render_scene(Core::Scene *scene) override;
            };
        }
    }
}

#endif //LUDVIG_D3DX11FORWARDRENDERER_H
