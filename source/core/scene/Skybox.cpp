//
// Created by Jesper on 5/23/2020.
//

#include "Skybox.h"

Ludvig::Core::Scene::Skybox::Skybox()
{
    glGenBuffers(1,&vbo);
    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glBufferData(GL_ARRAY_BUFFER,this->vertices.size() * sizeof(float), &this->vertices[0], GL_STATIC_DRAW);
}

Ludvig::Core::Scene::Skybox::~Skybox()
{
    glDeleteBuffers(1,&vbo);
}
