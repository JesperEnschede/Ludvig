//
// Created by Jesper on 5/11/2020.
//

#include "Scene.h"

namespace Ludvig
{
    namespace Core
    {
        Scene::Scene() {
            mesh = std::make_unique<Mesh>();
            camera = std::make_unique<Camera>();
            light = std::make_unique<Light>();
        }
    }
}

