//
// Created by Jesper on 5/14/2020.
//

#ifndef LUDVIG_VERTEXBUFFERINDEXER_H
#define LUDVIG_VERTEXBUFFERINDEXER_H

#include "glm.hpp"

#include "vector"
#include "map"
#include "string.h"

namespace Ludvig
{
    namespace Rendering
    {
        /*
         * Returns true if vertex1 & vertex2 are almost the same. (0.01f margin)
         */
        bool is_near(float vertex1, float vertex2);

        bool get_similar_vertex_index
        (
                glm::vec3 & in_vertex,glm::vec2 & in_uv,
                glm::vec3 & in_normal,std::vector<glm::vec3> & out_vertices,
                std::vector<glm::vec2> & out_uvs,
                std::vector<glm::vec3> & out_normals,unsigned short & result
        );

        void indexVBO_slow
        (
                std::vector<glm::vec3> & in_vertices,
                std::vector<glm::vec2> & in_uvs,
                std::vector<glm::vec3> & in_normals,

                std::vector<unsigned short> & out_indices,
                std::vector<glm::vec3> & out_vertices,
                std::vector<glm::vec2> & out_uvs,
                std::vector<glm::vec3> & out_normals
        );
    }
}

#endif //LUDVIG_VERTEXBUFFERINDEXER_H
