//
// File created by Jesper on 8/6/2020.
//

#include "OpenGLMeshRenderer.h"

#include "glad/glad.h"

#include "OpenGLVertexArray.h"
#include "OpenGLBuffer.h"
#include "OpenGLVertexAttrib.h"
#include "OpenGLShader.h"

#include "Data/FileReader.h"
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

                meshTransform = mesh->transform.get();

                vao = create_vertex_array();

                shader = create_shader
                        (
                            Data::read_file("assets/shaders/" + mesh->shader + "_vertex.glsl").c_str(),
                            Data::read_file("assets/shaders/" + mesh->shader + "_fragment.glsl").c_str()
                        );

                // TODO(Jesper) create texture

                /*
                 * Maybe i should create a "create buffer" function inside of the mesh renderer,
                 * because manually incrementing the vertexattrib index is kinda dirty tbh ;)
                 * idk, we'll see if this causes any major problems in the near future.
                 * -Jesper 8/7/2020
                 */
                buffers.push_back(create_buffer(GL_ARRAY_BUFFER, mesh->vertices.data(), mesh->vertices.size() * sizeof(glm::vec3), GL_STATIC_DRAW));
                vertex_attrib_ptr(0,3);

                buffers.push_back(create_buffer(GL_ARRAY_BUFFER, mesh->uvs.data(), mesh->uvs.size() * sizeof(glm::vec2), GL_STATIC_DRAW));
                vertex_attrib_ptr(1,2);

                buffers.push_back(create_buffer(GL_ARRAY_BUFFER, mesh->normals.data(), mesh->normals.size() * sizeof(glm::vec3), GL_STATIC_DRAW));
                vertex_attrib_ptr(2,3);

                verticesSize = mesh->vertices.size();

                Debug::DebugLog::log_message("Created OpenGL mesh renderer");
            }

            OpenGLMeshRenderer::~OpenGLMeshRenderer() {
                glDeleteVertexArrays(1,&vao);
                for (int i = 0; i < buffers.size(); ++i) {
                    glDeleteBuffers(1,&buffers[i]);
                }
            }

            void OpenGLMeshRenderer::render(glm::mat4 view, glm::mat4 projection) {
                /*
                 * TODO(Jesper) ogl mesh rendering
                 * bind vao
                 * gldrawelements
                 */

                set_uniform_mat4(shader, "model", meshTransform->get_trs());
                set_uniform_mat4(shader, "view", view);
                set_uniform_mat4(shader, "projection", projection);
                glUseProgram(shader);

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
                glDrawArrays(GL_TRIANGLES, 0,verticesSize);
            }
        }
    }
}