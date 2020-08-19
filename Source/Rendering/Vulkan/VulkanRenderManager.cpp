//
// File created by Jesper on 8/10/2020.
//

#include "VulkanRenderManager.h"

#include "VulkanRenderContext.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace Vulkan
        {
            VulkanRenderManager::VulkanRenderManager() {
                renderContext = std::make_unique<VulkanRenderContext>();
            }

            void VulkanRenderManager::render(Core::Scene *scene) {

            }

            void VulkanRenderManager::create_mesh_renderer(Core::Mesh *mesh) {

            }
        }
    }
}