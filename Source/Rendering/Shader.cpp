//
// File created by Jesper on 8/7/2020.
//

#include "Shader.h"

namespace Ludvig
{
    namespace Rendering
    {
        Shader::Shader(std::string vertexFilePath, std::string fragmentFilePath) {
            this->vertexFilePath = vertexFilePath;
            this->fragmentFilePath = fragmentFilePath;
        }
    }
}