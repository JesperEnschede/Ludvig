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
        /*
         * A GUI window that can be attached to a GUIManager to be rendered to a window.
         * A constructor can be made to initialize member variables.
         */
        class GUIWindow
        {
        public:
            /*
             * Can be override to implement ImGui calls.
             */
            virtual void on_gui() = 0;

        public:
            const char* windowName;

            ImGuiWindowFlags windowFlags;

            int x = 5;
            int y = 5;

            int width = 10;
            int height = 10;

            bool isStatic = true;
        };
    }
}

#endif //LUDVIG_GUIWINDOW_H
