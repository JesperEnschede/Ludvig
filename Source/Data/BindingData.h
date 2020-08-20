//
// Created by Jesper on 6/11/2020.
//

#ifndef LUDVIG_BINDINGDATA_H
#define LUDVIG_BINDINGDATA_H

#include "memory"
#include "Rendering/Window.h"

namespace Ludvig
{
    namespace Data
    {
        class BindingData
        {
        public:
            static Rendering::Window* window;
            static int windowWidth;
            static int windowHeight;
        };
    }
}


#endif //LUDVIG_BINDINGDATA_H
