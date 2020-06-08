//
// Created by Jesper on 6/1/2020.
//

#ifndef LUDVIG_MATERIAL_H
#define LUDVIG_MATERIAL_H

#include "Texture.h"

namespace Ludvig
{
    namespace Rendering
    {
        struct Material
        {
        public:
            Core::Scene::Texture diffuse;
            Core::Scene::Texture specular;
            float shininess = 32.0f;
        };
    }
}



#endif //LUDVIG_MATERIAL_H
