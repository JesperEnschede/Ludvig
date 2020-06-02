//
// Created by Jesper on 5/29/2020.
//

#include "BufferObject.h"
#include "glad/glad.h"

Ludvig::Rendering::VertexBufferObject::VertexBufferObject(int dim,int index, const std::vector<glm::vec2> &data, int GL_BUFFER)
{
    GL_ARRAY_BUFFER;

    glGenBuffers(1,&this->buffer);
    glBindBuffer(GL_BUFFER,this->buffer);
    glBufferData(GL_BUFFER, data.size() * sizeof(glm::vec2), data.data(), GL_STATIC_DRAW);

    if (GL_BUFFER != GL_ELEMENT_ARRAY_BUFFER)
    {
        glVertexAttribPointer(index,dim,GL_FLOAT,GL_FALSE,0,(void*)0);
    }
}

Ludvig::Rendering::VertexBufferObject::VertexBufferObject(int dim,int index, const std::vector<glm::vec3> &data, int GL_BUFFER)
{
    glGenBuffers(1,&this->buffer);
    glBindBuffer(GL_BUFFER,this->buffer);
    glBufferData(GL_BUFFER, data.size() * sizeof(glm::vec3), data.data(), GL_STATIC_DRAW);

    if (GL_BUFFER != GL_ELEMENT_ARRAY_BUFFER)
    {
        glVertexAttribPointer(index,dim,GL_FLOAT,GL_FALSE,0,(void*)0);
    }
}

Ludvig::Rendering::VertexBufferObject::VertexBufferObject(int dim,int index, const std::vector<unsigned int> &data, int GL_BUFFER)
{
    glGenBuffers(1,&this->buffer);
    glBindBuffer(GL_BUFFER,this->buffer);
    glBufferData(GL_BUFFER, data.size() * sizeof(unsigned int), data.data(), GL_STATIC_DRAW);

    if (GL_BUFFER != GL_ELEMENT_ARRAY_BUFFER)
    {
        glVertexAttribPointer(index,dim,GL_FLOAT,GL_FALSE,0,(void*)0);
    }
}


Ludvig::Rendering::VertexBufferObject::~VertexBufferObject()
{
    glDeleteBuffers(1,&this->buffer);
}



