//
// Created by Jesper on 5/12/2020.
//

#include "Transform.h"

#include "gtc/matrix_transform.hpp"

Ludvig::Core::Scene::Transform::Transform()
{

}

glm::mat4 Ludvig::Core::Scene::Transform::get_trs()
{
    glm::mat4 trs = glm::mat4(1.0f);

    trs = glm::scale(trs, this->scale);
    trs = glm::rotate(trs,glm::radians(-180.0f),this->rotation);
    trs = glm::translate(trs,this->position);

    return trs;
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
}

void Ludvig::Core::Scene::Transform::set_scale(float x, float y, float z)
{
    this->scale.x += x;
    this->scale.y += y;
    this->scale.z += z;
}
