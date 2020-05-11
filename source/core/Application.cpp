//
// Created by Jesper on 5/11/2020.
//

#include "Application.h"

#include "imgui.h"

Ludvig::Core::Application::Application()
{
    this->window = std::make_unique<Rendering::Window>(800,600,true);
    this->renderer = std::make_unique<Rendering::Renderer>(this->window.get());
    this->scene = std::make_unique<Scene::Scene>();
    this->guiManager = std::make_unique<GUI::GUIManager>();
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
        this->guiManager->draw_windows();
        this->renderer->draw_gui_frame();

        this->window->swap_buffers();
    }
}
