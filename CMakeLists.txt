# CMakeLists.txt for the GFX Pacman Assignment - Spring 2019
cmake_minimum_required(VERSION 3.14 FATAL_ERROR)
project(conan-wacman VERSION 1.1.1)

set(CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

# CMake Complains if this is not set
set(OpenGL_GL_PREFERENCE GLVND)

# Discover and link required libraries
find_package(imgui REQUIRED)
find_package(OpenAL REQUIRED)
find_package(glad REQUIRED)
find_package(EnTT REQUIRED)
find_package(glfw REQUIRED)
find_package(glm REQUIRED)
find_package(sol2 REQUIRED)
find_package(stb REQUIRED)

add_subdirectory(cglutil)
add_subdirectory(external)
add_subdirectory(pacman)
