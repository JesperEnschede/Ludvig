//
// Created by Jesper on 5/12/2020.
//

#include "Transform.h"

#include "gtx/euler_angles.hpp"

namespace Ludvig
{
    namespace Core
    {
        glm::mat4 Ludvig::Core::Transform::get_trs() {
            glm::mat4 rotationMatrix = glm::eulerAngleYXZ(this->rotation.x, this->rotation.y,this->rotation.z);
            glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), this->position);
            glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), this->scale);

            return translationMatrix * rotationMatrix * scaleMatrix;
        }

        void Ludvig::Core::Transform::translate(float x, float y, float z) {
            this->position.x += x;
            this->position.y += y;
            this->position.z += z;
        }

        void Ludvig::Core::Transform::rotate(float yaw, float pitch, float roll) {
            this->rotation.x += yaw;
            this->rotation.y += pitch;
            this->rotation.z += roll;
        }

        void Ludvig::Core::Transform::set_scale(float x, float y, float z) {
            this->scale.x += x;
            this->scale.y += y;
            this->scale.z += z;
        }

        glm::vec3& Ludvig::Core::Transform::get_position() {
            return this->position;
        }

        glm::vec3& Ludvig::Core::Transform::get_rotation() {
            return this->rotation;
        }

        glm::vec3& Ludvig::Core::Transform::get_scale() {
            return this->scale;
        }
    }
}

