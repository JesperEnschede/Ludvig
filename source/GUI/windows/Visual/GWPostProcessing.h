//
// Created by Jesper on 6/3/2020.
//

#ifndef LUDVIG_GWPOSTPROCESSING_H
#define LUDVIG_GWPOSTPROCESSING_H

#include "GUI/GUIWindow.h"

#include "core/scene/PostProcessingVolume.h"

namespace Ludvig
{
    namespace Core
    {
        class GWPostProcessing : public GUIWindow
        {
        public:
            GWPostProcessing(Scene::PostProcessingVolume* postProcessingVolume)
            {
                this->enabled = false;

                this->postProcessingVolume = postProcessingVolume;
            }

            void on_gui() override
            {
                ImGui::Begin("Post processing editor");

                ImGui::Checkbox("Blur", &postProcessingVolume->enable_kernel);

                ImGui::Checkbox("Grayscale", &postProcessingVolume->enable_colorShift);
                if (postProcessingVolume->enable_colorShift)
                {
                    ImGui::DragFloat3("Grayscale shift", (float*)&postProcessingVolume->colorShift, 0.01f, 0.0f);
                }

                ImGui::Checkbox("Inverse", &postProcessingVolume->enable_invert);

                ImGui::End();
            }

        private:
            Scene::PostProcessingVolume* postProcessingVolume;

            float kernelRow1[3] = { 0,0,0 };
            float kernelRow2[3] = { 0,0,0 };
            float kernelRow3[3] = { 0,0,0 };
        };
    }
}

#endif //LUDVIG_GWPOSTPROCESSING_H
