//
// File created by Jesper on 8/21/2020.
//

#ifndef LUDVIG_D3DX11RENDERCONTEXT_H
#define LUDVIG_D3DX11RENDERCONTEXT_H

#include "Rendering/RenderContext.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace D3DX11
        {
            class D3DX11RenderContext : public RenderContext
            {
            public:
                void finish_frame() override;

                void prepare_frame() override;
            };
        }
    }
}

#endif //LUDVIG_D3DX11RENDERCONTEXT_H
