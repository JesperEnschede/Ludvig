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
        class Object
        {
        public:
            std::unique_ptr<Scene::Transform> transform = std::make_unique<Scene::Transform>();
        };
    }
}



#endif //LUDVIG_OBJECT_H
