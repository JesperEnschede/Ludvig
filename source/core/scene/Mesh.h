//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_MESH_H
#define LUDVIG_MESH_H

#include "glad/glad.h"

#include "../Object.h"

#include "../../rendering/Shader.h"
#include "../Transform.h"

#include "glm.hpp"

#include "vector"
#include "memory"

namespace Ludvig
{
    namespace Core
    {
        namespace Scene
        {
            /*
             * A mesh is an object in a 3D space.
             */
            class Mesh : public Object
            {
            public:
                Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals);

                /*
                 * Destroys all buffer objects & the vertex array object.
                 */
                ~Mesh();

                std::vector<unsigned int> get_mesh_indices();

                /*
                * Temp testing function.
                * Returns the size of the vertices vector.
                */
                int get_vertices_size()
                {
                    return this->vertices.size();
                }

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
                 * Generate a normal buffer object: this->nbo;
                 */
                void generate_normal_buffer();

                /*
                 * Generate a uv buffer object: this-> ubo;
                 */
                void generate_uv_buffer();

                /*
                 * Generate a element buffer object: this->ebo;
                 */
                void generate_element_buffer();

            public:
                GLuint vao; // vertex array

                GLuint vbo; // vertex buffer
                GLuint ubo; // uv buffer
                GLuint nbo; // normal buffer
                GLuint ebo; // element buffer

            private:
                std::vector<glm::vec3> vertices;
                std::vector<glm::vec2> uvs;
                std::vector<glm::vec3> normals;
                std::vector<unsigned int> indices = std::vector<unsigned int>();
            };
        }
    }
}




#endif //LUDVIG_MESH_H
