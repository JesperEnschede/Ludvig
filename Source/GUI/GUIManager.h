//
// File created by Jesper on 7/13/2020.
//

#ifndef LUDVIG_GUIMANAGER_H
#define LUDVIG_GUIMANAGER_H

#include "GUIWindow.h"

#include "Core/Scene.h"

#include "vector"
#include "memory"

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
            GUIManager(Core::Scene* scene);

            static void draw_gui_windows();

        private:
            void on_gui();

            std::vector<std::unique_ptr<GUIWindow>> windows;

            static GUIManager* instance;
        };
    }
}

#endif //LUDVIG_GUIMANAGER_H
