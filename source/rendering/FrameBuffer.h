//
// Created by Jesper on 5/29/2020.
//

#ifndef LUDVIG_FRAMEBUFFER_H
#define LUDVIG_FRAMEBUFFER_H

#include "VertexBufferObject.h"
#include "Texture.h"

#include "Shader.h"
#include "../core/scene/Mesh.h"

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

        private:
            unsigned int frameBufferObject;
            unsigned int renderBufferObject;

            std::unique_ptr<Core::Scene::Texture> colorBufferTexture;

            Core::Scene::Mesh screenQuad =
                    Core::Scene::Mesh
                    (
                            {
                                glm::vec3(-1.0f,  1.0f,0.0f),
                                glm::vec3(-1.0f, -1.0f,0.0f),
                                glm::vec3(1.0f, -1.0f,0.0f),
                                glm::vec3(-1.0f,  1.0f,0.0f),
                                glm::vec3(1.0f, -1.0f,0.0f),
                                glm::vec3(1.0f,  1.0f,0.0f)
                                },
                            {
                                glm::vec3(0.0f, 1.0f,0.0f),
                                glm::vec3( 0.0f, 0.0f,0.0f),
                                glm::vec3(1.0f, 0.0f,0.0f),
                                glm::vec3(0.0f, 1.0f,0.0f),
                                glm::vec3(1.0f, 0.0f,0.0f),
                                glm::vec3(1.0f, 1.0f,0.0f)
                                },
                            { /* we don't do normals here, because i said so :p */ });
        };
    }
}



#endif //LUDVIG_FRAMEBUFFER_H
