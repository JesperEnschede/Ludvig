//
// File created by Jesper on 8/20/2020.
//

#include "VulkanQueueFamilyIndices.h"

#include "vector"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            QueueFamilyIndices find_queue_families(VkPhysicalDevice &physicalDevice, VkSurfaceKHR &surface) {
                QueueFamilyIndices queueFamilyIndices;

                uint32_t familyCount = 0;
                vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice, &familyCount, nullptr);

                std::vector<VkQueueFamilyProperties> queueFamilies(familyCount);
                vkGetPhysicalDeviceQueueFamilyProperties(physicalDevice,&familyCount,queueFamilies.data());

                int i = 0;
                for (const auto& queueFamily : queueFamilies) {
                    if (queueFamily.queueFlags & VK_QUEUE_GRAPHICS_BIT) {
                        queueFamilyIndices.graphicsFamily = i;
                    }

                    VkBool32 presentSupport = false;
                    vkGetPhysicalDeviceSurfaceSupportKHR(physicalDevice,i,surface, &presentSupport);

                    if (presentSupport) {
                        queueFamilyIndices.presentFamily = i;
                    }

                    if (queueFamilyIndices.is_complete()) {
                        break;
                    }

                    i++;
                }
                return queueFamilyIndices;
            }
        }
    }
}