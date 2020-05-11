//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_WINDOW_H
#define LUDVIG_WINDOW_H

#include "GLFW/glfw3.h"

namespace Ludvig
{
    namespace Rendering
    {
        /*
         * Window class represents an window viewport.
         */
        class Window
        {
        public:
            Window(int width, int height, bool fullscreen);

            /*
             * Poll window events.
             */
            void poll_events();

            /*
             * Swap window buffers.
             */
            void swap_buffers();

            /*
             * Returns the current window width.
             */
            int get_width() const;

            /*
             * Returns the current window height.
             */
            int get_height() const;

            /*
             * Set the amount of window samples.
             */
            void set_samples(int amount);

            /*
             * Set the amount of vSync buffers.
             */
            void set_vsync(int buffers);

            /*
             * Returns a pointer to the context window.
             */
            GLFWwindow* get_context() const;

            /*
             * Returns true if the window is closing.
             */
            bool is_closing() const;

        private:
            /*
             * Gets called whenever the window is resized.
             */
            void window_resize_callback(int w, int h);

        private:
            GLFWwindow* window;

            int width = 800;
            int height = 600;
        };
    }
}


#endif //LUDVIG_WINDOW_H
