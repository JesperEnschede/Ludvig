//
// Created by Jesper on 5/11/2020.
//

#include "GUIManager.h"
#include "imgui.h"

#include "windows/GWIncludes.h"

Ludvig::GUI::GUIManager::GUIManager()
{
    this->add_window<Windows::GWMenuBar>();
    this->add_window<Windows::GWProfiler>();
}

void Ludvig::GUI::GUIManager::draw_windows()
{
    for (int i = 0; i < this->windows.size(); ++i)
    {
        GUIWindow* window = this->windows[i].get();

        if (window->isStatic)
        {
            ImGui::SetNextWindowPos(ImVec2(window->x,window->y));
            ImGui::SetNextWindowSize(ImVec2(window->width, window->height));
        }

        ImGui::Begin(window->windowName, nullptr,window->windowFlags);

        window->on_gui();

        ImGui::End();
    }
}
