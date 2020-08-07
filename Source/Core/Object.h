//
// Created by Jesper on 5/19/2020.
//

#ifndef LUDVIG_OBJECT_H
#define LUDVIG_OBJECT_H

#include "Transform.h"

#include "memory"

namespace Ludvig
{
    namespace Core
    {
        /*
         * An object is the base class for everything inside of a scene.
         */
        class Object
        {
        public:
            const char* name = "Unidentified Object";

            std::unique_ptr<Transform> transform = std::make_unique<Transform>();
        };
    }
}



#endif //LUDVIG_OBJECT_H
