//
// File created by Jesper on 8/10/2020.
//

#ifndef LUDVIG_VULKANRENDERMANAGER_H
#define LUDVIG_VULKANRENDERMANAGER_H

#include "Rendering/RenderManager.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            class VulkanRenderManager : public RenderManager
            {
            public:
                VulkanRenderManager();

                void render(Core::Scene *scene) override;

                void create_mesh_renderer(Core::Mesh *mesh) override;
            };
        }
    }
}

#endif //LUDVIG_VULKANRENDERMANAGER_H
