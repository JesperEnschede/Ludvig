//
// Created by Jesper on 5/12/2020.
//

#ifndef LUDVIG_CAMERA_H
#define LUDVIG_CAMERA_H

#include "Core/Object.h"
#include "Core/Transform.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

#include "memory"

namespace Ludvig
{
    namespace Core
    {
        /*
         * The camera is a type of Object that is the point of where to user looks from.
         */
        class Camera : public Object
        {
        public:
            /*
             * Initializes default camera values
             */
            Camera();

            /*
             * Returns the view matrix.
             */
            glm::mat4 get_view_matrix();

            /*
             * Returns the projection matrix.
             */
            glm::mat4 get_projection_matrix();

            float nearClipping = 0.1f;
            float farClipping = 1000.0f;
            float fieldOfView = 60.0f;
        };
    }
}


#endif //LUDVIG_CAMERA_H
