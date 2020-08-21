//
// File created by Jesper on 8/21/2020.
//

#ifndef LUDVIG_D3DX11RENDERMANAGER_H
#define LUDVIG_D3DX11RENDERMANAGER_H

#include "Rendering/RenderManager.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace D3DX11
        {
            class D3DX11RenderManager : public RenderManager
            {
            public:
                D3DX11RenderManager();

                void render(Core::Scene *scene) override;

                void create_mesh_renderer(Core::Mesh *mesh) override;

            private:
                void create_gui_frame();

                void render_gui_frame();
            };
        }
    }
}

#endif //LUDVIG_D3DX11RENDERMANAGER_H
