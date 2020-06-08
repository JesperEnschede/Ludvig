//
// Created by Jesper on 5/23/2020.
//

#include "Skybox.h"

Ludvig::Core::Scene::Skybox::Skybox()
{
    std::vector<glm::vec3> vertices =
            {
                    glm::vec3(-1.0f,  1.0f, -1.0f),
                    glm::vec3(-1.0f, -1.0f, -1.0f),
                    glm::vec3(1.0f, -1.0f, -1.0f),
                    glm::vec3(1.0f,  1.0f, -1.0f),
                    glm::vec3(-1.0f,  1.0f, -1.0f),
                    glm::vec3(-1.0f, -1.0f,  1.0f),
                    glm::vec3(-1.0f, -1.0f, -1.0f),
                    glm::vec3(-1.0f,  1.0f, -1.0f),
                    glm::vec3(-1.0f,  1.0f, -1.0f),
                    glm::vec3(-1.0f,  1.0f,  1.0f),
                    glm::vec3(-1.0f, -1.0f,  1.0f),
                    glm::vec3(1.0f, -1.0f, -1.0f),
                    glm::vec3(1.0f, -1.0f, -1.0f),
                    glm::vec3(1.0f, -1.0f,  1.0f),
                    glm::vec3(1.0f,  1.0f,  1.0f),
                    glm::vec3(1.0f,  1.0f,  1.0f),
                    glm::vec3(1.0f,  1.0f, -1.0f),
                    glm::vec3(1.0f, -1.0f, -1.0f),
                    glm::vec3(-1.0f, -1.0f,  1.0f),
                    glm::vec3(-1.0f,  1.0f,  1.0f),
                    glm::vec3(1.0f,  1.0f,  1.0f),
                    glm::vec3(1.0f,  1.0f,  1.0f),
                    glm::vec3(1.0f, -1.0f,  1.0f),
                    glm::vec3(-1.0f, -1.0f,  1.0f),
                    glm::vec3(-1.0f,  1.0f, -1.0f),
                    glm::vec3(1.0f,  1.0f, -1.0f),
                    glm::vec3(1.0f,  1.0f,  1.0f),
                    glm::vec3(1.0f,  1.0f,  1.0f),
                    glm::vec3(-1.0f,  1.0f,  1.0f),
                    glm::vec3(-1.0f,  1.0f, -1.0f),
                    glm::vec3(-1.0f, -1.0f, -1.0f),
                    glm::vec3(-1.0f, -1.0f,  1.0f),
                    glm::vec3(1.0f, -1.0f, -1.0f),
                    glm::vec3(1.0f, -1.0f, -1.0f),
                    glm::vec3(-1.0f, -1.0f,  1.0f),
                    glm::vec3(1.0f, -1.0f,  1.0f)
            };

    this->skyboxMesh = std::make_unique<Mesh>(vertices);
}

Ludvig::Core::Scene::Skybox::~Skybox()
{

}

Ludvig::Core::Scene::Mesh *Ludvig::Core::Scene::Skybox::get_skybox_mesh()
{
    return this->skyboxMesh.get();
}
