//
// File created by Jesper on 8/6/2020.
//

#include "OpenGLRenderManager.h"

#include "OpenGLForwardRenderer.h"
#include "OpenGLRenderContext.h"
#include "OpenGLWindow.h"
#include "OpenGLMeshRenderer.h"
#include "OpenGLShader.h"

#include "Data/FileReader.h"
#include "Debug/DebugLog.h"

#include "DearImGui/imgui.h"
#include "DearImGui/imgui_impl_glfw.h"
#include "DearImGui/imgui_impl_opengl3.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            OpenGLRenderManager::OpenGLRenderManager(Window* window) {

                OpenGLWindow* oglWindow = dynamic_cast<OpenGLWindow*>(window);

                renderContext = std::make_unique<OpenGLRenderContext>(oglWindow->get_handle());

                load_openGL();

                // TODO(Jesper) get render technique from a config file.
                renderTechnique = std::make_unique<OpenGLForwardRenderer>();

                initialize_imgui(oglWindow->get_handle());

                glClearColor(0.1f,0.1f,0.1f,1);
                glEnable(GL_DEPTH_TEST);
                glDepthFunc(GL_LESS);
                glEnable(GL_CULL_FACE);
            }

            void OpenGLRenderManager::render(Core::Scene* scene) {
                renderContext->prepare_frame();

                renderTechnique->render_scene(scene);

                create_gui_frame();

                render_gui_frame();

                renderContext->finish_frame();
            }

            void OpenGLRenderManager::create_mesh_renderer(Core::Mesh *mesh) {
                renderTechnique->meshRenderer = std::make_unique<OpenGLMeshRenderer>(mesh);
            }

            void OpenGLRenderManager::load_openGL() {
                if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
                    Debug::DebugLog::log_error("Failed to initialize OpenGL ", true);
                } else {
                    Debug::DebugLog::log_message("Initialized OpenGL");
                }
            }

            void OpenGLRenderManager::initialize_imgui(GLFWwindow* window) {
                IMGUI_CHECKVERSION();
                ImGui::CreateContext();
                ImGuiIO& io = ImGui::GetIO(); (void)io;

                ImGui_ImplGlfw_InitForOpenGL(window,true);
                ImGui_ImplOpenGL3_Init("#version 330 core");
            }

            void OpenGLRenderManager::create_gui_frame() {
                ImGui_ImplOpenGL3_NewFrame();
                ImGui_ImplGlfw_NewFrame();
                ImGui::NewFrame();
            }

            void OpenGLRenderManager::render_gui_frame() {
                ImGui::Render();
                ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            }
        }
    }
}