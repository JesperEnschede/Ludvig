//
// File created by Jesper on 8/7/2020.
//
#ifndef LUDVIG_SHADER_H
#define LUDVIG_SHADER_H

#include "string"

namespace Ludvig
{
    namespace Rendering
    {
        /*
         * The Shader data struct is used to store
         * file paths of shaders, The RenderManager is then
         * responsible for creating API specific shaders programs.
         * A shader is owned by a RenderManager.
         */
        struct Shader
        {
            /*
             * TODO(Jesper) Add support for more shader types.
             * Would be cool to add support for stuff like
             * geometry, compute or other shaders :)
             */

            Shader(std::string vertexFilePath, std::string fragmentFilePath);

            std::string vertexFilePath;
            std::string fragmentFilePath;
        };
    }
}

#endif //LUDVIG_SHADER_H
