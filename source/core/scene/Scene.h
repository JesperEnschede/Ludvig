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
            class Scene
            {
            public:
                Scene() = default;

                bool load_mesh(const char* path);

            private:
                std::vector<std::unique_ptr<Mesh>> meshes;
            };
        }
    }
}



#endif //LUDVIG_SCENE_H
