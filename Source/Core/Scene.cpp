//
// Created by Jesper on 5/11/2020.
//

#include "Scene.h"

#include "data/ModelLoader.h"
#include "debug/DebugLog.h"

Ludvig::Core::Scene::Scene::Scene()
{
    Debug::DebugLog::log_message("Creating scene");

    this->camera = std::make_unique<Camera>();
    this->skybox = std::make_unique<Skybox>();
    this->postProcessingVolume = std::make_unique<PostProcessingVolume>();

    this->light.push_back(std::make_unique<Light>());
    this->light[0]->type = LightType::Directional;
    this->light[0]->name = "Directional light \0";
    this->light[0]->transform->rotation = glm::vec3(0,0,1.5);

    this->camera->name = "Camera";
    this->camera->transform->translate(0,0,-15);

    load_mesh("assets/models/well.obj");
}

bool Ludvig::Core::Scene::Scene::load_mesh(const char *path)
{
    Debug::DebugLog::log_message("Loading mesh: " + std::string(path));

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