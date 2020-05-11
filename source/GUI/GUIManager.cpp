//
// Created by Jesper on 5/11/2020.
//

#include "GUIManager.h"
#include "imgui.h"

Ludvig::GUI::GUIManager::GUIManager()
{

}

void Ludvig::GUI::GUIManager::draw_windows()
{
    for (int i = 0; i < this->windows.size(); ++i)
    {
        GUIWindow* window = this->windows[i].get();

        ImGui::Begin(window->windowName, nullptr,window->windowFlags);

        window->on_gui();

        ImGui::End();
    }
}
