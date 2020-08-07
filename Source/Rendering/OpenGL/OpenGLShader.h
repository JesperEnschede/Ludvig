//
// File created by Jesper on 8/7/2020.
//

#ifndef LUDVIG_OPENGLSHADER_H
#define LUDVIG_OPENGLSHADER_H

#include "Rendering/Shader.h"

#include "string"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            class OpenGLShader : public Shader
            {
            public:
                /*
                 * Creates a GLSL shader object with vertex & fragment shader code.
                 */
                unsigned int create_shader(const char* vertexShaderCode, const char* fragmentShaderCode);

                void use();

            private:
                unsigned int program;
            };
        }
    }
}

#endif //LUDVIG_OPENGLSHADER_H
