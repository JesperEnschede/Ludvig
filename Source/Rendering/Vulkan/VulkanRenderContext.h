//
// File created by Jesper on 8/10/2020.
//

#ifndef LUDVIG_VULKANRENDERCONTEXT_H
#define LUDVIG_VULKANRENDERCONTEXT_H

#include "Rendering/RenderContext.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            class VulkanRenderContext : public RenderContext
            {
            public:
                void prepare_frame() override;

                void finish_frame() override;
            };
        }
    }
}

#endif //LUDVIG_VULKANRENDERCONTEXT_H
