//
// Created by Jesper on 5/29/2020.
//

#include "FrameBuffer.h"

#include "glad/glad.h"

Ludvig::Rendering::FrameBuffer::FrameBuffer()
{
    glGenBuffers(1,&this->buffer);
}

Ludvig::Rendering::FrameBuffer::~FrameBuffer()
{
    glDeleteFramebuffers(1,&this->buffer);
}

void Ludvig::Rendering::FrameBuffer::bind(int target)
{

}
