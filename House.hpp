#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "Shape.hpp"
#include "Cube.hpp"
#include "Pyramid.hpp"

class House : public Shape{
    public:
    Cube base;
    Pyramid roof;

    House();
    void draw() ;

};

#endif
