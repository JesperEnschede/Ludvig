//
// Created by Jesper on 6/7/2020.
//

#ifndef LUDVIG_UNIFORMBLOCK_H
#define LUDVIG_UNIFORMBLOCK_H

namespace Ludvig
{
    namespace Rendering
    {
        class UniformBlock
        {
        public:
            UniformBlock(unsigned int programID, const char* blockName);

        private:
            unsigned int uniformBlockIndex;
        };
    }
}



#endif //LUDVIG_UNIFORMBLOCK_H
