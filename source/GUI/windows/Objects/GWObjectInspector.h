//
// Created by Jesper on 5/23/2020.
//

#ifndef LUDVIG_GWOBJECTINSPECTOR_H
#define LUDVIG_GWOBJECTINSPECTOR_H

#include "../../GUIWindow.h"

#include "../../../core/Object.h"

namespace Ludvig
{
    namespace Core
    {
        class GWObjectInspector : public GUIWindow
        {
        public:
            GWObjectInspector(Object* object)
            {
                this->object = object;

                this->enabled = false;
            }

            void on_gui() override = 0;

        protected:
            Object* object;
        };
    }
}



#endif //LUDVIG_GWOBJECTINSPECTOR_H
