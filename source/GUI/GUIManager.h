//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_GUIMANAGER_H
#define LUDVIG_GUIMANAGER_H

#include "../core/Application.h"

#include "GUIWindow.h"

#include "dearimgui/imgui.h"

#include "memory"
#include "vector"

namespace Ludvig
{
    namespace Core
    {
        class Application;

        /*
         * The gui manager handles all the GUI windows.
         */
        class GUIManager
        {
            friend Application;

        public:
            /*
             * Initialize GUI windows.
             */
            GUIManager(Application *app);

        public:
            /*
             * Draws all the GUI windows.
             */
            void draw_windows();

            template <class T>
            GUIWindow* get_window();

        private:
            /*
             * Add a new window of type T.
             */
            template <class T>
            void add_window();

            void set_gui_style();

        private:
            Application* application;

            std::vector<std::unique_ptr<GUIWindow>> windows;
        };

        template <class T>
        inline void GUIManager::add_window()
        {
            this->windows.push_back(std::make_unique<T>());
        }

        template <class T>
        inline GUIWindow* GUIManager::get_window()
        {
            if (!std::is_base_of<GUIWindow, T>())
            {
                return nullptr;
            }

            for (int i = 0; i < windows.size(); i++)
            {
                if (dynamic_cast<T*>(windows[i].get()) != nullptr)
                {
                    return dynamic_cast<T*>(windows[i].get());
                }
            }

            return nullptr;
        }
    }
}

#endif //LUDVIG_GUIMANAGER_H
