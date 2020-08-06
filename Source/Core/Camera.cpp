//
// Created by Jesper on 5/12/2020.
//

#include "Camera.h"

namespace Ludvig
{
    namespace Core
    {
        glm::mat4 Camera::get_view_matrix()
        {
            // TODO(Jesper) Make the camera like a first person shooter camera.

            glm::vec3 direction
                    (
                            cos(this->transform->rotation.x) * sin(this->transform->rotation.y),
                            sin(this->transform->rotation.x),
                            cos(this->transform->rotation.x) * cos(this->transform->rotation.y)
                    );

            return glm::lookAt
                    (
                            this->transform->position,
                            this->transform->position + direction,
                            glm::vec3(0,1,0)
                    );
        }

        glm::mat4 Camera::get_projection_matrix()
        {
            // FIXME(Jesper) fix aspect ratio.
            return glm::perspective(glm::radians(this->fieldOfView),16.0f / 9.0f, this->nearClipping,this->farClipping);
        }
    }
}

