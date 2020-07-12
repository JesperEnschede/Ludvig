//
// Created by Jesper on 5/12/2020.
//

#include "FileReader.h"

#include "string"
#include "fstream"
#include "sstream"

namespace Ludvig
{
    namespace Data
    {
        std::string read_file(std::string path)
        {
            std::ostringstream sstream;

            std::ifstream fs(path);

            sstream << fs.rdbuf();

            const std::string fileContent(sstream.str());

            return fileContent;
        }
    }
}

