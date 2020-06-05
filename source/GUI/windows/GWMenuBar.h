//
// Created by Jesper on 6/3/2020.
//

#ifndef LUDVIG_GWMENUBAR_H
#define LUDVIG_GWMENUBAR_H

#include "../GUIWindow.h"
#include "../../rendering/Window.h"

namespace Ludvig
{
    namespace Core
    {
        class GWMenuBar : public GUIWindow
        {
        public:
            GWMenuBar(Rendering::Window* window)
            {
                this->window = window;
            }

            void on_gui() override
            {
                ImGui::SetNextWindowPos(ImVec2(0,0));
                ImGui::SetNextWindowSize(ImVec2(window->get_width(), 0));

                ImGui::Begin("MenuBar", NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar| ImGuiWindowFlags_MenuBar);

                if (ImGui::BeginMenuBar())
                {
                    if (ImGui::BeginMenu("File"))
                    {
                        if (ImGui::MenuItem("Import model"))
                        {
                            
                        }

                        if (ImGui::MenuItem("Exit"))
                        {

                        }

                        ImGui::EndMenu();
                    }

                    if (ImGui::BeginMenu("Window"))
                    {
                        if (ImGui::BeginMenu("Objects"))
                        {
                            if (ImGui::MenuItem("Mesh"))
                            {

                            }
                            if (ImGui::MenuItem("Light"))
                            {

                            }
                            if (ImGui::MenuItem("Camera"))
                            {

                            }

                            ImGui::EndMenu();
                        }

                        if (ImGui::BeginMenu("Visual"))
                        {
                            if (ImGui::MenuItem("Post Processing"))
                            {

                            }

                            if (ImGui::MenuItem("Lighting"))
                            {

                            }

                            ImGui::EndMenu();
                        }

                        if (ImGui::BeginMenu("Debug"))
                        {
                            if (ImGui::MenuItem("Profiler"))
                            {

                            }

                            if (ImGui::MenuItem("Render debug view"))
                            {

                            }

                            if (ImGui::MenuItem("Console"))
                            {

                            }

                            ImGui::EndMenu();
                        }

                        ImGui::EndMenu();
                    }

                    if (ImGui::BeginMenu("Help"))
                    {
                        if (ImGui::MenuItem("Build info"))
                        {

                        }

                        if (ImGui::MenuItem("Licenses"))
                        {

                        }

                        if (ImGui::MenuItem("About Ludvig"))
                        {

                        }

                        ImGui::EndMenu();
                    }


                    ImGui::EndMenuBar();
                }

                ImGui::End();
            }

        private:
            Rendering::Window* window;
        };
    }
}

#endif //LUDVIG_GWMENUBAR_H
