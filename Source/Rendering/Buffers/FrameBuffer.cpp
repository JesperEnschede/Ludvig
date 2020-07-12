//
// Created by Jesper on 5/29/2020.
//

#include "FrameBuffer.h"

#include "Debug/DebugLog.h"

#include "glad/glad.h"

namespace Ludvig
{
    namespace Rendering
    {
        FrameBuffer::FrameBuffer()
        {
            this->screenShader = std::make_unique<Rendering::Shader>("assets/shaders/screen_vertex.glsl","assets/shaders/screen_fragment.glsl");
            this->colorBufferTexture = std::make_unique<Rendering::Texture>();

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

            this->screenQuad = std::make_unique<Core::Mesh>(quadVertices,quadUVS);

            screenShader->set_texture("screenTexture",0);

            glGenFramebuffers(1,&this->frameBufferObject);

            glBindFramebuffer(GL_FRAMEBUFFER, this->frameBufferObject);

            glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, this->colorBufferTexture->id, 0);

            glGenRenderbuffers(1,&this->renderBufferObject);
            glBindRenderbuffer(GL_RENDERBUFFER, this->renderBufferObject);
            glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, 1920, 1080);
            glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, this->renderBufferObject);

            if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
            {
                Debug::DebugLog::log_error("Framebuffer is not complete!");

                std::printf("Framebuffer is broken :D \n \0");
            }

            glBindFramebuffer(GL_FRAMEBUFFER, 0);
        }

        FrameBuffer::~FrameBuffer()
        {
            glDeleteFramebuffers(1,&this->frameBufferObject);
        }

        void FrameBuffer::bind(unsigned int target)
        {
            glBindFramebuffer(GL_FRAMEBUFFER,this->frameBufferObject);
        }

        Rendering::Texture *FrameBuffer::get_color_buffer_texture()
        {
            return colorBufferTexture.get();
        }

        Rendering::Shader *FrameBuffer::get_screen_shader()
        {
            return this->screenShader.get();
        }

        Core::Mesh *FrameBuffer::get_screen_quad_mesh()
        {
            return screenQuad.get();
        }
    }
}

