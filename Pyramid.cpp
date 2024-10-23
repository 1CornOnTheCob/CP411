#include "Pyramid.hpp"
#include <GL/glut.h>

Pyramid:: Pyramid() {
    vertex[0][0] = 0.0f; vertex[0][1]=1.0f; vertex[0][2]=0.0f;
    vertex[1][0]= -1.0f; vertex[1][1]=-1.0f; vertex[1][2]=1.0f;
    vertex[2][0]= 1.0f; vertex[2][1]=-1.0f; vertex[2][2]=1.0f;
    vertex[3][0]=1.0f; vertex[3][1]=-1.0f; vertex[3][2]=-1.0f;
    vertex[4][0]=-1.0f; vertex[4][1]=-1.0f; vertex[4][2]=-1.0f;
    face[0][0]=0; face[0][1]=1; face[0][2]=2;face[0][3]=-1;
    face[1][0]=0; face[1][1]=2; face[1][2]=3;face[1][3]=-1;
    face[2][0]=0; face[2][1]=3; face[2][2]=4;face[2][3]=-1;
    face[3][0]=0; face[3][1]=4; face[3][2]=1;face[3][3]=-1;
    face[4][0]=1;face[4][1]=2;face[4][2]=3;face[4][3]=4;
    r=1.0f; g=1.0f; b=0.0f;
}
    void Pyramid::draw(){
        glPushMatrix();
    this->ctmMultiply();
    glScalef(s,s,s);
    glColor3f(r,g,b);
    for (int i =0; i<5; i++) {
        drawFace(i);
    }
        glPopMatrix();
    }
    void Pyramid::drawFace(int i) {
    if (i==4) {
        glBegin(GL_QUADS);
    }else {
        glBegin(GL_TRIANGLES);
    }
    for (int j =0; j<4 && face[i][j] != -1; j++) {
        glVertex3fv(vertex[face[i][j]]);

    }
    glEnd();
}
