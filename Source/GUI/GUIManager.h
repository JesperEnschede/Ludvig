//
// File created by Jesper on 7/13/2020.
//

#ifndef LUDVIG_GUIMANAGER_H
#define LUDVIG_GUIMANAGER_H

namespace Ludvig
{
    namespace GUI
    {
        /*
         * The GUIManager draws the GUI windows.
         */
        class GUIManager final
        {
        public:
            GUIManager();

            static void draw_gui_windows();

        private:
            void on_gui();

            static GUIManager* instance;
        };
    }
}

#endif //LUDVIG_GUIMANAGER_H
