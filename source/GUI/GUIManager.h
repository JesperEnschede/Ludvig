//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_GUIMANAGER_H
#define LUDVIG_GUIMANAGER_H

#include "GUIWindow.h"

#include "memory"
#include "vector"

namespace Ludvig
{
    namespace GUI
    {
        class GUIManager
        {
        public:
            GUIManager();

        public:
            void draw_windows();

        private:
            template <class T>
            void add_window();

        private:
            std::vector<std::unique_ptr<GUIWindow>> windows;
        };

        template <class T>
        inline void GUIManager::add_window()
        {
            this->windows.push_back(std::make_unique<T>());
        }
    }
}

#endif //LUDVIG_GUIMANAGER_H
