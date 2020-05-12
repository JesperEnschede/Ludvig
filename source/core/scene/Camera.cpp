//
// Created by Jesper on 5/12/2020.
//

#include "Camera.h"

Ludvig::Core::Scene::Camera::Camera()
{

}

glm::mat4 Ludvig::Core::Scene::Camera::get_view_projection_matrix()
{
    glm::mat4 view = this->transform->get_trs();
    glm::mat4 projection = glm::perspective(glm::radians(60.0f),16.0f / 9.0f, nearClipping,farClipping);

    return projection * view;
}
