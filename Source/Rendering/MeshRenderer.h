//
// File created by Jesper on 8/6/2020.
//

#ifndef LUDVIG_MESHRENDERER_H
#define LUDVIG_MESHRENDERER_H

#include "glm.hpp"

namespace Ludvig
{
    namespace Rendering
    {
        /*
         * The MeshRender class is a abstract class that must be overridden to defined API specific behaviour,
         * It creates buffers from mesh information.
         */
        class MeshRenderer
        {
        public:
            virtual void render(glm::mat4 view, glm::mat4 projection) = 0;
        };
    }
}

#endif //LUDVIG_MESHRENDERER_H
