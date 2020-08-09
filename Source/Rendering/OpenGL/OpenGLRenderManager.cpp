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

                shaders.push_back(std::make_unique<Shader>("assets/shaders/default_vertex.glsl", "assets/shaders/default_fragment.glsl"));
                create_glsl_shaders();

                glClearColor(0.1f,0.1f,0.1f,1);
                glEnable(GL_DEPTH_TEST);
                glDepthFunc(GL_LESS);
                glEnable(GL_CULL_FACE);
            }

            void OpenGLRenderManager::render(Core::Scene* scene) {
                renderContext->prepare_frame();

                renderTechnique->render_scene(scene);

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

            void OpenGLRenderManager::create_glsl_shaders() {
                for (int i = 0; i < shaders.size(); ++i) {
                    glslShaders.push_back(
                            OpenGL::create_shader(
                                    Data::read_file(shaders[i]->vertexFilePath).c_str(),
                                    Data::read_file(shaders[i]->fragmentFilePath).c_str()));
                }
            }
        }
    }
}