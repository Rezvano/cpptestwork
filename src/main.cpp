#include <iostream>
#include "GLFW/glfw3.h"

int main(){
    if(!glfwInit()){
        return -1;
    }
    GLFWwindow* window = glfwCreateWindow(640, 640, "C++ testwork", nullptr, nullptr);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0,0,0,1);
        glClear(GL_COLOR_BUFFER_BIT);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;    
}