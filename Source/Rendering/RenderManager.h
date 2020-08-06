//
// File created by Jesper on 8/6/2020.
//

#ifndef LUDVIG_RENDERMANAGER_H
#define LUDVIG_RENDERMANAGER_H

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
            virtual void render() = 0;
        };
    }
}



#endif //LUDVIG_RENDERMANAGER_H