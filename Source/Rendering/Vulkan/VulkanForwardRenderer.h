//
// File created by Jesper on 8/10/2020.
//

#ifndef LUDVIG_VULKANFORWARDRENDERER_H
#define LUDVIG_VULKANFORWARDRENDERER_H

#include "Rendering/RenderTechnique.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            class VulkanForwardRenderer : public RenderTechnique
            {
            public:
                void render_scene(Core::Scene *scene) override;
            };
        }
    }
}

#endif //LUDVIG_VULKANFORWARDRENDERER_H
