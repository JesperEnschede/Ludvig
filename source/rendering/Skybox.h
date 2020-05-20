//
// Created by Jesper on 5/20/2020.
//

#ifndef LUDVIG_SKYBOX_H
#define LUDVIG_SKYBOX_H

#include "glad/glad.h"

#include "vector"

namespace Ludvig
{
    namespace Rendering
    {
        class Skybox
        {
        public:
            Skybox(std::vector<const char*> facePaths);

        public:
            GLuint id;
        };
    }
}



#endif //LUDVIG_SKYBOX_H
