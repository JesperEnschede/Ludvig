//
// Created by Jesper on 5/23/2020.
//

#ifndef LUDVIG_LIGHTSETTINGS_H
#define LUDVIG_LIGHTSETTINGS_H

#include "glm.hpp"

namespace Ludvig
{
    namespace Rendering
    {
        /*
         * A container of light values for a certain scene.
         */
        class LightSettings
        {
        public:
            glm::vec3 ambientLightColor = glm::vec3(0.1f,0.1f,0.1f);

        private:
            // skybox
        };
    }
}



#endif //LUDVIG_LIGHTSETTINGS_H
