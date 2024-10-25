#include "Cube.hpp"

Cube::Cube()
{
	// set set cordinate values for all vertices
    // other faces
    vertex[0][0]=-1.0; vertex[0][1]=-1.0;vertex[0][2]=-1.0;
    vertex[1][0]=1.0; vertex[1][1]=-1.0; vertex[1][2]=-1.0;
    vertex[2][0]=1.0; vertex[2][1]=1.0; vertex[2][2]=-1.0;
    vertex[3][0]=-1.0; vertex[3][1]=1.0; vertex[3][2]=-1.0;
    vertex[4][0]=-1.0; vertex[4][1]=-1.0; vertex[4][2]=1.0;
    vertex[5][0]=1.0; vertex[5][1]=-1.0; vertex[5][2]=1.0;
    vertex[6][0]=1.0; vertex[6][1]=1.0; vertex[6][2]=1.0;
    vertex[7][0]=-1.0; vertex[7][1]=1.0; vertex[7][2]=1.0;
    r = 1.0;
    g = 0.0;
    b = 0.0;
    face[0][0] =0; face[0][1] =1; face[0][2] =2; face[0][3] =3;
    face[1][0] =4; face[1][1] =5; face[1][2] =6; face[1][3] =7;
    face[2][0] = 0; face[2][1] = 3; face[2][2] = 7; face[2][3] =4;
    face[3][0] = 1; face[3][1] = 5; face[3][2] = 6; face[3][3] =2;
    face[4][0] = 0; face[4][1] = 1; face[4][2] = 5; face[4][3] =4;
    face[5][0]=3; face[5][1]=2; face[5][2]=6; face[5][3] =7;
}

void Cube::drawFace(int i){
    glBegin(GL_QUADS);
    glVertex3fv(vertex[face[i][0]]);
    glVertex3fv(vertex[face[i][1]]);
    glVertex3fv(vertex[face[i][2]]);
    glVertex3fv(vertex[face[i][3]]);
    glEnd();

}

void Cube::draw()
{
    glPushMatrix();
    this->ctmMultiply();
    glScalef(s,s,s);
    glColor3f(r,g,b);
    for (int i = 0; i<6;i++){
        drawFace(i);
    }
 // draw all faces
    glPopMatrix();
}

