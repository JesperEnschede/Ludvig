//
// Created by Jesper on 5/12/2020.
//

#include "Shader.h"

#include "../../data/FileReader.h"

Ludvig::Core::Scene::Shader::Shader(const char *vertexPath, const char *fragmentPath)
{
    const char* vertexCode = Data::read_file(vertexPath);
    const char* fragmentCode = Data::read_file(fragmentPath);

    this->program = compile(vertexCode,fragmentCode);
}

GLuint Ludvig::Core::Scene::Shader::get_program() const
{
    return this->program;
}

GLuint Ludvig::Core::Scene::Shader::compile(const char *vertexCode, const char *fragmentCode)
{
    GLuint program;

    int success = 0;
    int infoLogLength = 0;

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1,&vertexCode, nullptr);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1,&fragmentCode, nullptr);
    glCompileShader(fragmentShader);

    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);

    glLinkProgram(program);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return 0;
}

