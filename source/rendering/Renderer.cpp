//
// Created by Jesper on 5/11/2020.
//

#include "Renderer.h"


Ludvig::Rendering::Renderer::Renderer()
{
    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
    {
        std::printf("Error: failed to load openGL!");
        std::printf("OpenGL: major: %d  minor: %d", GLVersion.major, GLVersion.minor);

        return;
    }
}

void Ludvig::Rendering::Renderer::clear(int mask)
{
    glClear(mask);
}

void Ludvig::Rendering::Renderer::render_scene(Ludvig::Core::Scene::Scene *scene)
{
    for (int i = 0; i < scene->meshes.size(); ++i)
    {
        Core::Scene::Mesh* mesh = scene->meshes[i].get();

        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, mesh->vbo);
        glVertexAttribPointer(0,2,GL_FLOAT, GL_FALSE,0,(void*)0);

        glDrawArrays(GL_TRIANGLES,0,mesh->indices);

        glDisableVertexAttribArray(0);
    }

    // for each mesh in the scene.
    // bind texture
    // set shader.
    // bind VBO,UBO etc.
    // draw triangles
    // cleanup
}

void Ludvig::Rendering::Renderer::create_gui_frame()
{

}

void Ludvig::Rendering::Renderer::draw_gui_frame()
{

}


