//
// File created by Jesper on 8/20/2020.
//

#include "Win32Window.h"

#include "Data/BindingData.h"
#include "Debug/DebugLog.h"

#include "DearImGui/imgui.h"
#include "DearImGui/imgui_impl_win32.h" // for imgui wndproc
#include "DearImGUI/imgui_impl_dx11.h" // for imgui wndproc

extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

namespace Ludvig
{
    namespace Rendering
    {
        namespace D3D
        {
            Win32Window::Win32Window(std::string title, int w, int h) {
                this->title = title;
                this->width = w;
                this->height = h;

                initialize();
            }

            Win32Window::~Win32Window() {
                ::DestroyWindow(hWnd);
                ::UnregisterClass("LudvigWin32WindowClass", hinstance);
            }

            void Win32Window::poll_window_events() {

                if (GetMessage(&msg, NULL,0,0)) {
                    TranslateMessage(&msg);
                    DispatchMessage(&msg);
                }
            }

            bool Win32Window::is_Closing() {
                return !isWindowOpen;
            }

            HWND Win32Window::get_handle() {
                return hWnd;
            }

            void Win32Window::initialize() {
                WNDCLASS wc;

                ZeroMemory(&wc, sizeof(WNDCLASSEX));

                wc.style = CS_HREDRAW | CS_VREDRAW;
                wc.lpfnWndProc = static_window_proc;
                wc.hInstance = hinstance;
                wc.hCursor = LoadCursor(NULL,IDC_ARROW);
                wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
                wc.lpszClassName = "LudvigWin32WindowClass";

                RegisterClass(&wc);

                DWORD dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
                DWORD dwStyle = WS_CAPTION | WS_SYSMENU | WS_VISIBLE | WS_THICKFRAME;

                // TODO(Jesper) calculate middle of the screen for initial window position.

                hWnd = CreateWindowEx
                        (
                                dwExStyle,
                                "LudvigWin32WindowClass",
                                title.c_str(),
                                dwStyle,
                                25,
                                25,
                                width,
                                height,
                                NULL,
                                NULL,
                                hinstance,
                                this
                        );

                ShowWindow(hWnd, 1);
                isWindowOpen = true;

                Data::BindingData::window = this;
                Data::BindingData::windowWidth = width;
                Data::BindingData::windowHeight = height;
            }

            void Win32Window::on_resize_window_callback(int newWidth, int newHeight) {
                width = newWidth;
                height = newHeight;
                Data::BindingData::windowWidth = newWidth;
                Data::BindingData::windowHeight = newHeight;
            }

            LRESULT CALLBACK Win32Window::local_window_proc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) {

                if (ImGui_ImplWin32_WndProcHandler(hwnd,message,wparam,lparam)) {
                   return 0;
                }

                switch (message) {
                    case WM_DESTROY: {
                        isWindowOpen = false;
                        return -1;
                    } break;

                    case WM_SIZE: {
                        on_resize_window_callback(
                                LOWORD(lparam),
                                HIWORD(lparam));
                    };

                    default: {
                        return DefWindowProc (hwnd, message, wparam, lparam);
                    } break;
                }
            }

            LRESULT CALLBACK Win32Window::static_window_proc(HWND hwnd, UINT message, WPARAM wparam, LPARAM lparam) {

                Win32Window* self;

                if (message == WM_NCCREATE) {
                    LPCREATESTRUCT lpcs = reinterpret_cast<LPCREATESTRUCT>(lparam);
                    self = static_cast<Win32Window*>(lpcs->lpCreateParams);
                    self->hWnd = hwnd;
                    SetWindowLongPtr(hwnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(self));
                } else {
                    self = reinterpret_cast<Win32Window*>(GetWindowLongPtr(hwnd, GWLP_USERDATA));
                }

                if (self) {
                    return self->local_window_proc(hwnd,message,wparam,lparam);
                } else {
                    return DefWindowProc (hwnd, message, wparam, lparam);
                }
            }
        }
    }
}