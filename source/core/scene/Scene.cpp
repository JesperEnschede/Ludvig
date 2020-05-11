//
// Created by Jesper on 5/11/2020.
//

#include "Scene.h"

Ludvig::Core::Scene::Scene::Scene()
{

}

bool Ludvig::Core::Scene::Scene::load_mesh(const char *path)
{
    this->meshes.push_back(std::make_unique<Mesh>());

    return false;
}