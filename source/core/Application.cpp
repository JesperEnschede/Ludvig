//
// Created by Jesper on 5/11/2020.
//

#include "Application.h"

Ludvig::Core::Application::Application()
{
    this->scene = std::make_unique<Scene::Scene>();
    this->window = std::make_unique<Rendering::Window>(800,600,true);
    this->renderer = std::make_unique<Rendering::Renderer>();
}

void Ludvig::Core::Application::start()
{
    runtime();
}

void Ludvig::Core::Application::runtime()
{
    while (!this->window->is_closing())
    {
        this->renderer->clear(GL_COLOR_BUFFER_BIT);

        this->window->poll_events();

        this->renderer->render_scene(this->scene.get());

        this->renderer->create_gui_frame();

        // do imgui calls.

        this->renderer->draw_gui_frame();

        this->window->swap_buffers();
    }
}
