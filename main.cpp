#include "source/core/Application.h"
#include "source/debug/DebugLog.h"

int main()
{
    Ludvig::Debug::DebugLog log;

    Ludvig::Core::Application renderingEngine;

    renderingEngine.start();

    return 0;
}
