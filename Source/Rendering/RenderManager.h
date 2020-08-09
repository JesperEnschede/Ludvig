//
// File created by Jesper on 8/6/2020.
//

#ifndef LUDVIG_RENDERMANAGER_H
#define LUDVIG_RENDERMANAGER_H

#include "RenderTechnique.h"
#include "RenderContext.h"
#include "Shader.h"

#include "Core/Scene.h"

#include "memory"

namespace Ludvig
{
    namespace Rendering
    {
        /*
         * The base class for a RenderManager, it must be overridden to define API specific behaviour,
         * The class also handles shaders & textures.
         */
        class RenderManager
        {
        public:
            /*
             * Renders a scene
             */
            virtual void render(Core::Scene* scene) = 0;

            /*
             * Creates and registers a new mesh renderer.
             */
            virtual void create_mesh_renderer(Core::Mesh* mesh) = 0;

            /*
             * Sets the active camera for rendering.
             */
            void set_active_camera(Core::Camera* camera);

        protected:
            std::unique_ptr<RenderTechnique> renderTechnique;
            std::unique_ptr<RenderContext> renderContext;

            // the camera is owned by the scene.
            Core::Camera* camera;
        };
    }
}



#endif //LUDVIG_RENDERMANAGER_H
