//
// Created by Jesper on 5/12/2020.
//

#include "FileReader.h"

#include "stdio.h"
#include "string"
#include "fstream"
#include "sstream"

const char* Ludvig::Data::read_file(const char *path)
{
    std::string fileContent;
    std::ifstream file;

    file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try
    {
        file.open(path);

        std::stringstream fileStream;

        fileStream << file.rdbuf();

        file.close();

        fileContent = fileStream.str();
    }
    catch(std::ifstream::failure& e)
    {
        printf("Error: unable to open file %s \n", path);
    }

    return fileContent.c_str();
}
