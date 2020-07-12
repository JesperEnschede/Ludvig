//
// Created by Jesper on 5/12/2020.
//

#ifndef LUDVIG_MODELLOADER_H
#define LUDVIG_MODELLOADER_H

#include "glm.hpp"
#include "vector"

namespace Ludvig
{
    namespace Data
    {
        /*
         * Read a .OBJ model
         */
        void load_obj(const char* path, std::vector<glm::vec3>& out_vertices, std::vector<glm::vec2>& out_uvs, std::vector<glm::vec3>& out_normals);
    }
}

#endif //LUDVIG_MODELLOADER_H
