//
// Created by Jesper on 5/29/2020.
//

#ifndef LUDVIG_FRAMEBUFFER_H
#define LUDVIG_FRAMEBUFFER_H

#include "VertexBufferObject.h"
#include "Rendering/Texture.h"

#include "Rendering/Shader.h"
#include "Core/Mesh.h"

namespace Ludvig
{
    namespace Rendering
    {
        class FrameBuffer
        {
        public:
            FrameBuffer();
            ~FrameBuffer();

            /*
             * Binds the framebuffer.
             */
            void bind();

            /*
             * Returns a pointer to the color buffer texture object.
             */
            Rendering::Texture* get_color_buffer_texture();

            /*
             * Returns a pointer to the screen shader.
             */
            Rendering::Shader* get_screen_shader();

            /*
             * Returns a pointer to the framebuffer quad mesh.
             */
            Core::Mesh* get_screen_quad_mesh();

        private:
            unsigned int frameBufferObject;
            unsigned int renderBufferObject;

            std::unique_ptr<Rendering::Texture> colorBufferTexture;
            std::unique_ptr<Rendering::Shader> screenShader;
            std::unique_ptr<Core::Mesh> screenQuad;
        };
    }
}

#endif //LUDVIG_FRAMEBUFFER_H
