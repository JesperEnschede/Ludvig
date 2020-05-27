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
            /*
             * A texture holds the id of a image that the renderer can use to draw meshes with texture.
             */
            class Texture
            {
            public:
                /*
                 * Loads and creates a GL texture.
                 */
                Texture(const char* path);

                /*
                 * Deletes the texture
                 */
                ~Texture();

            public:
                GLuint id;

            protected:
                unsigned char* data;

                int width;
                int height;
                int channels;
            };
        }
    }
}



#endif //LUDVIG_TEXTURE_H
