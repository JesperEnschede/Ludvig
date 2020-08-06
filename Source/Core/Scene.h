//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_SCENE_H
#define LUDVIG_SCENE_H

#include "Mesh.h"
#include "Camera.h"
#include "Light.h"

// #include "Skybox.h"
// #include "PostProcessingVolume.h"

#include "memory"

namespace Ludvig
{
    namespace Core
    {
        /*
         * A scene is a collection of objects
         */
        struct Scene
        {
        public:
            /*
             * Initializes the scene with default objects.
             */
            Scene();

            std::unique_ptr<Mesh> mesh;
            std::unique_ptr<Camera> camera;
            std::unique_ptr<Light> light;
        };
    }
}

#endif //LUDVIG_SCENE_H
