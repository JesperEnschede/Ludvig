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
                void generate_vertex_array();
                void generate_vertex_buffer();
                void generate_uv_buffer();
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
