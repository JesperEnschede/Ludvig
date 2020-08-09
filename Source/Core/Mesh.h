//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_MESH_H
#define LUDVIG_MESH_H

#include "Object.h"

#include "glm.hpp"

#include "vector"
#include "memory"

namespace Ludvig
{
    namespace Core
    {
        /*
         * A mesh is an visible mesh Object in 3D space.
         * A MeshRenderer can be used to render a mesh to the screen
         */
        struct Mesh : public Object
        {
            std::vector<unsigned int> indices;
            std::vector<glm::vec3> vertices;
            std::vector<glm::vec2> uvs;
            std::vector<glm::vec3> normals;

            std::string shader;
            std::string texture;
        };

        Mesh* create_mesh(std::string path);
    }
}


#endif //LUDVIG_MESH_H
