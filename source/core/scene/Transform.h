//
// Created by Jesper on 5/12/2020.
//

#ifndef LUDVIG_TRANSFORM_H
#define LUDVIG_TRANSFORM_H

#include "glm.hpp"

namespace Ludvig
{
    namespace Core
    {
        namespace Scene
        {
            class Transform
            {
            public:
                Transform();

            public:
                glm::mat4 get_trs();

                void translate(float x, float y, float z);
                void rotate(float yaw, float pitch, float roll);
                void set_scale(float x, float y, float z);

            private:
                glm::vec3 position = glm::vec3(0.0f,0.0f,0.0f);
                glm::vec3 rotation = glm::vec3(0.0f,0.0f,0.0f); // todo: quaternions.
                glm::vec3 scale = glm::vec3(0.0f,0.0f,0.0f);
            };
        }
    }
}



#endif //LUDVIG_TRANSFORM_H
