//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_MESH_H
#define LUDVIG_MESH_H

#include "glad/glad.h"

#include "Core/Object.h"
#include "Core/Transform.h"

#include "glm.hpp"

#include "vector"
#include "memory"

namespace Ludvig
{
    namespace Core
    {
        /*
         * A mesh is an object in a 3D space.
         */
        class Mesh : public Object
        {
        public:
            Mesh(std::vector<glm::vec3> vertices);

            Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs);

            Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals);

            std::vector<unsigned int> get_mesh_indices();

            /*
            * @Temp testing function.
            * Returns the size of the vertices vector.
            */
            int get_vertices_size();

        private:
            std::vector<glm::vec3> vertices;
            std::vector<glm::vec2> uvs;
            std::vector<glm::vec3> normals;
            std::vector<unsigned int> indices = std::vector<unsigned int>();
        };
    }
}


#endif //LUDVIG_MESH_H
