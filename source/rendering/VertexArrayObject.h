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
            VertexArrayObject();
            ~VertexArrayObject();

        public:
            /*
             * Bind the vao
             */
            void bind();

        private:
            unsigned int vao;
        };
    }
}



#endif //LUDVIG_VERTEXARRAYOBJECT_H
