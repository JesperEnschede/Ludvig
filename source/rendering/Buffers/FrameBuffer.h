//
// Created by Jesper on 5/29/2020.
//

#ifndef LUDVIG_FRAMEBUFFER_H
#define LUDVIG_FRAMEBUFFER_H

#include "VertexBufferObject.h"
#include "rendering/Texture.h"

#include "rendering/Shader.h"
#include "core/scene/Mesh.h"

namespace Ludvig
{
    namespace Rendering
    {
        class FrameBuffer
        {
        public:
            FrameBuffer();
            ~FrameBuffer();

            void bind(unsigned int target);

            Core::Scene::Texture* get_color_buffer_texture();
            Core::Scene::Mesh* get_screen_quad_mesh();
            Core::Scene::Shader* get_screen_shader();

        private:
            unsigned int frameBufferObject;
            unsigned int renderBufferObject;

            std::unique_ptr<Core::Scene::Texture> colorBufferTexture;
            std::unique_ptr<Core::Scene::Shader> screenShader;
            std::unique_ptr<Core::Scene::Mesh> screenQuad;
        };
    }
}

#endif //LUDVIG_FRAMEBUFFER_H
