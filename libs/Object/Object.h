#ifndef OBJECT_H
#define OBJECT_H

#include "Mesh.h"
class Object
{
public:
    Object(double x, double y, double width, double height, Mesh *mesh, float *color);
    double x, y, width, height;

    Mesh *mesh;
    float *color;

    virtual void onClickAnyWhere(double clickX, double clickY);
    virtual void onClick();
};

#endif