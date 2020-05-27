//
// Created by Jesper on 5/12/2020.
//

#ifndef LUDVIG_SHADER_H
#define LUDVIG_SHADER_H

#include "glad/glad.h"
#include "glm.hpp"

#include "string"

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
                Shader(std::string vertexPath, std::string fragmentPath);

                /*
                 * Destroys the shader program.
                 */
                ~Shader();

                /*
                 * Returns the shader program.
                 */
                GLuint get_program() const;

                /*
                 * Set a uniform matrix
                 */
                void set_mat4x4(const char* uniform, glm::mat4 matrix);

                /*
                 * Set a uniform vector 3.
                 */
                void set_vec3(const char* uniform, glm::vec3 vector);

                /*
                 * Set a uniform texture
                 */
                void set_texture(const char* uniform, GLuint id);

                /*
                 * Set a uniform float value.
                 */
                void set_float(const char* uniform, float value);

            public:
                /*
                 * Compile a GLSL shader.
                 */
                static GLuint compile(std::string vertexCode, std::string fragmentCode);

            private:
                GLuint program;
            };
        }
    }
}



#endif //LUDVIG_SHADER_H
