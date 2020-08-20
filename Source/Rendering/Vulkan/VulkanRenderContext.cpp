//
// File created by Jesper on 8/10/2020.
//

#include "VulkanRenderContext.h"

#include "VulkanWindow.h"

#include "API/VulkanValidationLayers.h"
#include "API/VulkanExtensions.h"
#include "API/VulkanDebugMessenger.h"

#include "Data/BindingData.h"

#include "GLFW/glfw3.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            VulkanRenderContext::VulkanRenderContext() {
                create_vulkan_instance();
                create_debug_messenger();
                create_surface();
            }

            VulkanRenderContext::~VulkanRenderContext() {

                if (VulkanValidationLayers::is_enabled()) {
                    destroy_debug_utils_messengerEXT(instance,debugMessenger,nullptr);
                }

                vkDestroySurfaceKHR(instance,surface,nullptr);
                vkDestroyInstance(instance,nullptr);
            }

            void VulkanRenderContext::prepare_frame() {

            }

            void VulkanRenderContext::finish_frame() {

            }

            void VulkanRenderContext::create_vulkan_instance() {

                if (VulkanValidationLayers::is_enabled() && !VulkanValidationLayers::is_supported()) {
                    Debug::DebugLog::log_error("Validation layers enabled but not available", false);
                }

                VkApplicationInfo applicationInfo{};
                applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;

                // TODO(Jesper) get app/engine name & version (m,m,p) from global data
                applicationInfo.pApplicationName = "Ludvig";
                applicationInfo.applicationVersion = VK_MAKE_VERSION(0,2,1);

                applicationInfo.pEngineName = "Ludvig rendering engine";
                applicationInfo.engineVersion = VK_MAKE_VERSION(0,2,1);

                applicationInfo.apiVersion = VK_API_VERSION_1_0;

                VkInstanceCreateInfo instanceCreateInfo{};
                instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
                instanceCreateInfo.pApplicationInfo = &applicationInfo;

                // TODO(Jesper) get available glfw extensions

                uint32_t glfwExtensionCount = 0;
                const char** glfwExtensions;

                glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

                auto extensions = get_required_extensions();
                instanceCreateInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
                instanceCreateInfo.ppEnabledExtensionNames = extensions.data();

                VkDebugUtilsMessengerCreateInfoEXT debugUtilsMessengerCreateInfoExt;
                if (Vulkan::VulkanValidationLayers::is_enabled()) { // FIXME(Jesper) enable debug vk callbacksEXT
                    instanceCreateInfo.enabledLayerCount = static_cast<uint32_t>(VulkanValidationLayers::validationLayers.size());
                    instanceCreateInfo.ppEnabledLayerNames = VulkanValidationLayers::validationLayers.data();

                    debugUtilsMessengerCreateInfoExt = {};
                    debugUtilsMessengerCreateInfoExt.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
                    debugUtilsMessengerCreateInfoExt.messageSeverity =
                            VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT |
                            VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT |
                            VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;

                    debugUtilsMessengerCreateInfoExt.messageType =
                            VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT |
                            VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT |
                            VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;

                    debugUtilsMessengerCreateInfoExt.pfnUserCallback = debug_callback;

                    instanceCreateInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*) &debugUtilsMessengerCreateInfoExt;
                } else {
                    instanceCreateInfo.enabledLayerCount = 0;
                    instanceCreateInfo.pNext = nullptr;
                }

                if (vkCreateInstance(&instanceCreateInfo, nullptr,&instance) != VK_SUCCESS) {
                    Debug::DebugLog::log_error("Failed to create vulkan instance", true);
                } else {
                    Debug::DebugLog::log_message("Created vulkan instance");
                }
            }

            void VulkanRenderContext::create_debug_messenger() {
                if (!VulkanValidationLayers::is_enabled())
                    return;

                VkDebugUtilsMessengerCreateInfoEXT debugUtilsMessengerCreateInfoExt{};
                debugUtilsMessengerCreateInfoExt = {};
                debugUtilsMessengerCreateInfoExt.sType = VK_STRUCTURE_TYPE_DEBUG_UTILS_MESSENGER_CREATE_INFO_EXT;
                debugUtilsMessengerCreateInfoExt.messageSeverity = VK_DEBUG_UTILS_MESSAGE_SEVERITY_VERBOSE_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_WARNING_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_SEVERITY_ERROR_BIT_EXT;
                debugUtilsMessengerCreateInfoExt.messageType = VK_DEBUG_UTILS_MESSAGE_TYPE_GENERAL_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_VALIDATION_BIT_EXT | VK_DEBUG_UTILS_MESSAGE_TYPE_PERFORMANCE_BIT_EXT;
                debugUtilsMessengerCreateInfoExt.pfnUserCallback = debug_callback;

                if (create_debug_utils_messengerEXT(instance,&debugUtilsMessengerCreateInfoExt, nullptr, &debugMessenger) != VK_SUCCESS) {
                    std::runtime_error("failed to setup debug messenger!");
                } else {
                    Debug::DebugLog::log_message("Created vulkan debug messenger");
                }
            }

            void VulkanRenderContext::create_surface() {
                if (glfwCreateWindowSurface(instance,dynamic_cast<VulkanWindow*>(Data::BindingData::window)->get_handle(), nullptr, &surface)) {
                    Debug::DebugLog::log_error("Unable to create vulkan surface", false);
                } else {
                    Debug::DebugLog::log_message("Created vulkan surface");
                }
            }
        }
    }
}
