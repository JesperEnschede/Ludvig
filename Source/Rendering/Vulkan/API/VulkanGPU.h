//
// File created by Jesper on 8/20/2020.
//

#ifndef LUDVIG_VULKANGPU_H
#define LUDVIG_VULKANGPU_H

#include "vulkan/vulkan.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            bool is_physical_device_suitable(VkPhysicalDevice& physicalDevice, VkSurfaceKHR& surface);

            bool check_device_extension_support(VkPhysicalDevice& physicalDevice);

            int rate_physical_device(VkPhysicalDevice& physicalDevice);

            VkPhysicalDevice pick_physical_device(VkInstance& instance, VkSurfaceKHR& surface);
        }
    }
}

#endif //LUDVIG_VULKANGPU_H
