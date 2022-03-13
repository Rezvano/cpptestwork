#include <iostream>

#include "Window.h"

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

Window::Window(int width, int height, char *name, std::vector<Object *> *objects) : objects(objects)
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

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        throw std::runtime_error("glew init falied\r\n");
    }

    glViewport(0, 0, width, height);

    input.Init(window, &frames);
    ShadersInit();
}

bool Window::ShouldClose()
{
    return glfwWindowShouldClose(window);
}

void Window::Loop()
{
    frames++;

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    for (auto &object : *objects)
    {

        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(object->x, object->y, 0));

        GLint transformLoc = glGetUniformLocation(shaderProgram, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

        glm::vec4 color = glm::vec4(object->color[0], object->color[1], object->color[2], object->color[3]);
        GLint colorLoc = glGetUniformLocation(shaderProgram, "col");
        glUniform4fv(colorLoc, 1, glm::value_ptr(color));

        glUseProgram(shaderProgram);
        glBindVertexArray(object->mesh->ID);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }
    glfwSwapBuffers(window);
    input.Loop();
}

Window::~Window()
{
    glfwTerminate();
}
