//
// Created by Jesper on 5/12/2020.
//

#ifndef LUDVIG_CAMERA_H
#define LUDVIG_CAMERA_H

#include "Transform.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

#include "memory"

namespace Ludvig
{
    namespace Core
    {
        namespace Scene
        {
            class Camera
            {
            public:
                Camera();

                glm::mat4 get_view_projection_matrix();

                glm::mat4 get_view_matrix();

                glm::mat4 get_projection_matrix();

                void calculate_view_projection_matrix();

            public:
                std::unique_ptr<Transform> transform;

                float nearClipping = 0.1f;
                float farClipping = 100.0f;
                float fieldOfView = 60.0f;

            private:
                glm::mat4 viewMatrix = glm::mat4(1.0f);
                glm::mat4 projectionMatrix = glm::mat4(1.0f);
            };
        }
    }
}


#endif //LUDVIG_CAMERA_H
