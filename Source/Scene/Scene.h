//
// File created by Jesper on 7/12/2020.
//

#ifndef LUDVIG_SCENE_H
#define LUDVIG_SCENE_H

#include "Core/Mesh.h"
#include "Core/Camera.h"
#include "Core/PostProcessingVolume.h"
#include "Core/Light.h"
#include "Core/Skybox.h"

#include "vector"
#include "memory"

namespace Ludvig
{
    namespace SceneManagement
    {
        /*
         * The scene data struct is a container of everything inside of a scene.
         */
        struct Scene
        {
            std::unique_ptr<Core::Camera> camera;
            std::unique_ptr<Core::PostProcessingVolume> postProcessingVolume;
            std::unique_ptr<Core::Skybox> skybox;

            std::vector<std::unique_ptr<Core::Mesh>> meshes;
            std::vector<std::unique_ptr<Core::Light>> lights;
        };
    }
}

#endif //LUDVIG_SCENE_H
