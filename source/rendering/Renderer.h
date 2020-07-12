//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_RENDERER_H
#define LUDVIG_RENDERER_H

#include "core/Scene.h"
#include "Shader.h"
#include "Texture.h"
#include "Cubemap.h"
#include "Buffers/FrameBuffer.h"

#include "glad/glad.h"
#include "Window.h"

#include "vector"
#include "memory"

namespace Ludvig
{
    namespace Rendering
    {
        /*
         * Renderer contains all openGL rendering functions.
         */
        class Renderer
        {
        public:
            /*
             * Loads openGL.
             */
            Renderer(Window* window);

        public:
            /*
             * Render a scene
             */
            void render_scene(Core::Scene::Scene* scene);

            /*
             * Clear the screen
             */
            void clear(int mask);

            /*
             * Create a DearImGui frame.
             */
            void create_gui_frame();

            /*
             * Draw every ImGui draw call
             */
            void draw_gui_frame();

        private:
            std::vector<std::unique_ptr<Core::Scene::Shader>> shaders;
            std::vector<std::unique_ptr<Core::Scene::Texture>> textures;
            std::vector<std::unique_ptr<Cubemap>> cubeMaps;

            std::unique_ptr<FrameBuffer> frameBuffer;
        };
    }
}



#endif //LUDVIG_RENDERER_H
