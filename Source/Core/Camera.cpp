//
// Created by Jesper on 5/12/2020.
//

#include "Camera.h"

#include "Data/BindingData.h"

namespace Ludvig
{
    namespace Core
    {
        Camera::Camera() {
            transform->position = glm::vec3(0,0,-10);
        }

        glm::mat4 Camera::get_view_matrix() {
            // TODO(Jesper) Make the camera like a first person shooter camera.

            glm::mat4 viewMatrix = glm::mat4(1.0f);

            glm::vec3 direction
                    (
                            cos(this->transform->rotation.x) * sin(this->transform->rotation.y),
                            sin(this->transform->rotation.x),
                            cos(this->transform->rotation.x) * cos(this->transform->rotation.y)
                    );

            viewMatrix = glm::lookAt
                    (
                            this->transform->position,
                            this->transform->position + direction,
                            glm::vec3(0,1,0)
                    );

            return viewMatrix;
        }

        glm::mat4 Camera::get_projection_matrix() const {
            return glm::perspective(
                    glm::radians(this->fieldOfView),
                    (float)Data::BindingData::windowWidth / (float)Data::BindingData::windowHeight,
                    this->nearClipping,
                    this->farClipping);
        }
    }
}

