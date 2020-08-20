//
// File created by Jesper on 8/20/2020.
//

#include "VulkanDebugMessenger.h"

#include "Debug/DebugLog.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            VKAPI_ATTR VkBool32 VKAPI_CALL debug_callback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                                               VkDebugUtilsMessageTypeFlagsEXT messageType,
                                               const VkDebugUtilsMessengerCallbackDataEXT *pCallbackData,
                                               void *pUserData) {
                Debug::DebugLog::log_error("Vulkan validation layer:" + std::string(pCallbackData->pMessage), false);

                return VK_FALSE;
            }
        }
    }
}