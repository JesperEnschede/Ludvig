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

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glDisable(GL_CULL_FACE);
    glDepthFunc(GL_LESS);
}

void Ludvig::Rendering::Renderer::render_scene(Ludvig::Core::Scene::Scene *scene)
{
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
