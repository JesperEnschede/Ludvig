cmake_minimum_required(VERSION 3.15)
project(Ludvig)

set(CMAKE_CXX_STANDARD 17)

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
        source/GUI/windows/GWIncludes.h
        source/rendering/Shader.cpp
        source/rendering/Shader.h
        source/data/FileReader.cpp
        source/data/FileReader.h
        source/core/Transform.cpp
        source/core/Transform.h
        source/core/scene/Camera.cpp
        source/core/scene/Camera.h
        source/data/ModelLoader.cpp
        source/data/ModelLoader.h
        source/rendering/Texture.cpp
        source/rendering/Texture.h

        external/dearimgui/imgui.cpp
        external/dearimgui/imgui_draw.cpp
        external/dearimgui/imgui_impl_glfw.cpp
        external/dearimgui/imgui_impl_opengl3.cpp
        external/dearimgui/imgui_widgets.cpp
        source/core/scene/Light.h source/core/Object.cpp source/core/Object.h
        source/GUI/windows/GWProfiler.cpp
        source/GUI/windows/GWProfiler.h
        source/GUI/windows/GWObjectInspector.h
        source/GUI/windows/GWMeshInspector.h
        source/GUI/windows/GWCameraInspector.h
        source/GUI/windows/GWLightInspector.h
        source/rendering/LightSettings.h
        source/GUI/windows/GWLightSettingsInspector.h
        source/rendering/Cubemap.cpp
        source/rendering/Cubemap.h
        source/core/scene/Skybox.cpp
        source/core/scene/Skybox.h
        source/debug/DebugLog.cpp source/debug/DebugLog.h 
        source/rendering/BufferObject.cpp 
        source/rendering/BufferObject.h 
        source/rendering/VertexArrayObject.cpp
        source/rendering/VertexArrayObject.h
        source/rendering/FrameBuffer.cpp
        source/rendering/FrameBuffer.h source/rendering/Material.cpp source/rendering/Material.h)

target_link_libraries(Ludvig glfw ${GLFW_LIBRARIES} -lopengl32)

find_package(OpenGL REQUIRED)