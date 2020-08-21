//
// File created by Jesper on 8/7/2020.
//

#ifndef LUDVIG_OPENGLSHADER_H
#define LUDVIG_OPENGLSHADER_H

#include "Rendering/Shader.h"

#include "glm.hpp"

#include "string"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            unsigned int create_shader(const char* vertexShaderCode, const char* fragmentShaderCode);

            /*
             * Sets a uniform mat4 value in a shader program.
             */
            void set_uniform_mat4(unsigned int shaderProgram,const std::string& location, glm::mat4 matrix);

            /*
             * Sets a uniform interger value in a shader program.
             */
            void set_uniform_int(unsigned int shaderProgram, const std::string& location, int value);
        }
    }
}

#endif //LUDVIG_OPENGLSHADER_H
