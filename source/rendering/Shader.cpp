//
// Created by Jesper on 5/12/2020.
//

#include "Shader.h"

#include "data/FileReader.h"

#include "vector"

Ludvig::Core::Scene::Shader::Shader(std::string vertexPath, std::string fragmentPath)
{
    std::string vertexCode = Data::read_file(vertexPath);
    std::string fragmentCode = Data::read_file(fragmentPath);

    this->program = compile(vertexCode,fragmentCode);
}

Ludvig::Core::Scene::Shader::~Shader()
{
    glDeleteProgram(this->program);
}

GLuint Ludvig::Core::Scene::Shader::get_program() const
{
    return this->program;
}

GLuint Ludvig::Core::Scene::Shader::compile(std::string _vertexCode, std::string _fragmentCode)
{
    const char* vertexCode = _vertexCode.c_str();
    const char* fragmentCode = _fragmentCode.c_str();

    GLuint program;

    int success = 0;
    int infoLogLength = 0;

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1,&vertexCode, nullptr);
    glCompileShader(vertexShader);

    glGetShaderiv(vertexShader,GL_COMPILE_STATUS,&success);
    glGetShaderiv(vertexShader,GL_INFO_LOG_LENGTH,&infoLogLength);

    if (infoLogLength > 0)
    {
        std::vector<char> shaderError(infoLogLength + 1);
        glGetShaderInfoLog(vertexShader,infoLogLength,nullptr,&shaderError[0]);
        std::printf("vertex shader error : \n%s\n",&shaderError[0]);
    }


    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1,&fragmentCode, nullptr);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader,GL_COMPILE_STATUS,&success);
    glGetShaderiv(fragmentShader,GL_INFO_LOG_LENGTH,&infoLogLength);

    if (infoLogLength > 0)
    {
        std::vector<char> shaderError(infoLogLength + 1);
        glGetShaderInfoLog(fragmentShader,infoLogLength,nullptr,&shaderError[0]);
        std::printf("fragment shader error: \n%s\n",&shaderError[0]);
    }

    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    glGetShaderiv(program,GL_LINK_STATUS,&success);
    glGetShaderiv(program,GL_INFO_LOG_LENGTH,&infoLogLength);

    if (infoLogLength > 0)
    {
        std::vector<char> shaderError(infoLogLength + 1);
        glGetShaderInfoLog(program,infoLogLength,nullptr,&shaderError[0]);
        std::printf("shader program error: \n%s\n",&shaderError[0]);
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return program;
}

void Ludvig::Core::Scene::Shader::set_mat4x4(const char *uniform, glm::mat4 matrix)
{
    glUniformMatrix4fv(glGetUniformLocation(this->program, uniform),1,GL_FALSE, &matrix[0][0]);
}

void Ludvig::Core::Scene::Shader::set_vec3(const char *uniform, glm::vec3 vector)
{
    glUniform3f(glGetUniformLocation(this->program,uniform),vector.x,vector.y,vector.z);
}

void Ludvig::Core::Scene::Shader::set_texture(const char *uniform, GLuint id)
{
    glUniform1i(glGetUniformLocation(this->program,uniform),id);
}

void Ludvig::Core::Scene::Shader::set_float(const char *uniform, float value)
{
    glUniform1f(glGetUniformLocation(this->program,uniform),value);
}

void Ludvig::Core::Scene::Shader::set_bool(const char *uniform, int boolean)
{
    glUniform1i(glGetUniformLocation(this->program,uniform), boolean);
}



