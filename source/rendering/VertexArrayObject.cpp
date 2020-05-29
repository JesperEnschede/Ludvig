//
// Created by Jesper on 5/29/2020.
//

#include "VertexArrayObject.h"

#include "glad/glad.h"

Ludvig::Rendering::VertexArrayObject::VertexArrayObject()
{
    glGenVertexArrays(1,&this->vao);
    glBindVertexArray(this->vao);
}

Ludvig::Rendering::VertexArrayObject::~VertexArrayObject()
{
    glDeleteVertexArrays(1,&this->vao);
}

void Ludvig::Rendering::VertexArrayObject::bind()
{
    glBindVertexArray(this->vao);
}
