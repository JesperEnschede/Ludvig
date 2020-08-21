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
                Debug::DebugLog::log_error("Unable to open config file: " + filePath + " - panic creating new config file.", false);
                panic_create_config_file();
                read_config(filePath);
            }
        }

        std::string UserConfig::get_string(const std::string &key) {
            return configValues[key];
        }

        int UserConfig::get_int(const std::string &key) {
            return std::stoi(configValues[key], nullptr,0);
        }

        void UserConfig::panic_create_config_file() {
            std::ofstream output("assets/config.cfg");
            output << "API=OpenGL" << std::endl;
            output << "WIDTH=800" << std::endl;
            output << "HEIGHT=600" << std::endl;
            output << "MODEL=assets/models/cube.obj" << std::endl;
            output << "SHADER=default" << std::endl;
            output << "MODEL=texture" << std::endl;
        }
    }
}