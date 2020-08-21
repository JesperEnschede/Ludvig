//
// File created by Jesper on 8/6/2020.
//

#include "OpenGLForwardRenderer.h"

#include "Rendering/OpenGL/API/OpenGLShader.h"

#include "Debug/DebugLog.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            OpenGLForwardRenderer::OpenGLForwardRenderer() {
                Debug::DebugLog::log_message("Created OpenGL forward renderer");
            }

            void OpenGLForwardRenderer::render_scene(Core::Scene* scene) {
                meshRenderer->render(scene->camera->get_view_matrix(), scene->camera->get_projection_matrix());
            }
        }
    }
}