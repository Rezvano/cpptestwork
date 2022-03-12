#ifndef WINDOW_H
#define WINDOW_H

#include "glew.h"
#include "glfw3.h"

class Window
{
private:
public:
    GLFWwindow *window;

    bool ShouldClose();

    Window(int width, int height, char *name);
    ~Window();

    void Loop();
};

#endif
