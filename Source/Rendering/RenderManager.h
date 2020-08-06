//
// File created by Jesper on 8/6/2020.
//

#ifndef LUDVIG_RENDERMANAGER_H
#define LUDVIG_RENDERMANAGER_H

#include "RenderTechnique.h"
#include "RenderContext.h"

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
            virtual void render(Core::Scene* scene) = 0;

        protected:
            std::unique_ptr<RenderTechnique> renderTechnique;
            std::unique_ptr<RenderContext> renderContext;
        };
    }
}



#endif //LUDVIG_RENDERMANAGER_H
