//
// Created by Jesper on 6/3/2020.
//

#ifndef LUDVIG_GWMENUBAR_H
#define LUDVIG_GWMENUBAR_H

#include "../GUIWindow.h"
#include "../../rendering/Window.h"

#include "GWIncludes.h"

namespace Ludvig
{
    namespace Core
    {
        class GWMenuBar : public GUIWindow
        {
        public:
            GWMenuBar(GUIManager* manager,Rendering::Window* window)
            {
                this->manager = manager;
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
                                this->manager->get_window<GWMeshInspector>()->enabled = !this->manager->get_window<GWMeshInspector>()->enabled;
                            }
                            if (ImGui::MenuItem("Light"))
                            {
                                this->manager->get_window<GWLightInspector>()->enabled = !this->manager->get_window<GWLightInspector>()->enabled;
                            }
                            if (ImGui::MenuItem("Camera"))
                            {
                                this->manager->get_window<GWCameraInspector>()->enabled = !this->manager->get_window<GWCameraInspector>()->enabled;
                            }

                            ImGui::EndMenu();
                        }

                        if (ImGui::BeginMenu("Visual"))
                        {
                            if (ImGui::MenuItem("Post Processing"))
                            {
                                this->manager->get_window<GWPostProcessing>()->enabled = !this->manager->get_window<GWPostProcessing>()->enabled;
                            }

                            if (ImGui::MenuItem("Lighting"))
                            {
                                this->manager->get_window<GWLightSettingsInspector>()->enabled = !this->manager->get_window<GWLightSettingsInspector>()->enabled;
                            }

                            ImGui::EndMenu();
                        }

                        if (ImGui::BeginMenu("Debug"))
                        {
                            if (ImGui::MenuItem("Profiler"))
                            {
                                this->manager->get_window<GWProfiler>()->enabled = !this->manager->get_window<GWProfiler>()->enabled;
                            }

                            if (ImGui::MenuItem("Render debug view"))
                            {

                            }

                            if (ImGui::MenuItem("Console"))
                            {
                                this->manager->get_window<GWConsole>()->enabled = !this->manager->get_window<GWConsole>()->enabled;
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
            GUIManager* manager;
            Rendering::Window* window;
        };
    }
}

#endif //LUDVIG_GWMENUBAR_H
