//
// Created by Jesper on 5/23/2020.
//

#ifndef LUDVIG_GWLIGHTSETTINGSINSPECTOR_H
#define LUDVIG_GWLIGHTSETTINGSINSPECTOR_H

#include "../Objects/GWObjectInspector.h"

#include "../../../rendering/LightSettings.h"

namespace Ludvig
{
    namespace Core
    {
        class GWLightSettingsInspector : public GUIWindow
        {
        public:
            GWLightSettingsInspector(Rendering::LightSettings* lightSettings)
            {
                this->lightSettings = lightSettings;

                this->enabled = false;
            }

            void on_gui() override
            {
                ImGui::Begin("Light settings inspector");
                ImGui::ColorEdit3("Ambient light color", (float*)&this->lightSettings->ambientLightColor);
                ImGui::DragFloat("Ambient light intensity", (float*)&this->lightSettings->intensity, 0.025f, 0.0f);
                ImGui::End();
            }

        private:
            Rendering::LightSettings* lightSettings;
        };
    }
}


#endif //LUDVIG_GWLIGHTSETTINGSINSPECTOR_H
