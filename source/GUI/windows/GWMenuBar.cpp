//
// Created by Jesper on 5/11/2020.
//

#include "GWMenuBar.h"

Ludvig::GUI::Windows::GWMenuBar::GWMenuBar()
{
    this->windowName = "MenuBar";

    this->x = 0;
    this->y = 0;

    this->width = 1920;
    this->height = 10;

    this->windowFlags |= ImGuiWindowFlags_NoTitleBar;
    this->windowFlags |= ImGuiWindowFlags_MenuBar;
    this->windowFlags |= ImGuiWindowFlags_NoMove;
    this->windowFlags |= ImGuiWindowFlags_NoResize;
    this->windowFlags |= ImGuiWindowFlags_NoCollapse;
    this->windowFlags |= ImGuiWindowFlags_NoBringToFrontOnFocus;
    this->windowFlags |= ImGuiWindowFlags_NoBackground;
}

void Ludvig::GUI::Windows::GWMenuBar::on_gui()
{
    if (ImGui::BeginMenuBar())
    {
        ImGui::EndMenuBar();
    }
}
