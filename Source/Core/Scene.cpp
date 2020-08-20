//
// Created by Jesper on 5/11/2020.
//

#include "Scene.h"

#include "Data/UserConfig.h"

namespace Ludvig
{
    namespace Core
    {
        Scene::Scene() {
            mesh = std::move(std::unique_ptr<Mesh>(create_mesh(Data::UserConfig::get_string("MODEL"))));
            mesh->shader = Data::UserConfig::get_string("SHADER");
            mesh->texture = Data::UserConfig::get_string("TEXTURE");

            camera = std::make_unique<Camera>();
            light = std::make_unique<Light>();
        }
    }
}

