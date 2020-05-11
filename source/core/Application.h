//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_APPLICATION_H
#define LUDVIG_APPLICATION_H

#include "../rendering/Renderer.h"
#include "../rendering/Window.h"
#include "../GUI/GUIManager.h"
#include "scene/Scene.h"

#include "memory"

namespace Ludvig
{
    namespace Core
    {
        /*
         * The application class is the main core class of the Ludvig rendering engine. is manages all the core instances. and does the main runtime loop.
         */
        class Application final
        {
        public:
            /*
             * Initialize default application components.
             */
            Application();

            /*
             * Starts the runtime loop if all core instances have successfully been initialized.
             */
            void start();

        private:
            /*
             * Main runtime loop.
             */
            void runtime();

        private:
            std::unique_ptr<Rendering::Window> window;
            std::unique_ptr<Rendering::Renderer> renderer;
            std::unique_ptr<Scene::Scene> scene;
            std::unique_ptr<GUI::GUIManager> guiManager;
        };
    }
}


#endif //LUDVIG_APPLICATION_H
