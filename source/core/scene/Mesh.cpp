//
// Created by Jesper on 5/11/2020.
//

#include "Mesh.h"

Ludvig::Core::Scene::Mesh::Mesh()
{
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

    this->indices = vertices.size() * 3;

    this->generate_vertex_array();
    this->generate_vertex_buffer();
    this->generate_uv_buffer();

    this->transform = std::make_unique<Transform>();
}

Ludvig::Core::Scene::Mesh::Mesh(std::vector<GLfloat> vertices, std::vector<GLfloat> uvs, std::vector<GLfloat> normals)
{
    this->vertices = vertices;
    this->uvs = uvs;
    this->normals = normals;

    this->generate_vertex_array();
    this->generate_vertex_buffer();
    this->generate_uv_buffer();
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
    glBufferData(GL_ARRAY_BUFFER,this->vertices.size() * sizeof(GLfloat), &this->vertices[0], GL_STATIC_DRAW);
}

void Ludvig::Core::Scene::Mesh::generate_uv_buffer()
{
    glGenBuffers(1,&this->ubo);
    glBindBuffer(GL_ARRAY_BUFFER, this->ubo);
    glBufferData(GL_ARRAY_BUFFER, this->uvs.size() * sizeof(GLfloat), &this->uvs[0], GL_STATIC_DRAW);
}

void Ludvig::Core::Scene::Mesh::generate_element_buffer()
{
    throw "generate_element_buffer is not implemented!";
}
