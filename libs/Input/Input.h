#ifndef INPUT_H
#define INPUT_H

#include "glfw3.h"

class Input
{
private:
    GLFWwindow *window;
    bool mousePress;
    int pressFrame;
    int inputFrames;
    int centerX, centerY;

public:
    void mouse_callback(int action);
    void cursor_callback(double xpos, double ypos);

    Input(GLFWwindow *window);

    bool Clicked();

    void Loop();

    double mouseX, mouseY;
};

#endif