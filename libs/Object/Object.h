#ifndef OBJECT_H
#define OBJECT_H

class Object
{
public:
    Object(double x, double y,double width,double height);
    bool visible = true;
    double x, y, width, height;

    virtual void onClickAnyWhere(double clickX, double clickY);
    virtual void onClick();
};

#endif