//
// File created by Jesper on 7/13/2020.
//

#include "GUIManager.h"

#include "Windows/GUIMeshInspector.h"
#include "Windows/GUICameraInspector.h"

#include "DearImGui/imgui.h"

namespace Ludvig
{
    namespace GUI
    {
        GUIManager* GUIManager::instance;

        GUIManager::GUIManager(Core::Scene* scene) {
            instance = this;

            instance->windows.push_back(std::make_unique<GUIMeshInspector>(scene->mesh.get()));
            instance->windows.push_back(std::make_unique<GUICameraInspector>(scene->camera.get()));
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
