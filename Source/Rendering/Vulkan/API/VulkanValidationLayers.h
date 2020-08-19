//
// File created by Jesper on 8/19/2020.
//

#ifndef LUDVIG_VULKANVALIDATIONLAYERS_H
#define LUDVIG_VULKANVALIDATIONLAYERS_H

#include "vector"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            /*
             * The VulkanValidationLayers class is a class contain global data about the vulkan validation layers.
             */
            class VulkanValidationLayers
            {
                /*
                 * Returns true if the validation layers are enabled
                 */
                static bool is_enabled();

                /*
                 * Returns true if validation layers are supported
                 */
                static bool is_supported();

                static std::vector<const char*> validationLayers;

            private:
                static bool validationLayersEnabled;
            };
        }
    }
}

#endif //LUDVIG_VULKANVALIDATIONLAYERS_H
