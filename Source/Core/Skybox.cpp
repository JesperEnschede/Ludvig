//
// Created by Jesper on 5/23/2020.
//

#include "Skybox.h"

namespace Ludvig
{
    namespace Core
    {
        Skybox::Skybox()
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

            // this->skyboxMesh = std::make_unique<Mesh>(vertices);
        }

        Mesh *Ludvig::Core::Skybox::get_skybox_mesh()
        {
            return this->skyboxMesh.get();
        }
    }
}

