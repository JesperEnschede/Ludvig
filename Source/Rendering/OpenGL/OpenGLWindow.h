//
// File created by Jesper on 8/6/2020.
//

#ifndef LUDVIG_OPENGLWINDOW_H
#define LUDVIG_OPENGLWINDOW_H

#include "Rendering/Window.h"

namespace Ludvig
{
    namespace Rendering
    {
        namespace OpenGL
        {
            class OpenGLWindow : public Window
            {
            public:
                OpenGLWindow(std::string title,int w, int h);

                void initialize() override;
            };
        }
    }
}

#endif //LUDVIG_OPENGLWINDOW_H
