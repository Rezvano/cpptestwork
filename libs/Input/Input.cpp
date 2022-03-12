#include <iostream>
#include "Input.h"

void glfw_mouse_callback(GLFWwindow *window, int button, int action, int mods)
{
    if (button == 0)
        static_cast<Input *>(glfwGetWindowUserPointer(window))->mouse_callback(action);
}

void glfw_cursor_callback(GLFWwindow *window, double xpos, double ypos)
{
    static_cast<Input *>(glfwGetWindowUserPointer(window))->cursor_callback(xpos, ypos);
}

Input::Input(GLFWwindow *window) : window(window)
{
    glfwSetWindowUserPointer(window, this);
    glfwSetMouseButtonCallback(window, glfw_mouse_callback);
    glfwSetCursorPosCallback(window, glfw_cursor_callback);

    glfwGetWindowSize(window, &centerX, &centerY);
    centerX /= 2;
    centerY /= 2;

    mouseX = 0;
    mouseY = 0;
    inputFrames = 0;
    pressFrame = 0;
}

void Input::mouse_callback(int action)
{
    switch (action)
    {
    case GLFW_PRESS:
        mousePress = true;
        pressFrame = inputFrames;
        break;
    case GLFW_RELEASE:
        mousePress = false;
        break;

    default:
        break;
    }
}

void Input::cursor_callback(double xpos, double ypos)
{
    mouseX = (xpos-centerX) / centerX;
    mouseY = - (ypos - centerY) / centerY;
}

bool Input::Clicked()
{
    return mousePress && (pressFrame == inputFrames);
}

void Input::Loop()
{
    inputFrames++;
    glfwPollEvents();
}