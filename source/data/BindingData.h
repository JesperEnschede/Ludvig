//
// Created by Jesper on 6/11/2020.
//

#ifndef LUDVIG_BINDINGDATA_H
#define LUDVIG_BINDINGDATA_H

#include "memory"

namespace Ludvig
{
    namespace Data
    {
        class BindingData
        {
        public:
            static BindingData* get_instance()
            {
                return instance.get();
            }

        protected:
            static std::unique_ptr<BindingData> instance;
        };
    }
}


#endif //LUDVIG_BINDINGDATA_H
