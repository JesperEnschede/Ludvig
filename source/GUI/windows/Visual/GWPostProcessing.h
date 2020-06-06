//
// Created by Jesper on 6/3/2020.
//

#ifndef LUDVIG_GWPOSTPROCESSING_H
#define LUDVIG_GWPOSTPROCESSING_H

#include "../../GUIWindow.h"

#include "../../../core/scene/PostProcessingVolume.h"

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

                ImGui::Checkbox("Kernel", &postProcessingVolume->enable_kernel);
                if (postProcessingVolume->enable_kernel)
                {
                    ImGui::DragFloat3("Kernel row 1", kernelRow1, 0.01);
                    ImGui::DragFloat3("Kernel row 2", kernelRow2, 0.01);
                    ImGui::DragFloat3("Kernel row 3", kernelRow3, 0.01);

                    this->postProcessingVolume->kernel[0] = kernelRow1[0];
                    this->postProcessingVolume->kernel[1] = kernelRow1[1];
                    this->postProcessingVolume->kernel[2] = kernelRow1[2];
                    this->postProcessingVolume->kernel[3] = kernelRow2[0];
                    this->postProcessingVolume->kernel[4] = kernelRow2[1];
                    this->postProcessingVolume->kernel[5] = kernelRow2[2];
                    this->postProcessingVolume->kernel[6] = kernelRow3[0];
                    this->postProcessingVolume->kernel[7] = kernelRow3[1];
                    this->postProcessingVolume->kernel[8] = kernelRow3[2];
                }

                ImGui::Checkbox("Grayscale", &postProcessingVolume->enable_colorShift);
                if (postProcessingVolume->enable_colorShift)
                {
                    ImGui::DragFloat3("Grayscale shift", (float*)&postProcessingVolume->colorShift, 0.01f, 0.0f);
                }

                ImGui::Checkbox("Inverse", &postProcessingVolume->enable_invert);
                if (postProcessingVolume->enable_invert)
                {

                }


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
