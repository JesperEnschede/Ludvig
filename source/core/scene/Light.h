//
// Created by Jesper on 5/18/2020.
//

#ifndef LUDVIG_LIGHT_H
#define LUDVIG_LIGHT_H

#include "Transform.h"

#include "memory"

namespace Ludvig
{
    namespace Core
    {
        namespace Scene
        {
            class Light
            {
            public:
                Light();

                std::unique_ptr<Transform> transform = std::make_unique<Transform>();
            };
        }
    }
}



#endif //LUDVIG_LIGHT_H
