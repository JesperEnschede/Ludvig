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

            unsigned int get_color_buffer();

            unsigned int quadVAO; // vao for test :(

        private:
            unsigned int buffer;
            unsigned int colorBuffer;
            unsigned int renderBuffer;

            unsigned int quadVBO; // vbo for framebuffer testing only.
        };
    }
}



#endif //LUDVIG_FRAMEBUFFER_H
