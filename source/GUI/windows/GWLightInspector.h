//
// Created by Jesper on 5/23/2020.
//

#ifndef LUDVIG_GWLIGHTINSPECTOR_H
#define LUDVIG_GWLIGHTINSPECTOR_H

#include "GWObjectInspector.h"

#include "../../core/scene/Light.h"

namespace Ludvig
{
    namespace Core
    {
        class GWLightInspector : public GWObjectInspector
        {
        public:
            GWLightInspector(Object* object) : GWObjectInspector(object)
            {
                this->light = reinterpret_cast<Scene::Light*>(object);
            }

            void on_gui() override
            {
                ImGui::Begin(object->name);
                this->draw_transform(this->object->transform.get());
                ImGui::ColorEdit3("Color", (float*)&this->light->color);
                ImGui::DragFloat("Intensity", &this->light->intensity,0.025,0.1,INT_MAX);
                ImGui::End();
            }

        private:
            Scene::Light* light;
        };
    }
}



#endif //LUDVIG_GWLIGHTINSPECTOR_H
