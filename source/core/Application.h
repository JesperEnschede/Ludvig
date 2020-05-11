//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_APPLICATION_H
#define LUDVIG_APPLICATION_H

#include "../rendering/Window.h"

#include "memory"

namespace Ludvig
{
    namespace Core
    {
        class Application final
        {
        public:
            Application();

            void start();

        private:
            void runtime();

        private:
            std::unique_ptr<Rendering::Window> window;
        };
    }
}


#endif //LUDVIG_APPLICATION_H
