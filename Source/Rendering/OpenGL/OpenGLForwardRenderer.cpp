//
// File created by Jesper on 8/6/2020.
//

#include "OpenGLForwardRenderer.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            void OpenGLForwardRenderer::render_scene() {
                for (int i = 0; i < meshRenderers.size(); ++i) {
                    meshRenderers[i]->render();
                }
            }
        }
    }
}