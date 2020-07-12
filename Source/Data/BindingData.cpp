//
// Created by Jesper on 6/13/2020.
//

#include "BindingData.h"

namespace Ludvig
{
    namespace Data
    {
        std::unique_ptr<Ludvig::Data::BindingData> Ludvig::Data::BindingData::instance;

        Rendering::Window* BindingData::window;
    }
}
