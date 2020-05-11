//
// Created by Jesper on 5/11/2020.
//

#include "GWProfiler.h"

Ludvig::GUI::Windows::GWProfiler::GWProfiler()
{
    this->windowName = "Profiler";

    this->x = 25;
    this->y = 25;

    this->width = 250;
    this->height = 250;

    this->windowFlags |= ImGuiWindowFlags_NoCollapse;

    this->isStatic = false;
}

void Ludvig::GUI::Windows::GWProfiler::on_gui()
{
    ImGui::Text("%.3f ms/frame | %.3f FPS", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);

    this->frame_times[5] = ImGui::GetIO().Framerate;
    ImGui::PlotLines("frame: ", this->frame_times, IM_ARRAYSIZE(this->frame_times));
    this->frame_times[4] = this->frame_times[5];
    this->frame_times[3] = this->frame_times[4];
    this->frame_times[2] = this->frame_times[3];
    this->frame_times[1] = this->frame_times[2];
    this->frame_times[0] = this->frame_times[1];
}
