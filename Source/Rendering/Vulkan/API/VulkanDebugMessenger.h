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
                    void* pUserData);;
        }
    }
}

#endif //LUDVIG_VULKANDEBUGMESSENGER_H
