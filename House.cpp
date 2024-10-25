#include "House.hpp"
#include "GL/glut.h"

House::House()
: s(1.0f),theta(0.0f),tx(0.0f),ty(0.0f),tz(0.0f),r(1.0f),g(1.0f),b(1.0f) {

}


void House::setColor(float red, float green, float blue) {
    r=red; g=green; b=blue;
}
// void House::ctmMultiply() {
//     glTranslatef(tx,ty,tz);
//     glRotatef(theta,.0,1.0,0);
// }

    void House::draw(){
        glPushMatrix();
    this->ctmMultiply();


    glRotatef(theta,0.0f,1.0f,0.0f);
    glTranslatef(tx,ty,tz);
    glScalef(s,s,s);

        // glPushMatrix();
        // base.setScale(1.0f);


    base.draw();


    glPushMatrix();
    glTranslatef(0.0f,2.0f,0.0f);
        // roof.setScale(1.0f);
    roof.draw();

    glPopMatrix();
    // glPopMatrix();

    }
