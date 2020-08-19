//
// File created by Jesper on 8/19/2020.
//

#ifndef LUDVIG_GUIWINDOW_H
#define LUDVIG_GUIWINDOW_H

namespace Ludvig
{
    namespace GUI
    {
        /*
         * Base class for GUI windows.
         */
        class GUIWindow
        {
            virtual void draw() = 0;
        };
    }
}

#endif //LUDVIG_GUIWINDOW_H
