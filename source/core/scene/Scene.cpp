//
// Created by Jesper on 5/11/2020.
//

#include "Scene.h"

#include "../../data/ModelLoader.h"

Ludvig::Core::Scene::Scene::Scene()
{
    this->camera = std::make_unique<Camera>();

    this->lightSettings = std::make_unique<Rendering::LightSettings>();
    this->skybox = std::make_unique<Skybox>();

    this->light.push_back(std::make_unique<Light>());
    this->light[0]->type = LightType::Directional;
    this->light[0]->name = "Directional light \0";
    
    this->camera->name = "Camera";
    this->camera->transform->translate(0,0,15);

    load_mesh("assets/models/well.obj");
    // load_mesh("assets/models/plane.obj");
}

bool Ludvig::Core::Scene::Scene::load_mesh(const char *path)
{
    std::vector<glm::vec3> vertices = std::vector<glm::vec3>();
    std::vector<glm::vec2> uvs = std::vector<glm::vec2>();
    std::vector<glm::vec3> normals = std::vector<glm::vec3>();

    Data::load_obj(path, vertices,uvs,normals);

    Mesh* mesh = new Mesh(vertices,uvs,normals);
    mesh->name = path;
    mesh->transform->position = glm::vec3(0,0,0);

    this->meshes.push_back(std::move(std::unique_ptr<Mesh>(mesh)));

    return false;
}