#include "Source/Core/Application.h"
#include "Source/Debug/DebugLog.h"

#include "Source/Data/UserConfig.h"

#include "memory"

using Application = Ludvig::Core::Application;
using DebugLog = Ludvig::Debug::DebugLog;

int main()
{
    std::unique_ptr<Application> application;
    std::unique_ptr<DebugLog> debugLog;

    debugLog = std::make_unique<DebugLog>();

    Ludvig::Data::UserConfig::read_config("assets/config.cfg");
    application = std::make_unique<Application>();

    application->start();

    return 0;
}
