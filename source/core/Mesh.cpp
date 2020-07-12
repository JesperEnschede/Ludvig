//
// Created by Jesper on 5/11/2020.
//

#include "Mesh.h"

namespace Ludvig {
    namespace Core {
        Mesh::Mesh(std::vector<glm::vec3> vertices)
        {
            this->vertices = vertices;

            this->vertexArrayObject = std::make_unique<Rendering::VertexArrayObject>();
            this->buffers.push_back(std::make_unique<Rendering::VertexBufferObject>(3,0,vertices, GL_ARRAY_BUFFER));
        }

        Mesh::Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs)
        {
            this->vertices = vertices;
            this->uvs = uvs;

            this->vertexArrayObject = std::make_unique<Rendering::VertexArrayObject>();
            this->buffers.push_back(std::make_unique<Rendering::VertexBufferObject>(3,0,vertices, GL_ARRAY_BUFFER));
            this->buffers.push_back(std::make_unique<Rendering::VertexBufferObject>(2,1,uvs, GL_ARRAY_BUFFER));
        }

        Mesh::Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals)
        {
            this->vertices = vertices;
            this->uvs = uvs;
            this->normals = normals;

            this->vertexArrayObject = std::make_unique<Rendering::VertexArrayObject>();
            this->buffers.push_back(std::make_unique<Rendering::VertexBufferObject>(3,0,vertices, GL_ARRAY_BUFFER));
            this->buffers.push_back(std::make_unique<Rendering::VertexBufferObject>(2,1,uvs, GL_ARRAY_BUFFER));
            this->buffers.push_back(std::make_unique<Rendering::VertexBufferObject>(3,2,normals, GL_ARRAY_BUFFER));
            this->buffers.push_back(std::make_unique<Rendering::VertexBufferObject>(3,3,indices, GL_ELEMENT_ARRAY_BUFFER));
        }

        std::vector<unsigned int> Mesh::get_mesh_indices()
        {
            return this->indices;
        }

        Ludvig::Rendering::VertexArrayObject *Mesh::get_vao() const
        {
            return this->vertexArrayObject.get();
        }

        int Mesh::get_vertices_size()
        {
            return this->vertices.size();
        }
    }
}


