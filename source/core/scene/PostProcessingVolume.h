//
// Created by Jesper on 6/6/2020.
//

#ifndef LUDVIG_POSTPROCESSINGVOLUME_H
#define LUDVIG_POSTPROCESSINGVOLUME_H

namespace Ludvig
{
    namespace Core
    {
        namespace Scene
        {
            class PostProcessingVolume
            {
            public:
                bool enable_kernel;
                bool enable_colorShift;
                bool enable_invert;

                float kernel[9] = { 0,0,0,0,0,0,0,0,0};
                float colorShift[3] = { 1,1,1};
            };
        }
    }
}


#endif //LUDVIG_POSTPROCESSINGVOLUME_H
