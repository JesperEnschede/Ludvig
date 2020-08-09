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
            unsigned int create_shader(const char* vertexShaderCode, const char* fragmentShaderCode);
        }
    }
}

#endif //LUDVIG_OPENGLSHADER_H
