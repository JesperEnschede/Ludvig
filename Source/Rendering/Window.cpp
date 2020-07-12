//
// Created by Jesper on 5/11/2020.
//

#include "Window.h"
#include "Debug/DebugLog.h"

namespace Ludvig
{
    namespace Rendering
    {
        Window::Window(int width, int height, bool fullscreen)
        {
            if (glfwInit() != GLFW_TRUE)
            {
                Debug::DebugLog::log_error("Failed to initialize window");

                return;
            }
            else
            {
                Debug::DebugLog::log_message("Successfully initialized window");
            }

            this->window = glfwCreateWindow(width,height,"Ludvig", fullscreen ? glfwGetPrimaryMonitor() : nullptr ,nullptr);

            if (window == nullptr)
            {
                Debug::DebugLog::log_error("Failed to create window");

                return;
            }
            else
            {
                Debug::DebugLog::log_message("Successfully created window");
            }

            set_samples(16); // default samples.

            glfwMakeContextCurrent(this->window);

            set_vSync(0); // disabled vSync by default.

            glfwSetInputMode(this->window, GLFW_STICKY_KEYS, GL_TRUE);

            glfwSetWindowUserPointer(window,this);

            glfwSetWindowSizeCallback(window,
                                      [](GLFWwindow* w, int newWidth, int newHeight )
                                      {
                                          reinterpret_cast<Window*>(glfwGetWindowUserPointer(w))->window_resize_callback(newWidth,newHeight);
                                      });
        }

        Window::~Window()
        {
            glfwDestroyWindow(window);
            glfwTerminate();
        }

        void Window::poll_events()
        {
            glfwPollEvents();
        }

        void Window::swap_buffers()
        {
            glfwSwapBuffers(this->window);
        }

        int Window::get_width() const
        {
            return this->width;
        }

        int Window::get_height() const
        {
            return this->height;
        }

        void Window::set_samples(int amount)
        {
            glfwWindowHint(GLFW_SAMPLES,amount);
        }

        void Window::set_vSync(int buffers)
        {
            glfwSwapInterval(buffers);
        }

        void Window::window_resize_callback(int w, int h)
        {
            this->width = w;
            this->height = h;

            glViewport(0,0,w,h);
        }

        GLFWwindow *Window::get_context() const
        {
            return this->window;
        }

        bool Window::is_closing() const
        {
            return glfwWindowShouldClose(window);
        }

    }
}


