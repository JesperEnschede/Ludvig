//
// File created by Jesper on 8/21/2020.
//

#include "D3DX11RenderManager.h"

#include "D3DX11ForwardRenderer.h"
#include "D3DX11RenderContext.h"

#include "GUI/GUIManager.h"

#include "DearImGui/imgui.h"
#include "DearImGui/imgui_impl_win32.h"
#include "DearImGui/imgui_impl_dx11.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace D3DX11
        {
            D3DX11RenderManager::D3DX11RenderManager() {
                renderContext = std::make_unique<D3DX11RenderContext>();
            }

            void D3DX11RenderManager::render(Core::Scene *scene) {
                renderContext->prepare_frame();

                create_gui_frame();
                GUI::GUIManager::draw_gui_windows();
                render_gui_frame();

                renderContext->finish_frame();
            }

            void D3DX11RenderManager::create_mesh_renderer(Core::Mesh *mesh) {

            }

            void D3DX11RenderManager::create_gui_frame() {
                ImGui_ImplDX11_NewFrame();
                ImGui_ImplWin32_NewFrame();
                ImGui::NewFrame();
            }

            void D3DX11RenderManager::render_gui_frame() {
                ImGui::Render();
                ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());
            }
        }
    }
}