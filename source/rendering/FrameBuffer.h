//
// Created by Jesper on 5/29/2020.
//

#ifndef LUDVIG_FRAMEBUFFER_H
#define LUDVIG_FRAMEBUFFER_H

namespace Ludvig
{
    namespace Rendering
    {
        class FrameBuffer
        {
        public:
            FrameBuffer();
            ~FrameBuffer();

            void bind(unsigned int target);

        private:
            unsigned int buffer;
            unsigned int colorBuffer;
            unsigned int renderBuffer;
        };
    }
}



#endif //LUDVIG_FRAMEBUFFER_H
