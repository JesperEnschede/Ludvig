//
// Created by Jesper on 5/11/2020.
//

#include "Scene.h"

Ludvig::Core::Scene::Scene::Scene()
{
    load_mesh("test");
}

bool Ludvig::Core::Scene::Scene::load_mesh(const char *path)
{
    // todo: load mesh
    // todo: create_unique mesh instance based on the loaded mesh
    // todo: return true|false

    this->meshes.push_back(std::make_unique<Mesh>());
    this->meshes.push_back(std::make_unique<Mesh>());
    this->meshes.push_back(std::make_unique<Mesh>());


    return false;
}