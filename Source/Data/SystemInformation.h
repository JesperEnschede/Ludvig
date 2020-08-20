//
// File created by Jesper on 8/20/2020.
//

#ifndef LUDVIG_SYSTEMINFORMATION_H
#define LUDVIG_SYSTEMINFORMATION_H

#include "string"

namespace Ludvig
{
    namespace Data
    {
        /*
         * A global class containing information about the host system,
         * eg: GPU vendor & model
         */
        class SystemInformation
        {
        public:
            static std::string GPUVendor;
            static std::string GPUModel;
        };
    }
}

#endif //LUDVIG_SYSTEMINFORMATION_H
