//
// File created by Jesper on 8/7/2020.
//

#include "OpenGLShader.h"

#include "glad/glad.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            unsigned int OpenGLShader::create_shader(const char *vertexShaderCode, const char *fragmentShaderCode) {
                unsigned int program;

                unsigned int vertexShader;
                vertexShader = glCreateShader(GL_VERTEX_SHADER);
                glShaderSource(vertexShader, 1, &vertexShaderCode, nullptr);
                glCompileShader(vertexShader);

                unsigned int fragmentShader;
                vertexShader = glCreateShader(GL_VERTEX_SHADER);
                glShaderSource(fragmentShader, 1, &fragmentShaderCode, nullptr);
                glCompileShader(fragmentShader);

                program = glCreateProgram();
                glAttachShader(program,vertexShader);
                glAttachShader(program,fragmentShader);
                glLinkProgram(program);

                glDeleteShader(vertexShader);
                glDeleteShader(fragmentShader);

                this->program = program;

                return program;
            }

            void OpenGLShader::use() {
                glUseProgram(program);
            }
        }
    }
}