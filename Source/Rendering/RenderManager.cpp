//
// File created by Jesper on 8/6/2020.
//

#include "RenderManager.h"

namespace Ludvig
{
    namespace Rendering
    {
        void RenderManager::set_active_camera(Core::Camera *camera) {
            this->camera = camera;
        }
    }
}