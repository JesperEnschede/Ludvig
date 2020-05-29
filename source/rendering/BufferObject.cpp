//
// Created by Jesper on 5/29/2020.
//

#include "BufferObject.h"
#include "glad/glad.h"

Ludvig::Rendering::BufferObject::BufferObject(int dim, const std::vector<float> &data)
{
    glGenBuffers(1,&this->buffer);
    glBindBuffer(GL_ARRAY_BUFFER,this->buffer);
    glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
}

Ludvig::Rendering::BufferObject::~BufferObject()
{
    glDeleteBuffers(1,&this->buffer);
}
