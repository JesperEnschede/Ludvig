//
// Created by Jesper on 5/11/2020.
//

#include "Mesh.h"

Ludvig::Core::Scene::Mesh::Mesh()
{
    /*
    this->vertices =
            {
                    -1.0, -1.0,  1.0,
                    1.0, -1.0,  1.0,
                    1.0,  1.0,  1.0,
                    -1.0,  1.0,  1.0,
                    -1.0, -1.0, -1.0,
                    -1.0,  1.0, -1.0,
                    1.0,  1.0, -1.0,
                    1.0, -1.0, -1.0,
                    -1.0,  1.0, -1.0,
                    -1.0,  1.0,  1.0,
                    1.0,  1.0,  1.0,
                    1.0,  1.0, -1.0,
                    -1.0, -1.0, -1.0,
                    1.0, -1.0, -1.0,
                    1.0, -1.0,  1.0,
                    -1.0, -1.0,  1.0,
                    1.0, -1.0, -1.0,
                    1.0,  1.0, -1.0,
                    1.0,  1.0,  1.0,
                    1.0, -1.0,  1.0,
                    -1.0, -1.0, -1.0,
                    -1.0, -1.0,  1.0,
                    -1.0,  1.0,  1.0,
                    -1.0,  1.0, -1.0,
            };

    this->uvs =
            {
                    0.0, 1.0,
                    0.0, 0.0,
                    1.0, 0.0,
                    0.0, 1.0,
                    1.0, 0.0,
                    1.0, 1.0,
            };

    this->indices =
            {
                    0,  1,  2, 0,  2,  3,
                    4,  5,  6, 4,  6,  7,
                    8,  9,  10, 8,  10, 11,
                    12, 13, 14, 12, 14, 15,
                    16, 17, 18, 16, 18, 19,
                    20, 21, 22, 20, 22, 23,
            };

    this->generate_vertex_array();
    this->generate_vertex_buffer();
    this->generate_normal_buffer();
    this->generate_uv_buffer();
    this->generate_element_buffer();

    this->transform = std::make_unique<Transform>();

    this->transform->rotate(45,45,45);
     */
}

Ludvig::Core::Scene::Mesh::Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals)
{
    this->vertices = vertices;
    this->uvs = uvs;
    this->normals = normals;

    this->generate_vertex_array();
    this->generate_vertex_buffer();
    this->generate_normal_buffer();
    this->generate_uv_buffer();
    this->generate_element_buffer();

    this->transform = std::make_unique<Transform>();

    this->transform->rotate(0,0,0);
    this->transform->translate(0,0,-5);
}

void Ludvig::Core::Scene::Mesh::generate_vertex_array()
{
    glGenVertexArrays(1,&this->vao);
    glBindVertexArray(this->vao);
}

void Ludvig::Core::Scene::Mesh::generate_vertex_buffer()
{
    glGenBuffers(1,&this->vbo);
    glBindBuffer(GL_ARRAY_BUFFER,this->vbo);
    glBufferData(GL_ARRAY_BUFFER,this->vertices.size() * sizeof(glm::vec3), &this->vertices[0], GL_STATIC_DRAW);
}

void Ludvig::Core::Scene::Mesh::generate_normal_buffer()
{
    glGenBuffers(1,&this->nbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->nbo);
    glBufferData(GL_ARRAY_BUFFER,this->normals.size() * sizeof(glm::vec2), &this->normals[0],GL_STATIC_DRAW);
}

void Ludvig::Core::Scene::Mesh::generate_uv_buffer()
{
    glGenBuffers(1,&this->ubo);
    glBindBuffer(GL_ARRAY_BUFFER, this->ubo);
    glBufferData(GL_ARRAY_BUFFER, this->uvs.size() * sizeof(glm::vec3), &this->uvs[0], GL_STATIC_DRAW);
}

void Ludvig::Core::Scene::Mesh::generate_element_buffer()
{
    glGenBuffers(1,&this->ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,this->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);
}

std::vector<unsigned int> Ludvig::Core::Scene::Mesh::get_mesh_indices()
{
    return this->indices;
}
