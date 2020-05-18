//
// Created by Jesper on 5/18/2020.
//

#include "Light.h"

Ludvig::Core::Scene::Light::Light()
{
    this->transform = std::make_unique<Transform>();
}
