//
// Created by Jesper on 6/7/2020.
//

#include "UniformBlock.h"

#include "glad/glad.h"

namespace Ludvig
{
    namespace Rendering
    {
        UniformBlock::UniformBlock(unsigned int programID, const char *blockName)
        {
            this->uniformBlockIndex = glGetUniformBlockIndex(programID, blockName);

            glUniformBlockBinding(programID, uniformBlockIndex, 0);
        }
    }
}

