//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_WINDOW_H
#define LUDVIG_WINDOW_H

namespace Ludvig
{
    namespace Rendering
    {
        class Window
        {
        public:
            Window(int width, int height, bool fullscreen);

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

        private:
            /*
             * Gets called whenever the window is resized.
             */
            void window_resize_callback(int w, int h);

        private:
            int width = 800;
            int height = 600;
        };
    }
}


#endif //LUDVIG_WINDOW_H
