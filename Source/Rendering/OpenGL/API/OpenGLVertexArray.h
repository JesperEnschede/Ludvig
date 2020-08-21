//
// File created by Jesper on 8/7/2020.
//

#ifndef LUDVIG_OPENGLVERTEXARRAY_H
#define LUDVIG_OPENGLVERTEXARRAY_H

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            /*
             * Creates, bind and returns a vertex array object.
             */
            unsigned int create_vertex_array();

            /*
             * Binds a vertex array
             */
            void bind_vertex_array(unsigned int vao);
        }
    }
}

#endif //LUDVIG_OPENGLVERTEXARRAY_H
