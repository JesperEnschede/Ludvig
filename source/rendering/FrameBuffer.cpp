//
// Created by Jesper on 5/29/2020.
//

#include "FrameBuffer.h"

#include "../debug/DebugLog.h"

#include "glad/glad.h"


Ludvig::Rendering::FrameBuffer::FrameBuffer()
{
    glGenBuffers(1,&this->buffer);
    glBindFramebuffer(GL_FRAMEBUFFER, this->buffer);

    glGenTextures(1,&this->colorBuffer);
    glBindTexture(GL_TEXTURE_2D, this->colorBuffer);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1920, 1080, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, this->colorBuffer, 0);

    glGenRenderbuffers(1,&this->renderBuffer);
    glBindRenderbuffer(GL_RENDERBUFFER, this->renderBuffer);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 1920, 1080);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, this->renderBuffer);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
    {
        Debug::DebugLog::log_error("Framebuffer is not complete!");
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

Ludvig::Rendering::FrameBuffer::~FrameBuffer()
{
    glDeleteFramebuffers(1,&this->buffer);
}

void Ludvig::Rendering::FrameBuffer::bind(unsigned int target)
{
    glBindFramebuffer(target,this->buffer);
}