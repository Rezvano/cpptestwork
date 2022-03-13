#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Object.h"
#include "Window.h"

class Game
{
private:
    std::vector<Object *> objects;
    Window *window;
public:
    void addObject(Object *object);

    Game(int width, int height, char *name);
    
    ~Game();

    void MainLoop();
};


#endif