//
// File created by Jesper on 8/19/2020.
//

#include "VulkanValidationLayers.h"

#include "vulkan/vulkan.h"

#include "vector"
#include "cstring"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            std::vector<const char*> VulkanValidationLayers::validationLayers;

            /*
             * Validation layers are enabled by default and i see
             * no reason to disable them in a rendering engine like this
             * Might be changed in the future - Jesper 8/19/2020
             */
            bool VulkanValidationLayers::validationLayersEnabled = true;

            bool VulkanValidationLayers::is_enabled() {
                return validationLayersEnabled;
            }

            bool VulkanValidationLayers::is_supported() {

                uint32_t layerCount;
                vkEnumerateInstanceLayerProperties(&layerCount, nullptr);

                std::vector<VkLayerProperties> availableLayers(layerCount);
                vkEnumerateInstanceLayerProperties(&layerCount, availableLayers.data());

                for (const char* layerName : validationLayers) {
                    bool layerFound = false;

                    for (const auto& layerProperties : availableLayers) {
                        if (std::strcmp(layerName, layerProperties.layerName) == 0) {
                            layerFound = true;
                            break;
                        }
                    }

                    if (!layerFound) {
                        return false;
                    }
                }

                return true;
            }
        }
    }
}