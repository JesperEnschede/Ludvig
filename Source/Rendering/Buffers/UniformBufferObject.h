//
// Created by Jesper on 6/7/2020.
//

#ifndef LUDVIG_UNIFORMBUFFEROBJECT_H
#define LUDVIG_UNIFORMBUFFEROBJECT_H

#include "glad/glad.h"

#include "cstdio"
#include "memory"

namespace Ludvig
{
    namespace Rendering
    {
        template <class TDataType>
        class UniformBufferObject
        {
        public:
            UniformBufferObject(unsigned int elements)
            {
                glGenBuffers(1,this->buffer);
                glBindBuffer(GL_UNIFORM_BUFFER, this->buffer);
                glBufferData(GL_UNIFORM_BUFFER, elements * sizeof(TDataType), nullptr, GL_STATIC_DRAW);

                glBindBuffer(GL_UNIFORM_BUFFER,0);

                glBindBufferRange(GL_UNIFORM_BUFFER,0,this->buffer, 0, elements * sizeof(TDataType));
            }

            void buffer_sub_data(void *data)
            {
                glBindBuffer(GL_UNIFORM_BUFFER, this->buffer);
                glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(TDataType), data);
                glBindBuffer(GL_UNIFORM_BUFFER,0);
            }

        private:
            unsigned int buffer;
        };
    }
}



#endif //LUDVIG_UNIFORMBUFFEROBJECT_H
