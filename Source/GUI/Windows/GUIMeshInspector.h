//
// File created by Jesper on 8/19/2020.
//

#ifndef LUDVIG_GUIMESHINSPECTOR_H
#define LUDVIG_GUIMESHINSPECTOR_H

#include "GUI/GUIWindow.h"

#include "Core/Mesh.h"

namespace Ludvig
{
    namespace GUI
    {
        class GUIMeshInspector : public GUIWindow
        {
        public:
            GUIMeshInspector(Core::Mesh* mesh);

            void draw() override;

        private:
            Core::Mesh* mesh;
        };
    }
}

#endif //LUDVIG_GUIMESHINSPECTOR_H
