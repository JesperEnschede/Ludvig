//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_GUIWINDOW_H
#define LUDVIG_GUIWINDOW_H

#include "dearimgui/imgui.h"

#include "../core/Transform.h"

namespace Ludvig
{
    namespace Core
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

            static void draw_transform(Scene::Transform* transform)
            {
                ImGui::DragFloat3("Position", (float*)&transform->position,0.025);
                ImGui::DragFloat3("Rotation", (float*)&transform->rotation,0.025);
                ImGui::DragFloat3("Scale", (float*)&transform->scale,0.025);
            }

            bool enabled = true;
        };
    }
}

#endif //LUDVIG_GUIWINDOW_H
