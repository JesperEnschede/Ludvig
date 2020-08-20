//
// File created by Jesper on 8/20/2020.
//

#ifndef LUDVIG_VULKANQUEUEFAMILYINDICES_H
#define LUDVIG_VULKANQUEUEFAMILYINDICES_H

#include "optional"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            struct QueueFamilyIndices
            {
                std::optional<uint32_t> graphicsFamily;
                std::optional<uint32_t> presentFamily;

                /*
                 * Returns true if the graphicsFamily and the presentFamily both have a value.
                 */
                bool is_complete() {
                    return graphicsFamily.has_value() && presentFamily.has_value();
                }
            };
        }
    }
}

#endif //LUDVIG_VULKANQUEUEFAMILYINDICES_H
