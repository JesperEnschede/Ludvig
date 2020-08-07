//
// File created by Jesper on 8/6/2020.
//

#ifndef LUDVIG_OPENGLRENDERMANAGER_H
#define LUDVIG_OPENGLRENDERMANAGER_H

#include "glad/glad.h"

#include "Rendering/RenderManager.h"
#include "Rendering/Window.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            class OpenGLRenderManager : public RenderManager
            {
            public:
                OpenGLRenderManager(Window* window);

                void render(Core::Scene* scene) override;

                void create_mesh_renderer(Core::Mesh *mesh) override;
            private:
                void load_openGL();
            };
        }
    }
}

#endif //LUDVIG_OPENGLRENDERMANAGER_H
