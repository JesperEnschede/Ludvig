//
// Created by Jesper on 6/3/2020.
//

#ifndef LUDVIG_GWPOSTPROCESSING_H
#define LUDVIG_GWPOSTPROCESSING_H

#include "../../GUIWindow.h"

namespace Ludvig
{
    namespace Core
    {
        class GWPostProcessing : public GUIWindow
        {
        public:
            GWPostProcessing()
            {
                this->enabled = false;
            }

            void on_gui() override
            {
                ImGui::Begin("Post processing editor");
                ImGui::End();
            }
        };
    }
}

#endif //LUDVIG_GWPOSTPROCESSING_H
