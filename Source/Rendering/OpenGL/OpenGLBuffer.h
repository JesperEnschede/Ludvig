//
// File created by Jesper on 8/6/2020.
//

#ifndef LUDVIG_OPENGLBUFFER_H
#define LUDVIG_OPENGLBUFFER_H

#include "crtdefs.h" // for size_t

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            /*
             * Creates and returns a opengl buffer object
             */
            unsigned int create_buffer(int target,void* data,size_t size, int usage);
        }
    }
}

#endif //LUDVIG_OPENGLBUFFER_H
