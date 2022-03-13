#include "Game.h"

const int windowWidth = 300;
const int windowHeight = 300;

const float rectSize = 2.0 / 8;

GLfloat vertices[] = {
    rectSize, rectSize, 0.0f,   // Top Right
    rectSize, 0.0f, 0.0f,  // Bottom Right
    0.0f, 0.0f, 0.0f, // Bottom Left
    0.0f, rectSize, 0.0f   // Top Left
};
GLuint indices[] = {
    // Note that we start from 0!
    0, 1, 3, // First Triangle
    1, 2, 3  // Second Triangle
};

const float black[4] = {0.0f, 0.0f, 0.0f, 1.0f};
const float white[4] = {1.0f, 1.0f, 1.0f, 1.0f};


int main()
{
    Game testGame(300, 300, (char *)"cpptestwork");
    Mesh *rect = new Mesh(vertices, 12, indices, 6);
    for (int x = 0; x < 8; x++)
    {
        for (int y = 0; y < 8; y++)
        {
            float *color = (x + y%2)%2==0 ? (float*)black : (float*)white;
            Object *obj = new Object(-1.0f + rectSize * x,-1.0f +  rectSize * y, rectSize, rectSize, rect, color);
            testGame.addObject(obj);
        }
    }

    testGame.MainLoop();
    return 0;
}