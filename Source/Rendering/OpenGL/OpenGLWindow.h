//
// File created by Jesper on 8/6/2020.
//

#ifndef LUDVIG_OPENGLWINDOW_H
#define LUDVIG_OPENGLWINDOW_H

#include "Rendering/Window.h"

#include "GLFW/glfw3.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            class OpenGLWindow : public Window
            {
            public:
                /*
                 * Initializes default window values, calls initialize();
                 */
                OpenGLWindow(std::string title,int w, int h);

                /*
                 * Calls GLFW API poll events function
                 */
                void poll_window_events() override;

                /*
                 * Calls GLFW API window should close function,
                 * Returns true if the window is closing down.
                 */
                bool is_Closing() override;

                /*
                 * Returns a handle to the GLFW window.
                 */
                GLFWwindow* get_handle() const;

            protected:
                /*
                 * Initializes and creates a GLFW window.
                 */
                void initialize() override;

            private:
                GLFWwindow* window;
            };
        }
    }
}

#endif //LUDVIG_OPENGLWINDOW_H
