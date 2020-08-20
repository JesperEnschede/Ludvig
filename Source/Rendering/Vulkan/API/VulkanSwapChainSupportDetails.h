//
// File created by Jesper on 8/20/2020.
//

#ifndef LUDVIG_VULKANSWAPCHAINSUPPORTDETAILS_H
#define LUDVIG_VULKANSWAPCHAINSUPPORTDETAILS_H

#include "vulkan/vulkan.h"

#include "vector"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            struct SwapChainSupportDetails
            {
                VkSurfaceCapabilitiesKHR capabilities;
                std::vector<VkSurfaceFormatKHR> formats;
                std::vector<VkPresentModeKHR> presentModes;
            };

            SwapChainSupportDetails query_swap_chain_support(VkPhysicalDevice& physicalDevice, VkSurfaceKHR& surface);
        }
    }
}

#endif //LUDVIG_VULKANSWAPCHAINSUPPORTDETAILS_H
