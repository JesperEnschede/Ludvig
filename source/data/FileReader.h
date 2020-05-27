//
// Created by Jesper on 5/12/2020.
//

#ifndef LUDVIG_FILEREADER_H
#define LUDVIG_FILEREADER_H

#include "string"

namespace Ludvig
{
    namespace Data
    {
        /*
         * Read a text file and return it as a std::string.
         */
        std::string read_file(std::string path);
    }
}


#endif //LUDVIG_FILEREADER_H
