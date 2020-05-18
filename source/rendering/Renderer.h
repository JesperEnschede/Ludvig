//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_RENDERER_H
#define LUDVIG_RENDERER_H

#include "../core/scene/Scene.h"
#include "../core/scene/Shader.h"
#include "../core/scene/Texture.h"

#include "glad/glad.h"
#include "Window.h"

#include "vector"

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
            Renderer(Window* window);

        public:
            void render_scene(Core::Scene::Scene* scene);
            void clear(int mask);

            void create_gui_frame();
            void draw_gui_frame();

        private:
            std::vector<std::unique_ptr<Core::Scene::Shader>> shaders;
            std::vector<std::unique_ptr<Core::Scene::Texture>> textures;
        };
    }
}



#endif //LUDVIG_RENDERER_H
