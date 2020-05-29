//
// Created by Jesper on 5/29/2020.
//

#ifndef LUDVIG_BUFFEROBJECT_H
#define LUDVIG_BUFFEROBJECT_H

#include "vector"

namespace Ludvig
{
    namespace Rendering
    {
        /*
         * A buffer object holds openGL buffer data.
         */
        class BufferObject
        {
        public:
            BufferObject(int dim, const std::vector<float>& data);
            ~BufferObject();

        private:
            unsigned int buffer;
        };
    }
}



#endif //LUDVIG_BUFFEROBJECT_H
