//
// File created by Jesper on 8/20/2020.
//

#ifndef LUDVIG_USERCONFIG_H
#define LUDVIG_USERCONFIG_H

#include "map"
#include "string"

namespace Ludvig
{
    namespace Data
    {
        /*
         * The UserConfig class reads a file and stores the key+value in a std::map
         * so the application can read user data.
         */
        class UserConfig
        {
        public:
            /*
             * Reads a config file and inserts the key & value in a config map;
             */
            static void read_config(const std::string& filePath);

            /*
             * Returns a value from a key as a std::string.
             */
            static std::string get_string(const std::string& key);

            /*
             * Returns a value from a key as an int.
             */
            static int get_int(const std::string& key);

        private:
            static std::map<std::string, std::string> configValues;
        };
    }
}

#endif //LUDVIG_USERCONFIG_H
