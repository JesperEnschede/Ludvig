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
            std::vector<std::unique_ptr<GUIWindow>> windows;
        };
    }
}

#endif //LUDVIG_GUIMANAGER_H
