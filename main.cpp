#include "Source/Core/Application.h"
#include "Source/Debug/DebugLog.h"
#include "Source/Scene/SceneManager.h"

#include "memory"

using Application = Ludvig::Core::Application;
using DebugLog = Ludvig::Debug::DebugLog;
using SceneManager = Ludvig::SceneManagement::SceneManager;

int main()
{
    std::unique_ptr<Application> application;
    std::unique_ptr<DebugLog> debugLog;
    std::unique_ptr<SceneManager> sceneManager;

    sceneManager = std::make_unique<SceneManager>();

    debugLog = std::make_unique<DebugLog>();
    application = std::make_unique<Application>();

    sceneManager->test_model();

    application->start();

    return 0;
}
