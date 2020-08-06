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
             * Initializes default window values
             * and calls the abstract initialize function,
             * which will create a window.
             */
            Window(std::string name,int w, int h);

            /*
             * Returns the width of the window.
             */
            int get_width() const;

            /*
             * Returns the height of the window.
             */
            int get_height() const;

        private:
            virtual void initialize() = 0;

            int width;
            int height;
        };
    }
}

#endif //LUDVIG_WINDOW_H
