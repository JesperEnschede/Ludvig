//
// File created by Jesper on 8/6/2020.
//

#ifndef LUDVIG_MESHRENDERER_H
#define LUDVIG_MESHRENDERER_H

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
            virtual void render() = 0;
        };
    }
}

#endif //LUDVIG_MESHRENDERER_H
