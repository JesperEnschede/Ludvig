//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_WINDOW_H
#define LUDVIG_WINDOW_H

#include "string"

namespace Ludvig
{
    namespace Rendering
    {
        /*
         * The Window class is a abstract class that must be overridden to define
         * API specific window creation, The window can be used to draw graphics to.
         */
        class Window
        {
        public:
            /*
             * Returns the width of the window.
             */
            int get_width() const;

            /*
             * Returns the height of the window.
             */
            int get_height() const;

            /*
             * Polls the window event messages.
             */
            virtual void poll_window_events() = 0;

            /*
             * Returns true if the window is closing.
             */
            virtual bool is_Closing() = 0;

        protected:
            /*
             * Initializes the window.
             */
            virtual void initialize() = 0;

            /*
             * Get called whenever the window is resized.
             */
            virtual void on_resize_window_callback(int newWidth, int newHeight) = 0;

            std::string title;
            int width;
            int height;
        };
    }
}

#endif //LUDVIG_WINDOW_H
