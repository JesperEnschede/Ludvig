//
// Created by Jesper on 5/11/2020.
//

#include "Mesh.h"

Ludvig::Core::Scene::Mesh::Mesh(std::vector<GLfloat> vertices, std::vector<GLfloat> uvs, std::vector<GLfloat> normals)
{
    this->vertices = vertices;
    this->uvs = uvs;
    this->normals = normals;
}