//
// File created by Jesper on 8/7/2020.
//

#include "OpenGLVertexArray.h"

#include "glad/glad.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            unsigned int create_vertex_array() {
                unsigned int vao;

                glGenVertexArrays(1,&vao);
                glBindVertexArray(vao);

                return vao ;
            }
        }
    }
}