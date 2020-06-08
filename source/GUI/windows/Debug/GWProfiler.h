//
// Created by Jesper on 5/22/2020.
//

#ifndef LUDVIG_GWPROFILER_H
#define LUDVIG_GWPROFILER_H

#include "../../GUIWindow.h"

#include "imgui.h"

namespace Ludvig
{
    namespace Core
    {
        class GWProfiler : public GUIWindow
        {
        public:
            GWProfiler()
            {
                this->enabled = false;
            }

            void on_gui() override;
        };
    }
}



#endif //LUDVIG_GWPROFILER_H
