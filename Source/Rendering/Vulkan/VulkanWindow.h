//
// File created by Jesper on 8/10/2020.
//

#ifndef LUDVIG_VULKANWINDOW_H
#define LUDVIG_VULKANWINDOW_H

#include "Rendering/Window.h"

#include "GLFW/glfw3.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            class VulkanWindow : public Window
            {
            public:
                VulkanWindow(const std::string& title, int w, int h);

                void initialize() override;

                bool is_Closing() override;

                void poll_window_events() override;

                GLFWwindow* get_handle() const;

            private:
                void on_resize_window_callback(int newWidth, int newHeight) override;

                GLFWwindow* windowHandle;
            };
        }
    }
}

#endif //LUDVIG_VULKANWINDOW_H
