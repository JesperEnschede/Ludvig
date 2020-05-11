//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_GUIWINDOW_H
#define LUDVIG_GUIWINDOW_H

#include "imgui.h"

namespace Ludvig
{
    namespace GUI
    {
        class GUIWindow
        {
        public:
            virtual void on_gui() = 0;

        public:
            const char* windowName;

            ImGuiWindowFlags windowFlags;
        };
    }
}

#endif //LUDVIG_GUIWINDOW_H
