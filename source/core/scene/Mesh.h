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

#include "../../rendering/VertexArrayObject.h"
#include "../../rendering/Buffers/VertexBufferObject.h"

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
                Mesh(std::vector<glm::vec3> vertices);
                Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs);
                Mesh(std::vector<glm::vec3> vertices, std::vector<glm::vec2> uvs, std::vector<glm::vec3> normals);

                std::vector<unsigned int> get_mesh_indices();

                /*
                * Temp testing function.
                * Returns the size of the vertices vector.
                */
                int get_vertices_size();

                Rendering::VertexArrayObject* get_vao() const;

            private:
                std::vector<glm::vec3> vertices;
                std::vector<glm::vec2> uvs;
                std::vector<glm::vec3> normals;
                std::vector<unsigned int> indices = std::vector<unsigned int>();

                std::unique_ptr<Rendering::VertexArrayObject> vertexArrayObject;
                std::vector<std::unique_ptr<Rendering::VertexBufferObject>> buffers = std::vector<std::unique_ptr<Rendering::VertexBufferObject>>();
            };
        }
    }
}




#endif //LUDVIG_MESH_H
