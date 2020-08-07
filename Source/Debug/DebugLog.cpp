//
// Created by Jesper on 5/27/2020.
//

#include "DebugLog.h"

#include "stdexcept"

namespace Ludvig
{
    namespace Debug
    {
        DebugLog::DebugLog()
        {
            DebugLog::instance = this;
        }

        void DebugLog::log_message(std::string message)
        {
            std::printf("%s \n", message.c_str());
            instance->log += message + "\n";
        }

        void DebugLog::log_warning(std::string warning)
        {
            std::printf("warning: %s \n", warning.c_str());
            instance->log += "warning: " + warning + "\n";
        }

        void DebugLog::log_error(std::string error, bool throwException)
        {
            if (throwException)
                throw std::runtime_error(error);

            std::printf("error: %s \n", error.c_str());
            instance->log += "error: " + error + "\n";
        }

        std::string DebugLog::get_log()
        {
            return instance->log;
        }
    }
}
