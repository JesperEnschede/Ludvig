//
// Created by Jesper on 5/11/2020.
//

#include "Application.h"

Ludvig::Core::Application::Application()
{
    this->window = std::make_unique<Rendering::Window>(800,600,true);
}

void Ludvig::Core::Application::start()
{
    runtime();
}

void Ludvig::Core::Application::runtime()
{
    while (!this->window->is_closing())
    {
        this->window->poll_events();

        this->window->swap_buffers();
    }
}
