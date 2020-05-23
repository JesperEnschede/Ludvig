//
// Created by Jesper on 5/23/2020.
//

#ifndef LUDVIG_GWCAMERAINSPECTOR_H
#define LUDVIG_GWCAMERAINSPECTOR_H

#include "GWObjectInspector.h"

#include "../../core/scene/Camera.h"

namespace Ludvig
{
    namespace Core
    {
        class GWCameraInspector : public GWObjectInspector
        {
        public:
            GWCameraInspector(Object *object) : GWObjectInspector(object)
            {
                this->camera = reinterpret_cast<Scene::Camera*>(object);
            }

            void on_gui() override
            {
                ImGui::Begin("Camera inspector");
                this->draw_transform(this->object->transform.get());
                ImGui::DragFloat("Field of view", &this->camera->fieldOfView,0.025,0.1,179);
                ImGui::DragFloat("Near clipping", &this->camera->nearClipping,0.025,0.1,179);
                ImGui::DragFloat("Far clipping", &this->camera->farClipping,0.025,0.1,179);
                ImGui::End();
            }

        private:
            Scene::Camera* camera;
        };
    }
}


#endif //LUDVIG_GWCAMERAINSPECTOR_H


