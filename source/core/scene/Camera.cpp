//
// Created by Jesper on 5/12/2020.
//

#include "Camera.h"

Ludvig::Core::Scene::Camera::Camera()
{
    this->transform = std::make_unique<Transform>();
}

glm::mat4 Ludvig::Core::Scene::Camera::get_view_projection_matrix()
{
    return this->projectionMatrix * this->viewMatrix;
}

void Ludvig::Core::Scene::Camera::calculate_view_projection_matrix()
{
    this->viewMatrix = this->transform->get_trs();
    this->projectionMatrix = glm::perspective(glm::radians(this->fieldOfView),16.0f / 9.0f, this->nearClipping,this->farClipping);
}

glm::mat4 Ludvig::Core::Scene::Camera::get_view_matrix()
{
    return this->viewMatrix;
}

glm::mat4 Ludvig::Core::Scene::Camera::get_projection_matrix()
{
    return this->projectionMatrix;
}
