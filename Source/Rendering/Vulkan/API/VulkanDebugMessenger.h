//
// File created by Jesper on 8/20/2020.
//

#ifndef LUDVIG_VULKANDEBUGMESSENGER_H
#define LUDVIG_VULKANDEBUGMESSENGER_H

#include "vulkan/vulkan.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            VKAPI_ATTR VkBool32 VKAPI_CALL debug_callback(
                    VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity,
                    VkDebugUtilsMessageTypeFlagsEXT messageType,
                    const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData,
                    void* pUserData);

            VkResult create_debug_utils_messengerEXT(VkInstance instance, const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
                                                     const VkAllocationCallbacks* pAllocator, VkDebugUtilsMessengerEXT* pDebugMessenger);

            void destroy_debug_utils_messengerEXT(VkInstance instance, VkDebugUtilsMessengerEXT debugMessenger, const VkAllocationCallbacks* pAllocator);
        }
    }
}

#endif //LUDVIG_VULKANDEBUGMESSENGER_H
