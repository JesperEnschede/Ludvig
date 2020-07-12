//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_SCENE_H
#define LUDVIG_SCENE_H

#include "Mesh.h"
#include "Camera.h"
#include "Light.h"
#include "Skybox.h"
#include "PostProcessingVolume.h"
#include "Rendering/LightSettings.h"

#include "memory"
#include "vector"

namespace Ludvig
{
    namespace Core
    {
        namespace Scene
        {
            /*
             * A scene is a collection of Meshes, it has a camera, and light sources.
             */
            class Scene
            {
            public:
                /*
                 * Initialize the scene.
                 */
                Scene();

                /*
                 * Load a new mesh.
                 */
                bool load_mesh(const char* path);

            public:
                std::vector<std::unique_ptr<Mesh>> meshes;
                std::unique_ptr<Skybox> skybox;
                std::unique_ptr<Camera> camera;
                std::vector<std::unique_ptr<Light>> light;
                std::unique_ptr<Rendering::LightSettings> lightSettings;
                std::unique_ptr<PostProcessingVolume> postProcessingVolume;
            };
        }
    }
}



#endif //LUDVIG_SCENE_H
