//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_SCENE_H
#define LUDVIG_SCENE_H

#include "Mesh.h"

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
            };
        }
    }
}



#endif //LUDVIG_SCENE_H
