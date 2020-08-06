//
// Created by Jesper on 5/11/2020.
//

#include "Mesh.h"

#include "Data/ModelLoader.h"

namespace Ludvig
{
    namespace Core
    {
        Mesh* create_mesh(std::string path) {
            Mesh* mesh = new Mesh();

            Data::load_obj(path.c_str(), mesh->vertices, mesh->uvs, mesh->normals);

            return mesh;
        }
    }
}


