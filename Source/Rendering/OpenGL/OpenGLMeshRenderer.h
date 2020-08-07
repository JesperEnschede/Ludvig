//
// File created by Jesper on 8/6/2020.
//

#ifndef LUDVIG_OPENGLMESHRENDERER_H
#define LUDVIG_OPENGLMESHRENDERER_H

#include "Rendering/MeshRenderer.h"

#include "Core/Mesh.h"

#include "vector"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            /*
             * OpenGL implementation of a meshrenderer, Read MeshRenderer class brief for info.
             */
            class OpenGLMeshRenderer : public MeshRenderer
            {
            public:
                OpenGLMeshRenderer(Core::Mesh* mesh);

                void render() override;

            private:
                unsigned int vao;
                std::vector<unsigned int> buffers;
            };
        }
    }
}

#endif //LUDVIG_OPENGLMESHRENDERER_H
