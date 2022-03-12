#ifndef WINDOW_H
#define WINDOW_H

#include "glew.h"
#include "Input.h"

class Window
{
private:
    GLFWwindow *window;
    int frames=0;
public:
    bool ShouldClose();

    Window(int width, int height, char *name);
    ~Window();
    
    Input input;
    void Loop();
};

#endif
