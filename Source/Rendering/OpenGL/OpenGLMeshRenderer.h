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
                /*
                 * Creates OpenGL buffer objects from mesh data.
                 */
                OpenGLMeshRenderer(Core::Mesh* mesh);

                /*
                 * Deletes the mesh renderer buffers.
                 */
                virtual ~OpenGLMeshRenderer();

                void render() override;

            private:
                unsigned int vao;
                std::vector<unsigned int> buffers;

                size_t verticesSize; // TODO(Jesper) remove temp size;
            };
        }
    }
}

#endif //LUDVIG_OPENGLMESHRENDERER_H
