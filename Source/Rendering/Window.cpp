//
// Created by Jesper on 5/11/2020.
//

#include "Window.h"

namespace Ludvig
{
    namespace Rendering
    {
        Window::Window(std::string name, int w, int h) {
            this->width = w;
            this->height = h;

            initialize();
        }

        int Window::get_width() const {
            return width;
        }

        int Window::get_height() const {
            return height;
        }
    }
}
