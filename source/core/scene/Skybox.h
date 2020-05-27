//
// Created by Jesper on 5/23/2020.
//

#ifndef LUDVIG_SKYBOX_H
#define LUDVIG_SKYBOX_H

#include "glad/glad.h"

#include "vector"

namespace Ludvig
{
    namespace Core
    {
        namespace Scene
        {
            class Skybox
            {
            public:
                Skybox();

                GLuint vbo;

            private:
                std::vector<float> vertices =
                        {
                                -1.0f,  1.0f, -1.0f,
                                -1.0f, -1.0f, -1.0f,
                                1.0f, -1.0f, -1.0f,
                                1.0f, -1.0f, -1.0f,
                                1.0f,  1.0f, -1.0f,
                                -1.0f,  1.0f, -1.0f,
                                -1.0f, -1.0f,  1.0f,
                                -1.0f, -1.0f, -1.0f,
                                -1.0f,  1.0f, -1.0f,
                                -1.0f,  1.0f, -1.0f,
                                -1.0f,  1.0f,  1.0f,
                                -1.0f, -1.0f,  1.0f,
                                1.0f, -1.0f, -1.0f,
                                1.0f, -1.0f,  1.0f,
                                1.0f,  1.0f,  1.0f,
                                1.0f,  1.0f,  1.0f,
                                1.0f,  1.0f, -1.0f,
                                1.0f, -1.0f, -1.0f,
                                -1.0f, -1.0f,  1.0f,
                                -1.0f,  1.0f,  1.0f,
                                1.0f,  1.0f,  1.0f,
                                1.0f,  1.0f,  1.0f,
                                1.0f, -1.0f,  1.0f,
                                -1.0f, -1.0f,  1.0f,
                                -1.0f,  1.0f, -1.0f,
                                1.0f,  1.0f, -1.0f,
                                1.0f,  1.0f,  1.0f,
                                1.0f,  1.0f,  1.0f,
                                -1.0f,  1.0f,  1.0f,
                                -1.0f,  1.0f, -1.0f,
                                -1.0f, -1.0f, -1.0f,
                                -1.0f, -1.0f,  1.0f,
                                1.0f, -1.0f, -1.0f,
                                1.0f, -1.0f, -1.0f,
                                -1.0f, -1.0f,  1.0f,
                                1.0f, -1.0f,  1.0f
                        };
            };
        }
    }
}



#endif //LUDVIG_SKYBOX_H
