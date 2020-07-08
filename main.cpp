#include "source/core/Application.h"
#include "source/debug/DebugLog.h"

#include "memory"

using Application = Ludvig::Core::Application;
using DebugLog = Ludvig::Debug::DebugLog;

int main()
{
    std::unique_ptr<Application> application;
    std::unique_ptr<DebugLog> debugLog;

    debugLog = std::make_unique<DebugLog>();
    application = std::make_unique<Application>();

    application->start();

    return 0;
}
