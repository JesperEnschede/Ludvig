//
// File created by Jesper on 7/8/2020.
//

#include "SceneManager.h"

#include <Data/ModelLoader.h>

namespace Ludvig
{
    namespace SceneManagement
    {
        std::unique_ptr<Scene> SceneManager::currentScene;

        SceneManager::SceneManager()
        {
            currentScene = std::make_unique<Scene>();

            currentScene->camera = std::make_unique<Core::Camera>();
            currentScene->postProcessingVolume = std::make_unique<Core::PostProcessingVolume>();
        }

        Scene *SceneManager::get_current_scene()
        {
            return currentScene.get();
        }

        void SceneManager::test_model() {

            std::vector<glm::vec3> vertices = std::vector<glm::vec3>();
            std::vector<glm::vec2> uvs = std::vector<glm::vec2>();
            std::vector<glm::vec3> normals = std::vector<glm::vec3>();

            Data::load_obj("assets/models/well.obj", vertices,uvs,normals);

            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    for (int k = 0; k < 3; ++k) {
                        Core::Mesh* mesh = new Core::Mesh(vertices,uvs,normals);
                        mesh->name = "assets/models/well.obj";
                        mesh->transform->position = glm::vec3(i * 30,j * 30,k * 30);

                        currentScene->meshes.push_back(std::move(std::unique_ptr<Core::Mesh>(mesh)));
                    }
                }
            }
        }
    }
}
