//
// Created by Jesper on 5/12/2020.
//

#include "Camera.h"

namespace Ludvig
{
    namespace Core
    {
        glm::mat4 Camera::get_view_projection_matrix()
        {
            return this->projectionMatrix * this->viewMatrix;
        }

        void Camera::calculate_view_projection_matrix()
        {
            glm::vec3 direction
                    (
                            cos(this->transform->rotation.x) * sin(this->transform->rotation.y),
                            sin(this->transform->rotation.x),
                            cos(this->transform->rotation.x) * cos(this->transform->rotation.y)
                    );

            this->viewMatrix = glm::lookAt
                    (
                            this->transform->position,
                            this->transform->position + direction,
                            glm::vec3(0,1,0)
                    );

            // FIXME: apply proper aspect ratio in projection matrix.
            this->projectionMatrix = glm::perspective(glm::radians(this->fieldOfView),16.0f / 9.0f, this->nearClipping,this->farClipping);
        }

        glm::mat4 Camera::get_view_matrix()
        {
            return this->viewMatrix;
        }

        glm::mat4 Camera::get_projection_matrix()
        {
            return this->projectionMatrix;
        }
    }
}

