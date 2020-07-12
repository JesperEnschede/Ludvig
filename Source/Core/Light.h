//
// Created by Jesper on 5/18/2020.
//

#ifndef LUDVIG_LIGHT_H
#define LUDVIG_LIGHT_H

#include "Core/Transform.h"
#include "Core/Object.h"

#include "glm.hpp"

#include "memory"

namespace Ludvig
{
    namespace Core
    {
        enum LightType
        {
            Directional = 0,
            Point = 1,
            SpotLight = 2
        };

        /*
         * A light is a type of Object that is used to calculate light on a Mesh from.
         */
        class Light : public Object
        {
        public:
            Light() = default;

            float intensity = 1.0f;
            LightType type = LightType::Directional;
            glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
        };
    }
}

#endif //LUDVIG_LIGHT_H
