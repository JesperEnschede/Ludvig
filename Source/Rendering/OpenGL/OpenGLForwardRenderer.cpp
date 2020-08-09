//
// File created by Jesper on 8/6/2020.
//

#include "OpenGLForwardRenderer.h"

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

            void OpenGLForwardRenderer::render_scene() {
                for (int i = 0; i < meshRenderers.size(); ++i) {
                    meshRenderers[i]->render();
                }
            }
        }
    }
}