//
// File created by Jesper on 8/20/2020.
//

#include "GUIConsole.h"

#include "Debug/DebugLog.h"

#include "DearImGui/imgui.h"

namespace Ludvig
{
    namespace GUI
    {
        void GUIConsole::draw()
        {
            ImGui::Begin("Console");
            ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
            ImGui::Text("%s", Debug::DebugLog::get_log().c_str());
            ImGui::End();
        }
    }
}

