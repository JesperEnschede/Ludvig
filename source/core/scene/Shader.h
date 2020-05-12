//
// Created by Jesper on 5/12/2020.
//

#ifndef LUDVIG_SHADER_H
#define LUDVIG_SHADER_H

#include "glad/glad.h"
#include "glm.hpp"

namespace Ludvig
{
    namespace Core
    {
        namespace Scene
        {
            /*
             * A class containing a GLSL program.
             */
            class Shader
            {
            public:
                /*
                 * Read & compile the GLSL source.
                 */
                Shader(const char* vertexPath, const char* fragmentPath);

                /*
                 * Returns the shader program.
                 */
                GLuint get_program() const;

                void set_mat4x4(const char* uniform, glm::mat4 matrix);

            public:
                /*
                 * Compile a GLSL shader.
                 */
                static GLuint compile(const char* vertexCode, const char* fragmentCode);

            private:
                GLuint program;
            };
        }
    }
}



#endif //LUDVIG_SHADER_H
