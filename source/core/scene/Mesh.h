//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_MESH_H
#define LUDVIG_MESH_H

#include "glad/glad.h"

#include "vector"

namespace Ludvig
{
    namespace Core
    {
        namespace Scene
        {
            /*
             * A mesh is an object in a 3D space.
             */
            class Mesh
            {
            public:
                Mesh();
                Mesh(std::vector<GLfloat> vertices, std::vector<GLfloat> uvs, std::vector<GLfloat> normals);

            public:
                GLuint vao;
                GLuint vbo;
                GLuint ubo;
                GLuint ebo;
                unsigned int indices;

            private:
                /*
                 * Generate a vertex array object: this->vao;
                 */
                void generate_vertex_array();

                /*
                 * Generate a vertex buffer object: this->vbo;
                 */
                void generate_vertex_buffer();

                /*
                 * Generate a uv buffer object: this-> ubo;
                 */
                void generate_uv_buffer();

                /*
                 * Generate a element buffer object: this->ebo;
                 * WARNING: CURRENTLY NOT IMPLEMENTED.
                 */
                void generate_element_buffer();

            private:
                std::vector<GLfloat> vertices = std::vector<GLfloat>();
                std::vector<GLfloat> uvs = std::vector<GLfloat>();
                std::vector<GLfloat> normals = std::vector<GLfloat>();
            };
        }
    }
}




#endif //LUDVIG_MESH_H
