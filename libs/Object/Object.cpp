#include <iostream>
#include "Object.h"

Object::Object(double x, double y, double width, double height, Mesh *mesh, float *color) : x(x),
                                                                                                y(y),
                                                                                                width(width),
                                                                                                height(height),
                                                                                                mesh(mesh),
                                                                                                color(color)
{
}

void Object::onClickAnyWhere(double clickX, double clickY)
{
    //std::cout << "CLICK AT X: " << clickX << " Y: " << clickY << std::endl;
    if (clickX > x && clickX < (x + width) && clickY > y && clickY < (y + height))
    {
        onClick();
    }
}

void Object::onClick()
{
    std::cout << "CLICK AT ME!!!" << std::endl;
}