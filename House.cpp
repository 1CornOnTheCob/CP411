#include "House.hpp"

House::House(){}

    void House::draw(){
        glPushMatrix();
        glColor3f(0.0, 0.0, 0.0);
        base.draw();

        glTranslatef(0.0f,2.0f,0.0f);
        glColor3f(0.0f,1.0f,0.0f);
        roof.draw();
        glPopMatrix();
    
    }
