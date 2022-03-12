#include <iostream>
#include "Object.h"

Object::Object(double x, double y, double width, double height) : x(x),
                                                                  y(y),
                                                                  width(width),
                                                                  height(height)
{

}

void Object::onClickAnyWhere(double clickX, double clickY)
{
    if (clickX > x && clickX < (x + width) && clickY > y && clickY < (y + height))
    {
        onClick();
    }
}

void Object::onClick()
{
        std::cout << "CLICK AT ME!!!" << std::endl;
}