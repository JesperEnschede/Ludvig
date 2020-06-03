//
// Created by Jesper on 5/29/2020.
//

#include "FrameBuffer.h"

#include "../debug/DebugLog.h"

#include "glad/glad.h"


Ludvig::Rendering::FrameBuffer::FrameBuffer()
{
    this->screenShader = std::make_unique<Core::Scene::Shader>("assets/shaders/screen_vertex.glsl","assets/shaders/screen_fragment.glsl");

    std::vector<glm::vec3> quadVertices =
    {
            glm::vec3(-1.0f,  1.0f,0.0f),
            glm::vec3(-1.0f, -1.0f,0.0f),
            glm::vec3(1.0f, -1.0f,0.0f),
            glm::vec3(-1.0f,  1.0f,0.0f),
            glm::vec3(1.0f, -1.0f,0.0f),
            glm::vec3(1.0f,  1.0f,0.0f)
    };

    std::vector<glm::vec2> quadUVS =
    {
            glm::vec2(0.0f, 1.0f),
            glm::vec2( 0.0f, 0.0f),
            glm::vec2(1.0f, 0.0f),
            glm::vec2(0.0f, 1.0f),
            glm::vec2(1.0f, 0.0f),
            glm::vec2(1.0f, 1.0f)
    };

    this->screenQuad = std::make_unique<Core::Scene::Mesh>(quadVertices,quadUVS);

    float aquadVertices[] = { // vertex attributes for a quad that fills the entire screen in Normalized Device Coordinates.
            // positions   // texCoords
            -1.0f,  1.0f,  0.0f, 1.0f,
            -1.0f, -1.0f,  0.0f, 0.0f,
            1.0f, -1.0f,  1.0f, 0.0f,

            -1.0f,  1.0f,  0.0f, 1.0f,
            1.0f, -1.0f,  1.0f, 0.0f,
            1.0f,  1.0f,  1.0f, 1.0f
    };

    glGenVertexArrays(1, &testVAO);
    glGenBuffers(1, &testVBO);
    glBindVertexArray(testVAO);
    glBindBuffer(GL_ARRAY_BUFFER, testVBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(aquadVertices), &aquadVertices, GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)(2 * sizeof(float)));

    glBindVertexArray(0);

    glGenBuffers(1,&this->frameBufferObject);
    glBindFramebuffer(GL_FRAMEBUFFER, this->frameBufferObject);

    this->colorBufferTexture = std::make_unique<Core::Scene::Texture>();

    screenShader->set_texture("screenTexture",colorBufferTexture->id);

    glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, this->colorBufferTexture->id, 0);

    glGenRenderbuffers(1,&this->renderBufferObject);
    glBindRenderbuffer(GL_RENDERBUFFER, this->renderBufferObject);
    glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 1920, 1080);
    glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, this->renderBufferObject);

    if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
    {
        Debug::DebugLog::log_error("Framebuffer is not complete!");
    }

    glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

Ludvig::Rendering::FrameBuffer::~FrameBuffer()
{
    glDeleteFramebuffers(1,&this->frameBufferObject);
}

void Ludvig::Rendering::FrameBuffer::bind(unsigned int target)
{
    glBindFramebuffer(GL_FRAMEBUFFER,this->frameBufferObject);
}

Ludvig::Core::Scene::Texture *Ludvig::Rendering::FrameBuffer::get_color_buffer_texture()
{
    return colorBufferTexture.get();
}

Ludvig::Core::Scene::Mesh *Ludvig::Rendering::FrameBuffer::get_screen_quad_mesh()
{
    return screenQuad.get();
}

Ludvig::Core::Scene::Shader *Ludvig::Rendering::FrameBuffer::get_screen_shader()
{
    return this->screenShader.get();
}
