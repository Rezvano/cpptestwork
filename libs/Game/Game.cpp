#include "Game.h"

#include "Window.h"

Game::Game(int width, int height, char *name)
{
    window = new Window(width, height, name, &objects);
}

Game::~Game()
{
    delete window;
}

void Game::addObject(Object *object)
{
    objects.push_back(object);
}

void Game::MainLoop()
{
    while (!window->ShouldClose())
    {
        window->Loop();
        if (window->input.Clicked())
        {
            for (auto &object : objects)
            {
                object->onClickAnyWhere(window->input.mouseX, window->input.mouseY);
            }
        }
    }
}
