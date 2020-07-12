//
// Created by Jesper on 5/23/2020.
//

#ifndef LUDVIG_SKYBOX_H
#define LUDVIG_SKYBOX_H

#include "Mesh.h"

#include "glad/glad.h"

#include "vector"

namespace Ludvig
{
    namespace Core
    {
        /*
         * A skybox is a inverted cube mesh that can have a cubemap texture to create a sky.
         */
        class Skybox
        {
        public:
            /*
             * Bind the skybox vbo.
             */
            Skybox();

            /*
             * Returns a pointer to the skybox mesh.
             */
            Mesh *get_skybox_mesh();

        private:
            std::unique_ptr<Mesh> skyboxMesh;
        };
    }
}


#endif //LUDVIG_SKYBOX_H
