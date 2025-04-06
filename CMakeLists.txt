cmake_minimum_required(VERSION 4.0.0)
project(opengl_heart VERSION 0.1.0)
cmake_policy(SET CMP0072 NEW)

find_package(OpenGL REQUIRED)

add_executable(
    opengl_heart 
    src/main.cpp 
    src/Headers/glad.h 
    src/Headers/shaderClass.h
    src/Headers/VAO.h
    src/Headers/VBO.h
    src/Headers/EBO.h
    src/glad.c
    src/shaderClass.cpp
    src/VAO.cpp
    src/VBO.cpp
    src/EBO.cpp
)

file(
    COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/Shaders/default.vert
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

file(
    COPY ${CMAKE_CURRENT_SOURCE_DIR}/src/Shaders/default.frag
    DESTINATION ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(
    opengl_heart
    glfw 
    OpenGL::GL
)