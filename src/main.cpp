#include "Headers/glad.h"
#include <GLFW/glfw3.h>

#include "Headers/shaderClass.h"
#include "Headers/VAO.h"
#include "Headers/VBO.h"
#include "Headers/EBO.h"

#include <iostream>
#include <cstdio>
#include <cmath>

int width = 800, height = 800;

GLfloat vertices[] =
{
    0.0f, 0.0f, 0.0f,     1.0f, 0.0f, 0.0f,
    -0.3f, -0.4f, 0.0f,   1.0f, 0.2f, 0.2f,
    0.0f, -0.6f, 0.0f,    1.0f, 0.2f, 0.2f,
    0.3f, -0.4f, 0.0f,    1.0f, 0.0f, 0.0f,
    0.6f, 0.0f, 0.0f,     1.0f, 0.0f, 0.0f,
    0.6f, 0.3f, 0.0f,     0.8f, 0.2f, 0.2f,
    0.4f, 0.55f, 0.0f,    0.8f, 0.2f, 0.2f,
    0.15f, 0.5f, 0.0f,    0.6f, 0.0f, 0.0f,
    0.0f, 0.3f, 0.0f,     0.4f, 0.0f, 0.0f,
    -0.15f, 0.5f, 0.0f,   0.6f, 0.0f, 0.0f,
    -0.4f, 0.55f, 0.0f,   0.8f, 0.0f, 0.0f,
    -0.6f, 0.3f, 0.0f,    0.8f, 0.0f, 0.0f,
    -0.6f, 0.0f, 0.0f,    1.0f, 0.0f, 0.0f,
};

GLuint indices[] =
{
    0, 1, 2,
    0, 2, 3,
    0, 3, 4,
    0, 4, 5,
    0, 5, 6,
    0, 6, 7,
    0, 7, 8,
    0, 8, 9,
    0, 9, 10,
    0, 10, 11,
    0, 11, 12,
    0, 12, 1
};

int main() {
    if(!glfwInit()) {
        std::cout << "Failed to initialize GLFW" << '\n';
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow *window = glfwCreateWindow(width, height, "Window", NULL, NULL);

    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << '\n';
        glfwTerminate();
    }

    glfwMakeContextCurrent(window);

    gladLoadGL();

    glViewport(0, 0, width, height);

    Shader shaderProgram("default.vert", "default.frag");

    VAO VAO1;
    VAO1.Bind();

    VBO VBO1(vertices, sizeof(vertices));
    EBO EBO1(indices, sizeof(indices));

    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    while (!glfwWindowShouldClose(window)) {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        shaderProgram.Activate();
        VAO1.Bind();
        glDrawElements(GL_TRIANGLES, sizeof(indices), GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();

    glfwDestroyWindow(window);
    glfwTerminate();
}