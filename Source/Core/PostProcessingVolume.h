//
// Created by Jesper on 6/6/2020.
//

#ifndef LUDVIG_POSTPROCESSINGVOLUME_H
#define LUDVIG_POSTPROCESSINGVOLUME_H

namespace Ludvig
{
    namespace Core
    {
        class PostProcessingVolume
        {
        public:
            bool enable_kernel = false;
            bool enable_colorShift = false;
            bool enable_invert = false;

            float kernel[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            float colorShift[3] = {0.5f, 0.5f, 0.5f};
        };
    }
}

#endif //LUDVIG_POSTPROCESSINGVOLUME_H
