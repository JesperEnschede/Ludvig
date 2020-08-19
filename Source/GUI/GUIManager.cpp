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
            for (size_t i = 0; i < windows.size(); ++i) {
                if (windows[i]->isVisible)
                    windows[i].get()->draw();
            }
        }
    }
}
