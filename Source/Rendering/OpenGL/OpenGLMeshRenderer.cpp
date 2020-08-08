//
// File created by Jesper on 8/6/2020.
//

#include "OpenGLMeshRenderer.h"

#include "glad/glad.h"

#include "OpenGLVertexArray.h"
#include "OpenGLBuffer.h"
#include "OpenGLVertexAttrib.h"

#include "Debug/DebugLog.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            OpenGLMeshRenderer::OpenGLMeshRenderer(Core::Mesh *mesh) {
                /*
                 * TODO(Jesper) ogl mesh renderer creation
                 * vao
                 * vbo - vertices \v
                 * vbo - uvs \v
                 * vbo - normals \v
                 * index bo
                 */

                vao = create_vertex_array();

                /*
                 * Maybe i should create a "create buffer" function inside of the mesh renderer,
                 * because manually incrementing the vertexattrib index is kinda dirty tbh ;)
                 * idk, we'll see if this causes any major problems in the near future.
                 * -Jesper 8/7/2020
                 */
                buffers.push_back(create_buffer(GL_ARRAY_BUFFER, mesh->vertices.data(), mesh->vertices.size(), GL_STATIC_DRAW));
                vertex_attrib_ptr(0,3);

                buffers.push_back(create_buffer(GL_ARRAY_BUFFER, mesh->uvs.data(), mesh->uvs.size(), GL_STATIC_DRAW));
                vertex_attrib_ptr(1,2);

                buffers.push_back(create_buffer(GL_ARRAY_BUFFER, mesh->normals.data(), mesh->normals.size(), GL_STATIC_DRAW));
                vertex_attrib_ptr(2,3);

                Debug::DebugLog::log_message("Created OpenGL mesh renderer");
            }

            OpenGLMeshRenderer::~OpenGLMeshRenderer() {
                glDeleteVertexArrays(1,&vao);
                for (int i = 0; i < buffers.size(); ++i) {
                    glDeleteBuffers(1,&buffers[i]);
                }
            }

            void OpenGLMeshRenderer::render() {
                /*
                 * TODO(Jesper) ogl mesh rendering
                 * bind vao
                 * gldrawelements
                 */

                /*
                 * idk, this bind_vertex_array function seems a bit
                 * too unclear. maybe just call the ogl function directly.
                 */
                bind_vertex_array(vao);

                /*
                 * Create some bind of wrapper for the draw call like we did
                 * for the vertex buffer & vertex array, Might be better
                 * readable than doing direct ogl calls. However this level of
                 * abstraction might be very confusing. - Jesper 8/7/2020
                 */
                // TODO(Jesper) glDrawElements instead of glDrawArrays
                glDrawArrays(GL_TRIANGLES, 0,6);
            }
        }
    }
}