//
// Created by Jesper on 5/27/2020.
//

#include "DebugLog.h"

Ludvig::Debug::DebugLog::DebugLog()
{
    DebugLog::instance = this;
}

void Ludvig::Debug::DebugLog::log_message(std::string message)
{
    instance->log += message + "\n";
}

void Ludvig::Debug::DebugLog::log_warning(std::string warning)
{
    instance->log += "warning: " + warning + "\n";
}

void Ludvig::Debug::DebugLog::log_error(std::string error)
{
    instance->log += "error: " + error + "\n";
}

std::string Ludvig::Debug::DebugLog::get_log()
{
    return instance->log;
}
