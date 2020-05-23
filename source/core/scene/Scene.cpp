//
// Created by Jesper on 5/11/2020.
//

#include "Scene.h"

#include "../../data/ModelLoader.h"

Ludvig::Core::Scene::Scene::Scene()
{
    this->camera = std::make_unique<Camera>();
    this->light = std::make_unique<Light>();
    this->lightSettings = std::make_unique<Rendering::LightSettings>();

    this->light->name = "Light";
    this->camera->name = "Camera";
    this->camera->transform->translate(0,0,5);

    load_mesh("assets/models/monkey.obj");
}

bool Ludvig::Core::Scene::Scene::load_mesh(const char *path)
{
    std::vector<glm::vec3> vertices = std::vector<glm::vec3>();
    std::vector<glm::vec2> uvs = std::vector<glm::vec2>();
    std::vector<glm::vec3> normals = std::vector<glm::vec3>();

    Data::load_obj(path, vertices,uvs,normals);

    this->meshes.push_back(std::make_unique<Mesh>(vertices,uvs,normals));

    return false;
}