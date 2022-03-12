#include <iostream>
#include <vector>

#include "Window.h"
#include "Input.h"
#include "Object.h"

int main()
{

    std::vector<Object *> objects;

    Object* obj = new Object(0, 0, 1, 1);
    objects.push_back(obj);

    Window window(300, 300, (char *)"cpptestwork");

    while (!window.ShouldClose())
    { 
        window.Loop();

        if (window.input.Clicked())
        {
            for (auto &object : objects) // access by reference to avoid copying
            {
                object->onClickAnyWhere(window.input.mouseX, window.input.mouseY );
            }
            std::cout << "Cliked at xpos: " << window.input.mouseX << " ypos: " << window.input.mouseY << std::endl;
        }
    }

    return 0;
}