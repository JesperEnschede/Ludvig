//
// File created by Jesper on 7/13/2020.
//

#include "GUIManager.h"

#include "DearImGui/imgui.h"

namespace Ludvig
{
    namespace GUI
    {
        GUIManager* GUIManager::instance;

        GUIManager::GUIManager() {
            instance = this;
        }

        void GUIManager::draw_gui_windows() {
            instance->on_gui();
        }

        void GUIManager::on_gui() {
            ImGui::Begin("Profiler");
            ImGui::Text("ms/frame: %.3f", 1000.0f / ImGui::GetIO().Framerate);
            ImGui::Text("fps: %.3f",ImGui::GetIO().Framerate);
            ImGui::End();
        }
    }
}
