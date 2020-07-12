//
// Created by Jesper on 5/29/2020.
//

#include "VertexArrayObject.h"

#include "glad/glad.h"

namespace Ludvig
{
    namespace Rendering
    {
        VertexArrayObject::VertexArrayObject()
        {
            glGenVertexArrays(1,&this->vao);
            glBindVertexArray(this->vao);
        }

        VertexArrayObject::~VertexArrayObject()
        {
            glDeleteVertexArrays(1,&this->vao);
        }

        void VertexArrayObject::bind()
        {
            glBindVertexArray(this->vao);
        }
    }
}
