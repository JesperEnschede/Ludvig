//
// File created by Jesper on 8/7/2020.
//

#include "OpenGLVertexAttrib.h"

#include "glad/glad.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            void vertex_attrib_ptr(int index, int dim) {
                glVertexAttribPointer(index, dim, GL_FLOAT, GL_FALSE, 0,nullptr);
                glEnableVertexAttribArray(index);
            }
        }
    }
}