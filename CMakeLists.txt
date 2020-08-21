cmake_minimum_required(VERSION 3.15)
project(Ludvig)

set(CMAKE_CXX_STANDARD 17)

macro(read_directory curdir)
    file(GLOB children RELATIVE ${curdir} ${curdir}/*)

    set(groupList "")

    foreach(child ${children})
        if (NOT (IS_DIRECTORY ${curdir}/${child}))
            list(APPEND Ludvig_Source ${curdir}/${child})
            list(APPEND groupList ${curdir}/${child})
        endif()
    endforeach()

    list(LENGTH groupList length)
    if (length GREATER 0)
        string(REPLACE ${PROJECT_SOURCE_DIR} "" GROUPNAME ${curdir})
        string(REPLACE "/" "\\" GROUPNAME ${GROUPNAME})
        source_group(${GROUPNAME} FILES ${groupList})
    endif()

    foreach(child ${children})
        if (IS_DIRECTORY ${curdir}/${child})
            read_directory(${curdir}/${child})
        endif()
    endforeach()
endmacro()

read_directory(${PROJECT_SOURCE_DIR}/Source)

include_directories(External/gl)
include_directories(External/glm)
include_directories(External/stb)

include_directories(Source)

add_subdirectory(External/glfw)
include_directories(glfw/include/)

add_executable(Ludvig main.cpp ${Ludvig_Source})
find_package(Vulkan REQUIRED)
target_link_libraries(Ludvig glfw ${GLFW_LIBRARIES} -lopengl32 Vulkan::Vulkan d3d11 d3dx11)
find_package(OpenGL REQUIRED)