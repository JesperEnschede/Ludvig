//
// Created by Jesper on 5/12/2020.
//

#include "FileReader.h"

#include "Debug/DebugLog.h"

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

            if (!fs.is_open()) {
                Debug::DebugLog::log_error("Unable to open file " + path, false);
            } else {
                Debug::DebugLog::log_message("Opened file: " + path);
            }

            sstream << fs.rdbuf();

            const std::string fileContent(sstream.str());

            return fileContent;
        }
    }
}

