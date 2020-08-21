//
// File created by Jesper on 8/21/2020.
//

#ifndef LUDVIG_D3DX11RENDERCONTEXT_H
#define LUDVIG_D3DX11RENDERCONTEXT_H

#include "Rendering/RenderContext.h"

#include "d3d11.h"
#pragma comment(lib "d3d11.lib")

#include "Windows.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace D3DX11
        {
            class D3DX11RenderContext : public RenderContext
            {
            public:
                D3DX11RenderContext();

                ~D3DX11RenderContext();

                void prepare_frame() override;

                void finish_frame() override;

            private:
                void create_d3dx11_device(HWND hwnd);

                void create_d3dx11_device_context();

                ID3D11Device* d3dDevice;
                ID3D11DeviceContext* d3dDeviceContext;
                IDXGISwapChain* swapChain;
                ID3D11RenderTargetView* renderTargetView;
            };
        }
    }
}

#endif //LUDVIG_D3DX11RENDERCONTEXT_H
