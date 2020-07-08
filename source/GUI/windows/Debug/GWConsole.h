//
// Created by Jesper on 6/6/2020.
//

#ifndef LUDVIG_GWCONSOLE_H
#define LUDVIG_GWCONSOLE_H

#include "GUI/GUIWindow.h"

#include "debug/DebugLog.h"

namespace Ludvig
{
    namespace Core
    {
        class GWConsole : public GUIWindow
        {
        public:
            GWConsole()
            {
                this->enabled = false;
            }

            void on_gui() override
            {
                ImGui::Begin("Console");
                ImGui::Text(Debug::DebugLog::get_log().c_str());
                ImGui::End();
            }
        };
    }
}

#endif //LUDVIG_GWCONSOLE_H
