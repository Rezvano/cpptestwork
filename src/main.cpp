#include <iostream>

#include "glew.h"
#include "glfw3.h"

#include "Window.h"
#include "Input.h"

int main()
{

    Window window(300, 300, (char *)"cpptestwork");
    Input input(window.window);

    while (!window.ShouldClose())
    {
        input.Loop();
        window.Loop(); 

        if(input.Clicked()){
            std::cout << "Cliked at xpos: " << input.mouseX << " ypos: " << input.mouseY << std::endl;
        }       
    }

    return 0;
}