cmake_minimum_required(VERSION 3.8)
set(PROJECT_NAME OpenGL)
project(${PROJECT_NAME})

set(CMAKE_INCLUDE_CURRENT_DIR ON)
include_directories(Shaders)
include_directories(Textures)

set(CMAKE_CXX_STANDARD ${C_CXXV})
set(HEADER_FILES stb_image.h glad.h Shader.hpp Camera.hpp Mesh.hpp Model.hpp)
set(SOURCE_FILES main.cpp glad.c Shader.cpp stb_image.cpp Camera.cpp Mesh.cpp Model.cpp)

set (CMAKE_CXX_LINK_EXECUTABLE "${CMAKE_CXX_LINK_EXECUTABLE} -ldl")

find_package(glfw3 3.2 REQUIRED)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME} glfw assimp)
