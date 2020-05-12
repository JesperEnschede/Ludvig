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

            public:
                std::unique_ptr<Transform> transform;

                float nearClipping = 0.5f;
                float farClipping = 100.0f;
            };
        }
    }
}


#endif //LUDVIG_CAMERA_H
