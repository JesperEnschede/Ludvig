//
// File created by Jesper on 8/19/2020.
//

#ifndef LUDVIG_VULKANEXTENSIONS_H
#define LUDVIG_VULKANEXTENSIONS_H

#include "vulkan/vulkan.h"

#include "vector"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            /*
             * Returns a vector of required vulkan extension names.
             */
            std::vector<const char*> get_required_extensions();

            /*
             * Checks if a physical device extenion support, returns true if so.
             */
            bool check_physical_device_extension_support(VkPhysicalDevice& physicalDevice);

            std::vector<const char*> deviceExtensions = {
                    VK_KHR_SWAPCHAIN_EXTENSION_NAME
            };
        }
    }
}

#endif //LUDVIG_VULKANEXTENSIONS_H
