//
// Created by Jesper on 5/11/2020.
//

#include "Mesh.h"

namespace Ludvig
{
    namespace Core
    {
        Mesh::Mesh(std::vector<glm::vec3> vertices)
        {
            this->vertices = vertices;
        }

        Mesh::Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs)
        {
            this->vertices = vertices;
            this->uvs = uvs;
        }

        Mesh::Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals)
        {
            this->vertices = vertices;
            this->uvs = uvs;
            this->normals = normals;
        }

        std::vector<unsigned int> Mesh::get_mesh_indices()
        {
            return this->indices;
        }

        int Mesh::get_vertices_size()
        {
            return this->vertices.size();
        }
    }
}


