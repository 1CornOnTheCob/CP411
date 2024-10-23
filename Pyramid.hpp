#ifndef PYRAMID_HPP
#define PYRAMID_HPP

#include "Shape.hpp"
#include <GL/glut.h>
#include "Vector.hpp"
class Pyramid: public Shape{
protected:
    GLfloat vertex[5][3];  //to store pyramid vertex
    GLint face[5][4];      /* 2D array to store faces */
    GLfloat r, g, b;
public:
    Pyramid();
    void draw();
    void drawFace(int);


};

#endif
