//
// File created by Jesper on 8/6/2020.
//

#ifndef LUDVIG_RENDERCONTEXT_H
#define LUDVIG_RENDERCONTEXT_H

namespace Ludvig
{
    namespace Rendering
    {
        /*
         * The RenderContext class must be overridden to define API specific behaviour to:
         * prepare the frame and draw (finish) the frame to the screen.
         *
         * The RenderContext is owned by a RenderManager.
         */
        class RenderContext
        {
        public:
            virtual void prepare_frame() = 0;

            virtual void finish_frame() = 0;
        };
    }
}

#endif //LUDVIG_RENDERCONTEXT_H
