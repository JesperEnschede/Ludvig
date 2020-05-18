cmake_minimum_required(VERSION 3.15)
project(Ludvig)

set(CMAKE_CXX_STANDARD 14)

include_directories(external/gl external/dearimgui external/glm external/stb)

add_subdirectory(external/glfw)
include_directories(glfw/include/)

add_executable(
        Ludvig main.cpp

        source/core/Application.cpp
        source/core/Application.h
        source/rendering/Window.cpp
        source/rendering/Window.h
        source/GL/glad.c
        source/core/scene/Scene.cpp
        source/core/scene/Scene.h
        source/core/scene/Mesh.cpp
        source/core/scene/Mesh.h
        source/rendering/Renderer.cpp
        source/rendering/Renderer.h
        source/GUI/GUIManager.cpp
        source/GUI/GUIManager.h
        source/GUI/GUIWindow.h
        source/GUI/windows/GWMenuBar.cpp
        source/GUI/windows/GWMenuBar.h
        source/GUI/windows/GWIncludes.h
        source/GUI/windows/GWProfiler.cpp
        source/GUI/windows/GWProfiler.h
        source/core/scene/Shader.cpp
        source/core/scene/Shader.h
        source/data/FileReader.cpp
        source/data/FileReader.h
        source/core/scene/Transform.cpp
        source/core/scene/Transform.h
        source/core/scene/Camera.cpp
        source/core/scene/Camera.h
        source/data/ModelLoader.cpp
        source/data/ModelLoader.h
        source/rendering/VertexBufferIndexer.cpp
        source/rendering/VertexBufferIndexer.h
        source/core/scene/Texture.cpp
        source/core/scene/Texture.h

        external/dearimgui/imgui.cpp
        external/dearimgui/imgui_draw.cpp
        external/dearimgui/imgui_impl_glfw.cpp
        external/dearimgui/imgui_impl_opengl3.cpp
        external/dearimgui/imgui_widgets.cpp
)

target_link_libraries(Ludvig glfw ${GLFW_LIBRARIES} -lOpenGL32)

find_package(OpenGL REQUIRED)