//
// Created by Jesper on 5/11/2020.
//

#include "Mesh.h"

Ludvig::Core::Scene::Mesh::Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals)
{
    this->vertices = vertices;
    this->uvs = uvs;
    this->normals = normals;

    this->vertexArrayObject = std::make_unique<Rendering::VertexArrayObject>();
    this->buffers.push_back(std::make_unique<Rendering::BufferObject>(3,0,vertices, GL_ARRAY_BUFFER));
    this->buffers.push_back(std::make_unique<Rendering::BufferObject>(2,1,uvs, GL_ARRAY_BUFFER));
    this->buffers.push_back(std::make_unique<Rendering::BufferObject>(3,2,normals, GL_ARRAY_BUFFER));
    this->buffers.push_back(std::make_unique<Rendering::BufferObject>(3,3,indices, GL_ELEMENT_ARRAY_BUFFER));
}

std::vector<unsigned int> Ludvig::Core::Scene::Mesh::get_mesh_indices()
{
    return this->indices;
}

Ludvig::Rendering::VertexArrayObject *Ludvig::Core::Scene::Mesh::get_vao() const
{
    return this->vertexArrayObject.get();
}

int Ludvig::Core::Scene::Mesh::get_vertices_size()
{
    return this->vertices.size();
}
