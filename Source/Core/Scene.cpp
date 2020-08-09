//
// Created by Jesper on 5/11/2020.
//

#include "Scene.h"

namespace Ludvig
{
    namespace Core
    {
        Scene::Scene() {
            mesh = std::move(std::unique_ptr<Mesh>(create_mesh("assets/models/monkey.obj")));
            mesh->shader = "default";

            camera = std::make_unique<Camera>();
            light = std::make_unique<Light>();
        }
    }
}

