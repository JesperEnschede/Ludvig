//
// File created by Jesper on 8/6/2020.
//

#include "OpenGLRenderManager.h"

#include "OpenGLForwardRenderer.h"
#include "OpenGLRenderContext.h"
#include "OpenGLWindow.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            OpenGLRenderManager::OpenGLRenderManager(Window* window) {
                // TODO(Jesper) get render technique from config file.
                renderTechnique = std::make_unique<OpenGLForwardRenderer>();
                renderContext = std::make_unique<OpenGLRenderContext>(dynamic_cast<OpenGLWindow*>(window)->get_handle());
            }

            void OpenGLRenderManager::render() {
                renderContext->prepare_frame();
                renderTechnique->render_scene();
                renderContext->finish_frame();
            }
        }
    }
}