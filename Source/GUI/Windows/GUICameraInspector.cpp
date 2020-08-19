//
// File created by Jesper on 8/19/2020.
//

#include "GUICameraInspector.h"

#include "DearImGui/imgui.h"

namespace Ludvig
{
    namespace GUI
    {
        GUICameraInspector::GUICameraInspector(Core::Camera *camera) {
            this->camera = camera;
        }

        void GUICameraInspector::draw() {
            ImGui::Begin("Camera inspector");

            ImGui::Text("Transform");
            ImGui::DragFloat3("position", (float*)&camera->transform->position,0.01f);
            ImGui::DragFloat3("rotation", (float*)&camera->transform->rotation,0.01f);
            ImGui::DragFloat3("scale", (float*)&camera->transform->scale,0.01f);

            ImGui::Text("Properties");
            ImGui::DragFloat("Near clipping", (float*)&camera->nearClipping, 0.01f);
            ImGui::DragFloat("Far clipping", (float*)&camera->farClipping, 0.01f);
            ImGui::DragFloat("Field of view (fov)", (float*)&camera->fieldOfView, 0.01f, 0.1f, 179.0f);

            ImGui::End();
        }
    }
}