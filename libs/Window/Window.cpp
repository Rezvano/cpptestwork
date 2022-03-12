#include <iostream>

#include "Window.h"

Window::Window(int width, int height, char *name)
{
    if (!glfwInit())
    {
        throw std::runtime_error("glfw init falied\r\n");
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    window = glfwCreateWindow(width, height, name, nullptr, nullptr);

    if (!window)
    {
        throw std::runtime_error("window open falied\r\n");
    }
    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
    {
        throw std::runtime_error("glew init falied\r\n");
    }
}

bool Window::ShouldClose()
{
    return glfwWindowShouldClose(window);
}

void Window::Loop()
{
    glfwSwapBuffers(window);
}

Window::~Window()
{
    glfwTerminate();
}
