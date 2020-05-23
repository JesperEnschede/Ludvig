//
// Created by Jesper on 5/23/2020.
//

#ifndef LUDVIG_CUBEMAP_H
#define LUDVIG_CUBEMAP_H

#include "Texture.h"

#include "stb_image.h"

#include "vector"

namespace Ludvig
{
    namespace Rendering
    {
        class Cubemap
        {
        public:
            Cubemap(std::vector<const char*> faces);

        public:
            GLuint id;

        private:
            const char* data;

            int width;
            int height;
            int channels;
        };
    }
}



#endif //LUDVIG_CUBEMAP_H
