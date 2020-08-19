//
// File created by Jesper on 8/19/2020.
//

#ifndef LUDVIG_GUICAMERAINSPECTOR_H
#define LUDVIG_GUICAMERAINSPECTOR_H

#include "GUI/GUIWindow.h"
#include "Core/Camera.h"

namespace Ludvig
{
    namespace GUI
    {
        class GUICameraInspector : public GUIWindow
        {
        public:
            GUICameraInspector(Core::Camera* camera);

            void draw() override;

        private:
            Core::Camera* camera;
        };
    }
}

#endif //LUDVIG_GUICAMERAINSPECTOR_H
