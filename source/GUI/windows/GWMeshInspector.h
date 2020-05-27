//
// Created by Jesper on 5/23/2020.
//

#ifndef LUDVIG_GWMESHINSPECTOR_H
#define LUDVIG_GWMESHINSPECTOR_H

#include "GWObjectInspector.h"

namespace Ludvig
{
    namespace Core
    {
        class GWMeshInspector : public GWObjectInspector
        {
        public:
            GWMeshInspector(Object *object) : GWObjectInspector(object)
            {

            }

            void on_gui() override
            {
                ImGui::Begin("Mesh inspector");
                this->draw_transform(object->transform.get());
                ImGui::End();
            }
        };
    }
}



#endif //LUDVIG_GWMESHINSPECTOR_H
