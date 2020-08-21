//
// File created by Jesper on 8/21/2020.
//

#include "D3DX11RenderContext.h"

#include "Rendering/D3D/Win32Window.h"

#include "Data/BindingData.h"
#include "Debug/DebugLog.h"

#include "DearImGui/imgui.h"
#include "DearImGui/imgui_impl_win32.h"
#include "DearImGui/imgui_impl_dx11.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace D3DX11
        {
            D3DX11RenderContext::D3DX11RenderContext() {
                create_d3dx11_device(dynamic_cast<D3D::Win32Window*>(Data::BindingData::window)->get_handle());
                create_d3dx11_render_target();
                initialize_dearimgui();
            }

            D3DX11RenderContext::~D3DX11RenderContext() {
                ImGui_ImplDX11_Shutdown();
                ImGui_ImplWin32_Shutdown();
                ImGui::DestroyContext();

                swapChain->Release();
                swapChain = nullptr;

                d3dDeviceContext->Release();
                d3dDeviceContext = nullptr;

                d3dDevice->Release();
                d3dDevice = nullptr;
            }

            void D3DX11RenderContext::prepare_frame() {
                // FIXME(Jesper) replace ImVec4 clear color solution with a proper clear color.
                ImVec4 clear_color = ImVec4(0.1,0.1,0.1,1.0f);
                d3dDeviceContext->OMSetRenderTargets(1, &renderTargetView, NULL);
                d3dDeviceContext->ClearRenderTargetView(renderTargetView, (float*)&clear_color);
            }

            void D3DX11RenderContext::finish_frame() {
                swapChain->Present(1,0);
            }

            void D3DX11RenderContext::create_d3dx11_device(HWND hwnd) {
                DXGI_SWAP_CHAIN_DESC sd;
                ZeroMemory(&sd, sizeof(sd));
                sd.BufferCount = 2;
                sd.BufferDesc.Width = 0;
                sd.BufferDesc.Height = 0;
                sd.BufferDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
                sd.BufferDesc.RefreshRate.Numerator = 60; // :thinking:
                sd.BufferDesc.RefreshRate.Denominator = 1;
                sd.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;
                sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
                sd.OutputWindow = hwnd;
                sd.SampleDesc.Count = 1;
                sd.SampleDesc.Quality = 0;
                sd.Windowed = true;
                sd.SwapEffect  = DXGI_SWAP_EFFECT_DISCARD;

                UINT deviceCreateFlags = 0;
                D3D_FEATURE_LEVEL featureLevel;

                const D3D_FEATURE_LEVEL featureLevelArray[2] = {
                        D3D_FEATURE_LEVEL_11_0,
                        D3D_FEATURE_LEVEL_10_0
                };

                if (D3D11CreateDeviceAndSwapChain(
                        NULL,
                        D3D_DRIVER_TYPE_HARDWARE,
                        NULL,
                        deviceCreateFlags,
                        featureLevelArray,
                        2,
                        D3D11_SDK_VERSION,
                        &sd,
                        &swapChain,
                        &d3dDevice,
                        &featureLevel,
                        &d3dDeviceContext) != S_OK) {
                    Debug::DebugLog::log_error("Failed to create D3DX11 device & swapchain",true);
                } else {
                    Debug::DebugLog::log_message("Created D3DX11 device & swapchain");
                }
            }

            void D3DX11RenderContext::create_d3dx11_render_target() {
                ID3D11Texture2D* backBuffer;
                swapChain->GetBuffer(0, IID_PPV_ARGS(&backBuffer));
                d3dDevice->CreateRenderTargetView(backBuffer,NULL, &renderTargetView);
                backBuffer->Release();

                Debug::DebugLog::log_message("Created D3DX11 render target");
            }

            void D3DX11RenderContext::initialize_dearimgui() {
                IMGUI_CHECKVERSION();
                ImGui::CreateContext();
                ImGuiIO& io = ImGui::GetIO(); (void)io;

                ImGui_ImplWin32_Init(dynamic_cast<D3D::Win32Window*>(Data::BindingData::window)->get_handle());
                ImGui_ImplDX11_Init(d3dDevice, d3dDeviceContext);
            }
        }
    }
}