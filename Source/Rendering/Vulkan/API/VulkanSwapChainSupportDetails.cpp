//
// File created by Jesper on 8/20/2020.
//

#include "VulkanSwapChainSupportDetails.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            SwapChainSupportDetails query_swap_chain_support(VkPhysicalDevice &physicalDevice, VkSurfaceKHR &surface) {
                SwapChainSupportDetails details;

                vkGetPhysicalDeviceSurfaceCapabilitiesKHR(physicalDevice,surface,&details.capabilities);

                uint32_t formatCount;
                vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice,surface,&formatCount,nullptr);

                if (formatCount != 0) {
                    details.formats.resize(formatCount);
                    vkGetPhysicalDeviceSurfaceFormatsKHR(physicalDevice, surface, &formatCount, details.formats.data());
                }

                uint32_t presentModeCount;
                vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, &presentModeCount, nullptr);

                if (presentModeCount != 0) {
                    details.presentModes.resize(presentModeCount);
                    vkGetPhysicalDeviceSurfacePresentModesKHR(physicalDevice, surface, &presentModeCount, details.presentModes.data());
                }

                return details;
            }
        }
    }
}