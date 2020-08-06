//
// File created by Jesper on 8/6/2020.
//

#include "OpenGLBuffer.h"

#include "glad/glad.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            unsigned int create_buffer(int target,void* data,size_t size, int usage) {
                unsigned int buffer;

                glGenBuffers(1,&buffer);
                glBindBuffer(target, buffer);
                glBufferData(target, size, data, usage);

                return buffer;
            }
        }
    }
}