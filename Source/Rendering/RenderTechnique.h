//
// File created by Jesper on 8/6/2020.
//

#ifndef LUDVIG_RENDERTECHNIQUE_H
#define LUDVIG_RENDERTECHNIQUE_H

#include "MeshRenderer.h"

#include "Core/Scene.h"

#include "vector"
#include "memory"

namespace Ludvig
{
    namespace Rendering
    {
        /*
         * The RenderTechnique class must be overridden to define API specific behaviour and
         * on how to render a scene, eg: Forward rendering or deferred rendering
         * The RenderTechnique is owned by a RenderManager.
         */
        class RenderTechnique
        {
        public:
            /*
             * Renders a scene with API defined calls
             */
            virtual void render_scene(Core::Scene* scene) = 0;

            std::unique_ptr<MeshRenderer> meshRenderer;
        };
    }
}

#endif //LUDVIG_RENDERTECHNIQUE_H
