//
// File created by Jesper on 8/20/2020.
//

#include "UserConfig.h"

#include "Debug/DebugLog.h"

#include "iostream"
#include "fstream"
#include "string"
#include "sstream"
#include "iomanip" // for std::stoi

namespace Ludvig
{
    namespace Data
    {
        std::map<std::string, std::string> UserConfig::configValues;

        void UserConfig::read_config(const std::string &filePath) {
            std::ifstream file (filePath);

            if (file.is_open()) {
                std::string line;

                while (std::getline(file,line)) {
                    std::istringstream iss(line);
                    std::string key;

                    if (std::getline(iss, key, '=')) {
                        std::string value;

                        if (std::getline(iss,value)) {
                            configValues.insert(std::make_pair(key,value));
                        }
                    }
                }

                file.close();
            } else {
                Debug::DebugLog::log_error("Unable to open config file: " + filePath, false);
            }
        }

        std::string UserConfig::get_string(const std::string &key) {
            return configValues[key];
        }

        int UserConfig::get_int(const std::string &key) {
            return std::stoi(configValues[key], nullptr,0);
        }
    }
}