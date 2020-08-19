//
// File created by Jesper on 8/19/2020.
//

#include "GUIMeshInspector.h"

#include "DearImGui/imgui.h"

namespace Ludvig
{
    namespace GUI
    {
        GUIMeshInspector::GUIMeshInspector(Core::Mesh *mesh) {
            this->mesh = mesh;
        }

        void GUIMeshInspector::draw() {
            ImGui::Begin("Mesh inspector");

            ImGui::Text("Transform");
            ImGui::DragFloat3("position", (float*)&mesh->transform->position,0.01f);
            ImGui::DragFloat3("rotation", (float*)&mesh->transform->rotation,0.01f);
            ImGui::DragFloat3("scale", (float*)&mesh->transform->scale,0.01f);

            ImGui::End();
        }
    }
}