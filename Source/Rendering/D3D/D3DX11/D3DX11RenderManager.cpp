//
// File created by Jesper on 8/21/2020.
//

#include "D3DX11RenderManager.h"

#include "D3DX11ForwardRenderer.h"
#include "D3DX11RenderContext.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace D3DX11
        {
            D3DX11RenderManager::D3DX11RenderManager() {
                renderContext = std::make_unique<D3DX11RenderContext>();
            }

            void D3DX11RenderManager::render(Core::Scene *scene) {

            }

            void D3DX11RenderManager::create_mesh_renderer(Core::Mesh *mesh) {

            }
        }
    }
}