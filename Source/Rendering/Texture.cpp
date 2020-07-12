//
// Created by Jesper on 5/18/2020.
//

#include "Texture.h"
#include "Debug/DebugLog.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace Ludvig
{
    namespace Rendering
    {
        Texture::Texture()
        {
            glGenTextures(1,&this->id);
            glBindTexture(GL_TEXTURE_2D, this->id);

            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, 1920, 1080, 0, GL_RGB, GL_UNSIGNED_BYTE, NULL);

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        }

        Texture::Texture(const char *path)
        {
            glGenTextures(0,&this->id);
            glBindTexture(GL_TEXTURE_2D, this->id);

            this->data = stbi_load(path, &this->width,&this->height, &this->channels, 0);
            stbi_set_flip_vertically_on_load(true);

            if (this->data)
            {
                glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
                glTexImage2D(GL_TEXTURE_2D,0,GL_RGB, this->width, this->height, 0,GL_RGB, GL_UNSIGNED_BYTE,this->data);

                glGenerateMipmap(GL_TEXTURE_2D);
            }
            else
            {
                Debug::DebugLog::log_error("Failed to load image " + std::string(path) + " ! \n");
            }

            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

            glGenerateMipmap(GL_TEXTURE_2D);
        }

        Texture::~Texture()
        {
            glDeleteTextures(1,&id);
        }
    }
}
