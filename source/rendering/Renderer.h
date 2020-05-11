//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_RENDERER_H
#define LUDVIG_RENDERER_H

#include "../core/scene/Scene.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Ludvig
{
    namespace Rendering
    {
        class Renderer
        {
        public:
            /*
             * Loads openGL.
             */
            Renderer();

        public:
            void render_scene(Core::Scene::Scene* scene);

            void create_gui_frame();
            void draw_gui_frame();
        };
    }
}



#endif //LUDVIG_RENDERER_H
