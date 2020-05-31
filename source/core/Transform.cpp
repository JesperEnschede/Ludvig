//
// Created by Jesper on 5/12/2020.
//

#include "Transform.h"

#include "gtc/matrix_transform.hpp"
#include "gtc/quaternion.hpp"
#include "gtx/quaternion.hpp"
#include "gtx/euler_angles.hpp"
#include "gtx/norm.hpp"

Ludvig::Core::Scene::Transform::Transform()
{
    this->rotation.w = 1;
}

glm::mat4 Ludvig::Core::Scene::Transform::get_trs()
{
    glm::mat4 trs = glm::mat4(1.0f);

    /*
    trs = glm::scale(trs, this->scale);
    trs = glm::rotate(trs,glm::radians(-180.0f),this->rotation);
    trs = glm::translate(trs,this->position);
    */
    //glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1.0f),glm::radians(-180.0f), this->rotation);

    glm::mat4 rotationMatrix = glm::mat4(1.0f);// = glm::mat4_cast(this->rotation);
    this->rotation = glm::quat(glm::eulerAngles(this->rotation));
    rotationMatrix = glm::mat4_cast(this->rotation);
    glm::mat4 translationMatrix = glm::translate(glm::mat4(1.0f), this->position);
    glm::mat4 scaleMatrix = glm::scale(glm::mat4(1.0f), this->scale);


    return translationMatrix * rotationMatrix * scaleMatrix;
}

void Ludvig::Core::Scene::Transform::translate(float x, float y, float z)
{
    this->position.x += x;
    this->position.y += y;
    this->position.z += z;
}

void Ludvig::Core::Scene::Transform::rotate(float yaw, float pitch, float roll)
{
    this->rotation.x += yaw;
    this->rotation.y += pitch;
    this->rotation.z += roll;
    this->rotation.w = 1;
}

void Ludvig::Core::Scene::Transform::set_scale(float x, float y, float z)
{
    this->scale.x += x;
    this->scale.y += y;
    this->scale.z += z;
}

glm::vec3 Ludvig::Core::Scene::Transform::get_position()
{
    return this->position;
}

glm::vec3 Ludvig::Core::Scene::Transform::get_rotation()
{
    //return this->rotation;
    return glm::vec3();
}

glm::vec3 Ludvig::Core::Scene::Transform::get_scale()
{
    return this->scale;
}
