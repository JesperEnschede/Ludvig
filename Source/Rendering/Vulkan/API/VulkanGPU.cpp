//
// File created by Jesper on 8/20/2020.
//

#include "VulkanGPU.h"

#include "VulkanQueueFamilyIndices.h"
#include "VulkanSwapChainSupportDetails.h"
#include "VulkanExtensions.h"

#include "Debug/DebugLog.h"

#include "set"
#include "vector"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            bool is_physical_device_suitable(VkPhysicalDevice &physicalDevice, VkSurfaceKHR &surface) {
                QueueFamilyIndices indices = find_queue_families(physicalDevice, surface);

                bool extensionsSupported = check_device_extension_support(physicalDevice);

                bool swapChainAdequate = false;
                if (extensionsSupported) {
                    SwapChainSupportDetails swapChainSupport = query_swap_chain_support(physicalDevice, surface);
                    swapChainAdequate = !swapChainSupport.formats.empty() && !swapChainSupport.presentModes.empty();
                }

                return indices.is_complete() && extensionsSupported && swapChainAdequate;
            }

            bool check_device_extension_support(VkPhysicalDevice &physicalDevice) {
                uint32_t extensionCount;
                vkEnumerateDeviceExtensionProperties(physicalDevice, nullptr, &extensionCount, nullptr);

                std::vector<VkExtensionProperties> availableExtensions(extensionCount);
                vkEnumerateDeviceExtensionProperties(physicalDevice,nullptr,&extensionCount,availableExtensions.data());

                std::set<std::string> requiredExtensions(deviceExtensions.begin(), deviceExtensions.end());

                for (const auto& extension : availableExtensions) {
                    requiredExtensions.erase(extension.extensionName);
                }

                return requiredExtensions.empty();
            }

            int rate_physical_device(VkPhysicalDevice &physicalDevice) {

                int deviceRating = 0;

                VkPhysicalDeviceProperties deviceProperties;
                vkGetPhysicalDeviceProperties(physicalDevice, &deviceProperties);

                VkPhysicalDeviceFeatures deviceFeatures;
                vkGetPhysicalDeviceFeatures(physicalDevice,&deviceFeatures);

                if (deviceProperties.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU)
                    deviceRating += 10;

                deviceRating += deviceProperties.limits.maxImageDimension2D;

                return deviceRating;
            }

            VkPhysicalDevice pick_physical_device(VkInstance &instance, VkSurfaceKHR &surface) {
                uint32_t deviceCount = 0;
                vkEnumeratePhysicalDevices(instance, &deviceCount,nullptr);

                if (deviceCount == 0) {
                    Debug::DebugLog::log_error("Unable to find a GPU with Vulkan support", true);
                }

                std::vector<VkPhysicalDevice> foundPhysicalDevices(deviceCount);
                vkEnumeratePhysicalDevices(instance, &deviceCount,foundPhysicalDevices.data());

                for (auto& device : foundPhysicalDevices) {
                    if (is_physical_device_suitable(device,surface)) {
                        Debug::DebugLog::log_message("Found a suitable GPU with Vulkan support");
                        return device;
                    }
                }

                Debug::DebugLog::log_error("Failed to find a suitable GPU", true);
                return nullptr;
            }
        }
    }
}