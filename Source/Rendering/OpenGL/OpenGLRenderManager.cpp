//
// File created by Jesper on 8/6/2020.
//

#include "OpenGLRenderManager.h"

#include "OpenGLForwardRenderer.h"
#include "OpenGLRenderContext.h"
#include "OpenGLWindow.h"
#include "OpenGLMeshRenderer.h"

#include "Debug/DebugLog.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            OpenGLRenderManager::OpenGLRenderManager(Window* window) {

                renderContext = std::make_unique<OpenGLRenderContext>(dynamic_cast<OpenGLWindow*>(window)->get_handle());

                load_openGL();

                // TODO(Jesper) get render technique from a config file.
                renderTechnique = std::make_unique<OpenGLForwardRenderer>();
            }

            void OpenGLRenderManager::render(Core::Scene* scene) {
                renderContext->prepare_frame();
                renderTechnique->render_scene();
                renderContext->finish_frame();
            }

            void OpenGLRenderManager::create_mesh_renderer(Core::Mesh *mesh) {
                renderTechnique->meshRenderers.push_back(std::make_unique<OpenGLMeshRenderer>(mesh));
            }

            void OpenGLRenderManager::load_openGL() {
                if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
                    Debug::DebugLog::log_error("Failed to initialize OpenGL ", true);
                } else {
                    Debug::DebugLog::log_message("Initialized OpenGL");
                }
            }
        }
    }
}