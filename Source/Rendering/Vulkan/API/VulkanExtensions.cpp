//
// File created by Jesper on 8/19/2020.
//

#include "VulkanExtensions.h"

#include "VulkanValidationLayers.h"

#include "GLFW/glfw3.h"

#include "set"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            std::vector<const char *> get_required_extensions() {
                uint32_t glfwExtensionCount = 0;
                const char** glfwExtensions;
                glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

                std::vector<const char*> extensions(glfwExtensions,glfwExtensions + glfwExtensionCount);

                if (VulkanValidationLayers::is_enabled()) {
                    extensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
                }

                return extensions;
            }

            bool check_physical_device_extension_support(VkPhysicalDevice &physicalDevice) {
                uint32_t extensionCount;
                vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr,&extensionCount,nullptr);

                std::vector<VkExtensionProperties> availableExtensions(extensionCount);
                vkEnumerateDeviceExtensionProperties(physicalDevice,nullptr,&extensionCount,availableExtensions.data());

                std::set<std::string> requiredExtensions(deviceExtensions.begin(), deviceExtensions.end());

                for (const auto& extension : availableExtensions) {
                    requiredExtensions.erase(extension.extensionName);
                }

                return requiredExtensions.empty();
            }
        }
    }
}
