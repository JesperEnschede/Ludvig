//
// Created by Jesper on 5/18/2020.
//

#ifndef LUDVIG_TEXTURE_H
#define LUDVIG_TEXTURE_H

#include "glad/glad.h"

namespace Ludvig
{
    namespace Core
    {
        namespace Scene
        {
            class Texture
            {
            public:
                Texture(const char* path);

            public:
                GLuint id;

            private:
                unsigned char* data;

                int width;
                int height;
                int channels;
            };
        }
    }
}



#endif //LUDVIG_TEXTURE_H
