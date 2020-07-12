//
// File created by Jesper on 7/8/2020.
//

#ifndef LUDVIG_SCENEMANAGER_H
#define LUDVIG_SCENEMANAGER_H

#include "Scene.h"

#include "memory"

namespace Ludvig
{
    namespace SceneManagement
    {
        class Scene;

        /*
         * The SceneManager manages the current scene,
         * It also handles serialization/deserialization of scene's
         */
        class SceneManager final
        {
        public:
            /*
             * Creates a default empty scene.
             */
            SceneManager();

            void test_model();

            /*
             * Returns a pointer to the current scene
             */
            static Scene* get_current_scene();

        private:
            static std::unique_ptr<Scene> currentScene;
        };
    }
}

#endif //LUDVIG_SCENEMANAGER_H
