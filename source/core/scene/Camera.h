//
// Created by Jesper on 5/12/2020.
//

#ifndef LUDVIG_CAMERA_H
#define LUDVIG_CAMERA_H

#include "../Transform.h"

#include "../Object.h"

#include "glm.hpp"
#include "gtc/matrix_transform.hpp"

#include "memory"

namespace Ludvig
{
    namespace Core
    {
        namespace Scene
        {
            /*
             * The camera is a type of Object that is the point of where to user looks from.
             */
            class Camera : public Object
            {
            public:
                Camera() = default;

                /*
                 * Return the view * projection matrix.
                 */
                glm::mat4 get_view_projection_matrix();

                /*
                 * Returns the view matrix.
                 */
                glm::mat4 get_view_matrix();

                /*
                 * Returns the projection matrix.
                 */
                glm::mat4 get_projection_matrix();

                /*
                 * Calculate the view projection matrix.
                 */
                void calculate_view_projection_matrix();

            public:
                float nearClipping = 0.1f;
                float farClipping = 1000.0f;
                float fieldOfView = 60.0f;

            private:
                glm::mat4 viewMatrix = glm::mat4(1.0f);
                glm::mat4 projectionMatrix = glm::mat4(1.0f);
            };
        }
    }
}


#endif //LUDVIG_CAMERA_H
