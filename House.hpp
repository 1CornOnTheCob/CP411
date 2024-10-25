#ifndef HOUSE_HPP
#define HOUSE_HPP

#include <GL/glut.h>
#include "Shape.hpp"
#include "Cube.hpp"
#include "Pyramid.hpp"

class House : public Shape{
public:

    House();
    void draw() ;
    // void ctmMultiply();

    void setColor(float red, float green, float blue);


    float s;
    float theta;
    float tx,ty,tz;

private:
    Cube base;
    Pyramid roof;
    float r,g,b;
};

#endif
