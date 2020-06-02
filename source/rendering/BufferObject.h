//
// Created by Jesper on 5/29/2020.
//

#ifndef LUDVIG_BUFFEROBJECT_H
#define LUDVIG_BUFFEROBJECT_H

#include "glm.hpp"

#include "vector"

namespace Ludvig
{
    namespace Rendering
    {
        /*
         * A buffer object holds a buffer object.
         */
        class VertexBufferObject
        {
        public:
            VertexBufferObject(int dim,int index, const std::vector<glm::vec2>& data, int GL_BUFFER);
            VertexBufferObject(int dim,int index, const std::vector<glm::vec3>& data, int GL_BUFFER);
            VertexBufferObject(int dim,int index, const std::vector<unsigned int>& data, int GL_BUFFER);
            ~VertexBufferObject();

        private:
            unsigned int buffer;
        };
    }
}



#endif //LUDVIG_BUFFEROBJECT_H
