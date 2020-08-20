//
// File created by Jesper on 8/10/2020.
//

#ifndef LUDVIG_VULKANRENDERCONTEXT_H
#define LUDVIG_VULKANRENDERCONTEXT_H

#include "Rendering/RenderContext.h"

#include "Debug/DebugLog.h"

#include "vulkan/vulkan.hpp"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            class VulkanRenderContext : public RenderContext
            {
            public:
                /*
                 * Initializes the vulkan render context
                 */
                VulkanRenderContext();

                /*
                 * Vulkan cleanup
                 */
                ~VulkanRenderContext();

                void prepare_frame() override;

                void finish_frame() override;

            private:
                /*
                 * Creates a vulkan instance
                 */
                void create_vulkan_instance();

                /*
                 * Creates a vulkan debug messenger,
                 * Returns when validation layers are not enabled.
                 */
                void create_debug_messenger();

                /*
                 * Creates a vulkan glfw window surface
                 */
                void create_surface();

                VkInstance instance;
                VkDebugUtilsMessengerEXT debugMessenger;
                VkSurfaceKHR surface;
            };
        }
    }
}

#endif //LUDVIG_VULKANRENDERCONTEXT_H
