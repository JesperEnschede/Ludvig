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
    /*
     * A cubemap is a 6-sided texture that you can use as a skybox.
     */
    namespace Rendering
    {
        class Cubemap
        {
        public:
            /*
             * Load and bind the cubemap
             */
            Cubemap(std::vector<const char*> faces);

            /*
             * Destroys the cubemap texture.
             */
            ~Cubemap();

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
