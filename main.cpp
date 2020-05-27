#include "source/core/Application.h"
#include "source/debug/DebugLog.h"

int main()
{
    Ludvig::Core::Application renderingEngine;
    Ludvig::Debug::DebugLog log;

    renderingEngine.start();

    return 0;
}
