//
// Created by Jesper on 5/11/2020.
//

#include "Mesh.h"

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
}

Ludvig::Core::Scene::Mesh::~Mesh()
{
    glDeleteBuffers(1,&vbo);
    glDeleteBuffers(1,&nbo);
    glDeleteBuffers(1,&ubo);
    glDeleteBuffers(1,&ebo);

    glDeleteVertexArrays(1,&vao);
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

    glVertexAttribPointer(0,3,GL_FLOAT, GL_FALSE,0,(void*)0);
}

void Ludvig::Core::Scene::Mesh::generate_normal_buffer()
{
    glGenBuffers(1,&this->nbo);
    glBindBuffer(GL_ARRAY_BUFFER, this->nbo);
    glBufferData(GL_ARRAY_BUFFER,this->normals.size() * sizeof(glm::vec2), &this->normals[0],GL_STATIC_DRAW);
    glVertexAttribPointer(2,3,GL_FLOAT,GL_FALSE,0,(void*)0);
}

void Ludvig::Core::Scene::Mesh::generate_uv_buffer()
{
    glGenBuffers(1,&this->ubo);
    glBindBuffer(GL_ARRAY_BUFFER, this->ubo);
    glBufferData(GL_ARRAY_BUFFER, this->uvs.size() * sizeof(glm::vec3), &this->uvs[0], GL_STATIC_DRAW);
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,0,(void*)0);
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

