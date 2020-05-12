//
// Created by Jesper on 5/12/2020.
//

#include "Camera.h"

Ludvig::Core::Scene::Camera::Camera()
{
    this->transform = std::make_unique<Transform>();

    transform->translate(0,0,-1);
}

glm::mat4 Ludvig::Core::Scene::Camera::get_view_projection_matrix()
{
    return this->viewMatrix * this->projectionMatrix;
}

void Ludvig::Core::Scene::Camera::calculate_view_projection_matrix()
{
    this->viewMatrix = this->transform->get_trs();
    this->projectionMatrix = glm::perspective(glm::radians(this->fieldOfView),16.0f / 9.0f, this->nearClipping,this->farClipping);
}
