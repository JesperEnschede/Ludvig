//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_APPLICATION_H
#define LUDVIG_APPLICATION_H

#include "Rendering/RenderManager.h"
#include "Rendering/Window.h"

#include "GUI/GUIManager.h"

#include "Scene.h"

#include "memory"

namespace Ludvig
{
    namespace Core
    {
        class GUIManager;

        /*
         * The application class is the main core class of the Ludvig rendering engine. is manages all the core instances. and does the main runtime loop.
         */
        class Application final
        {
            friend GUIManager;

        public:
            /*
             * Initialize default application components.
             */
            Application();

            /*
             * Starts the application runtime loop.
             */
            void start();

        private:
            /*
             * Main runtime loop.
             */
            void runtime();

        private:
            std::string version = "v0.2.1";
            bool isRunning = false;

            std::unique_ptr<Rendering::Window> window;
            std::unique_ptr<Rendering::RenderManager> renderManager;
            std::unique_ptr<Core::Scene> scene;
            std::shared_ptr<GUI::GUIManager> guiManager;
        };
    }
}

#endif //LUDVIG_APPLICATION_H
