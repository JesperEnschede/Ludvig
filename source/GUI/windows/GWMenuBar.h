//
// Created by Jesper on 5/11/2020.
//

#ifndef LUDVIG_GWMENUBAR_H
#define LUDVIG_GWMENUBAR_H

#include "../GUIWindow.h"

namespace Ludvig
{
    namespace GUI
    {
        namespace Windows
        {
            class GWMenuBar : public GUIWindow
            {
            public:
                GWMenuBar();

                void on_gui() override;
            };
        }
    }
}



#endif //LUDVIG_GWMENUBAR_H
