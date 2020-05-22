//
// Created by Jesper on 5/22/2020.
//

#include "GWProfiler.h"

void Ludvig::GUI::Windows::GWProfiler::on_gui()
{
    ImGui::Begin("Profiler");
    ImGui::Text("%.3f ms/frame | %.3f FPS", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
    ImGui::End();
}
