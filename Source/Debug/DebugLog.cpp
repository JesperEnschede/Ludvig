//
// Created by Jesper on 5/27/2020.
//

#include "DebugLog.h"

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
            instance->log += message + "\n";
        }

        void DebugLog::log_warning(std::string warning)
        {
            instance->log += "warning: " + warning + "\n";
        }

        void DebugLog::log_error(std::string error)
        {
            instance->log += "error: " + error + "\n";
        }

        std::string DebugLog::get_log()
        {
            return instance->log;
        }

    }
}
