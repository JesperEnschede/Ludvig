cmake_minimum_required(VERSION 3.15)
project(Ludvig)

set(CMAKE_CXX_STANDARD 14)

include_directories(external/gl)

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
        source/rendering/Renderer.h)

target_link_libraries(Ludvig glfw ${GLFW_LIBRARIES} -lOpenGL32)

find_package(OpenGL REQUIRED)