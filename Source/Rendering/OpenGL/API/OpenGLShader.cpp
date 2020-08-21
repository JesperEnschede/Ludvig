//
// File created by Jesper on 8/7/2020.
//

#include "OpenGLShader.h"

#include "glad/glad.h"

#include "vector"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            unsigned int create_shader(const char *vertexShaderCode, const char *fragmentShaderCode) {
                unsigned int program;
                int success = 0;
                int infoLogLength = 0;

                unsigned int vertexShader;
                vertexShader = glCreateShader(GL_VERTEX_SHADER);
                glShaderSource(vertexShader, 1, &vertexShaderCode, nullptr);
                glCompileShader(vertexShader);

                glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&success);
                glGetShaderiv(vertexShader,GL_INFO_LOG_LENGTH,&infoLogLength);

                if (infoLogLength > 0) {
                    std::vector<char> shaderError(infoLogLength + 1);
                    glGetShaderInfoLog(vertexShader,infoLogLength,nullptr,&shaderError[0]);
                    std::printf("vertex shader error : \n%s\n",&shaderError[0]);
                }

                unsigned int fragmentShader;
                fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
                glShaderSource(fragmentShader, 1, &fragmentShaderCode, nullptr);
                glCompileShader(fragmentShader);

                glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&success);
                glGetShaderiv(fragmentShader,GL_INFO_LOG_LENGTH,&infoLogLength);

                if (infoLogLength > 0) {
                    std::vector<char> shaderError(infoLogLength + 1);
                    glGetShaderInfoLog(fragmentShader,infoLogLength,nullptr,&shaderError[0]);
                    std::printf("fragment shader error: \n%s\n",&shaderError[0]);
                }

                program = glCreateProgram();
                glAttachShader(program,vertexShader);
                glAttachShader(program,fragmentShader);
                glLinkProgram(program);

                glGetShaderiv(program,GL_LINK_STATUS,&success);
                glGetShaderiv(program,GL_INFO_LOG_LENGTH,&infoLogLength);

                if (infoLogLength > 0) {
                    std::vector<char> shaderError(infoLogLength + 1);
                    glGetShaderInfoLog(program,infoLogLength,nullptr,&shaderError[0]);
                    std::printf("shader program error: \n%s\n",&shaderError[0]);
                }

                glDeleteShader(vertexShader);
                glDeleteShader(fragmentShader);

                std::printf("Created ogl shader: %i \n", program);

                return program;
            }

            void set_uniform_mat4(unsigned int shaderProgram,const std::string& location, glm::mat4 matrix) {
                glUniformMatrix4fv(glGetUniformLocation(shaderProgram,location.c_str()), 1, GL_FALSE, &matrix[0][0]);
            }

            void set_uniform_int(unsigned int shaderProgram, const std::string &location, int value) {
                glUniform1i(glGetUniformLocation(shaderProgram,location.c_str()),value);
            }
        }
    }
}