#ifndef WINDOW_H
#define WINDOW_H

#include <vector>
#include "Object.h"
#include "glew.h"
#include "glfw3.h"
#include "Input.h"

class Window
{
private:
    GLFWwindow *window;
    GLuint shaderProgram;
    std::vector<Object *> *objects;

    int frames=0;
public:
    bool ShouldClose();

    void ShadersInit();

    Window(int width, int height, char *name, std::vector<Object *> *objects);
    ~Window();
    
    Input input;
    void Loop();
};

#endif
