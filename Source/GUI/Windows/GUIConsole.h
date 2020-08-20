//
// File created by Jesper on 8/20/2020.
//

#ifndef LUDVIG_GUICONSOLE_H
#define LUDVIG_GUICONSOLE_H

#include "GUI/GUIWindow.h"

namespace Ludvig
{
    namespace GUI
    {
        class GUIConsole : public GUIWindow
        {
        public:
            void draw() override;
        };
    }
}



#endif //LUDVIG_GUICONSOLE_H
