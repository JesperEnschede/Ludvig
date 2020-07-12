//
// Created by Jesper on 5/29/2020.
//

#ifndef LUDVIG_VERTEXBUFFEROBJECT_H
#define LUDVIG_VERTEXBUFFEROBJECT_H

#include "glm.hpp"

#include "vector"

namespace Ludvig
{
    namespace Rendering
    {
        /*
         * The vertexbufferobject class can generate glbuffers.
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



#endif //LUDVIG_VERTEXBUFFEROBJECT_H
