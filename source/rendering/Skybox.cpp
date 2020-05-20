//
// Created by Jesper on 5/20/2020.
//

#include "Skybox.h"

#include "stb_image.h"
#include "iostream"

Ludvig::Rendering::Skybox::Skybox(std::vector<const char *> facePaths)
{
    glGenTextures(1,&this->id);
    glBindTexture(GL_TEXTURE_CUBE_MAP, this->id);

    int width, height, channels;

    for (int i = 0; i < facePaths.size(); ++i)
    {
        unsigned char* data = stbi_load(facePaths[i], &width,&height,&channels,0);

        if (data)
        {
            glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width,height,0,GL_RGB, GL_UNSIGNED_BYTE,data);

            stbi_image_free(data);
        }
        else
        {
            std::printf("error: failed to load image! \n");
        }

        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    }
}
