//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_GWPROFILER_H
#define LUDVIG_GWPROFILER_H

#include "../GUIWindow.h"

namespace Ludvig
{
    namespace GUI
    {
        namespace Windows
        {
            class GWProfiler : public GUIWindow
            {
            public:
                GWProfiler();

                void on_gui() override;
            };
        }
    }
}



#endif //LUDVIG_GWPROFILER_H
