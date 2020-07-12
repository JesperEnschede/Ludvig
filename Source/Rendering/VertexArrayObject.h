//
// Created by Jesper on 5/29/2020.
//

#ifndef LUDVIG_VERTEXARRAYOBJECT_H
#define LUDVIG_VERTEXARRAYOBJECT_H

namespace Ludvig
{
    namespace Rendering
    {
        /*
         * A Vertex Array Object holds a Mesh's vao data.
         */
        class VertexArrayObject
        {
        public:
            /*
             * Generates and binds a new vertex array object.
             */
            VertexArrayObject();

            /*
             * Deletes the vertex array object.
             */
            ~VertexArrayObject();

        public:
            /*
             * Bind the vertex array object.
             */
            void bind();

        private:
            unsigned int vao;
        };
    }
}



#endif //LUDVIG_VERTEXARRAYOBJECT_H
