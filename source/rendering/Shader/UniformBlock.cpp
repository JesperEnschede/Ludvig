//
// Created by Jesper on 6/7/2020.
//

#include "UniformBlock.h"

#include "glad/glad.h"

Ludvig::Rendering::UniformBlock::UniformBlock(unsigned int programID, const char *blockName)
{
    this->uniformBlockIndex = glGetUniformBlockIndex(programID, blockName);

    glUniformBlockBinding(programID, uniformBlockIndex, 0);
}
