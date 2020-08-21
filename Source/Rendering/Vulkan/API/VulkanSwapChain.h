//
// File created by Jesper on 8/21/2020.
//

#ifndef LUDVIG_VULKANSWAPCHAIN_H
#define LUDVIG_VULKANSWAPCHAIN_H

#include "vulkan/vulkan.h"

#include "vector"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            /*
             * A container of swapchain related objects.
             */
            struct VulkanSwapChain
            {
                VkSwapchainKHR swapChain;
                VkRenderPass renderPass;
                std::vector<VkImage> images;
                std::vector<VkImageView> imageViews;
                std::vector<VkFramebuffer> framebuffers;
                VkFormat format;
                VkExtent2D extent;
            };
        }
    }
}

#endif //LUDVIG_VULKANSWAPCHAIN_H
