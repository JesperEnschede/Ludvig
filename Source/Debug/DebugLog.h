//
// Created by Jesper on 5/27/2020.
//

#ifndef LUDVIG_DEBUGLOG_H
#define LUDVIG_DEBUGLOG_H

#include "string"

namespace Ludvig
{
    namespace Debug
    {
        class DebugLog
        {
        public:
            DebugLog();

            static void log_message(std::string message);
            static void log_warning(std::string warning);
            static void log_error(std::string error);

            static std::string get_log();

        private:
            inline static DebugLog* instance;

            std::string log;
        };
    }
}



#endif //LUDVIG_DEBUGLOG_H
