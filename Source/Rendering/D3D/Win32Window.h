//
// File created by Jesper on 8/20/2020.
//

#ifndef LUDVIG_WIN32WINDOW_H
#define LUDVIG_WIN32WINDOW_H

#include "Rendering/Window.h"

#include "Windows.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace D3D
        {
            /*
             * A win32 window wrapper
             */
            class Win32Window : public Window
            {
            public:
                /*
                 * Initializes default window values and creates a win32 window.
                 */
                Win32Window(std::string title, int w, int h);

                /*
                 * Translates and dispatches window messages.
                 */
                void poll_window_events() override;

                /*
                 * Returns true if the window is closing.
                 */
                bool is_Closing() override;

                /*
                 * Returns the window handle
                 */
                HWND get_handle();

            protected:
                /*
                 * Creates a win32 window.
                 */
                void initialize() override;

                /*
                 * Window resize callback
                 */
                void on_resize_window_callback(int newWidth, int newHeight) override;

            private:
                /*
                 * Local window processing, gets called from the static_window_proc.
                 */
                LRESULT CALLBACK local_window_proc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

                /*
                 * Gets the window user data from the lparam and calls local_window_proc on the recovered user data,
                 * Calls DefWindowProc when no userdata is retrieved from the lparam.
                 */
                static LRESULT CALLBACK static_window_proc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam);

                std::string title;
                int height;
                int width;

                bool isWindowOpen;

                HWND hWnd;
                HINSTANCE hinstance;
                MSG msg;
            };
        }
    }
}

#endif //LUDVIG_WIN32WINDOW_H
