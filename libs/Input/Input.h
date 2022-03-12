#ifndef INPUT_H
#define INPUT_H

#include "glfw3.h"

class Input
{
private:
    bool mousePress = false;
    int pressFrame = 0;
    int *inputFrames;
    int centerX = 0, centerY = 0;

public:
    void mouse_callback(int action);
    void cursor_callback(double xpos, double ypos);

    void Init(GLFWwindow *window, int *inputFrames);

    bool Clicked();

    void Loop();

    double mouseX, mouseY;
};

#endif