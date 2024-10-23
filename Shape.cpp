#include "Shape.hpp"
#include <stdio.h>
#include <GL/glut.h>

using namespace std;

Shape::Shape() {
	reset();
}

Shape::~Shape() { };

Matrix Shape::getMC() {
	return  mc;
};


void Shape::setParentMC(Matrix *pm)
{
   pmc = pm;
}


void Shape::reset(){
	mc.loadIdentity();
	pmc = NULL;
	s = 1.0f;
}

void Shape::translate(GLfloat tx, GLfloat ty, GLfloat tz) {
	mc.mat[0][3] += tx;
	mc.mat[1][3] += ty;
	mc.mat[2][3] += tz;
	mc.mat[3][3] = 1.0f;
}

void Shape::rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {
	Matrix m;
	m.rotateMatrix(rx, ry, rz, angle);
	mc.matrixPreMultiply(&m);
}


void Shape::rotate(GLfloat x0, GLfloat  y0, GLfloat  z0, GLfloat  rx, GLfloat  ry, GLfloat rz,  GLfloat  angle) {
	translate(-x0,-y0,-z0);
	Matrix rotationMatrix;
	rotationMatrix.rotateMatrix(rx,ry,rz,angle);
	mc.matrixPreMultiply(&rotationMatrix);
	translate(x0,y0,z0);
}


void Shape::rotateOrigin(GLfloat x0, GLfloat  y0, GLfloat  z0, GLfloat  rx, GLfloat  ry, GLfloat rz,  GLfloat  angle) {
	Matrix m;
	m.rotateMatrix(rx, ry, rz, angle);
	GLfloat v[4]={
		mc.mat[0][3] - x0,
		mc.mat[1][3] - y0,
		mc.mat[2][3] - z0,
		mc.mat[3][3]
	};
	m.multiplyVector(v);
	mc.mat[0][3] = v[0] + x0;
	mc.mat[1][3] = v[1] + y0;
	mc.mat[2][3] = v[2] + z0;
	mc.mat[3][3] = v[3];
}


void Shape::setScale(GLfloat x) {
	s = x;
}

void Shape::scaleChange(GLfloat x) {
	s += x;
}

void Shape::setId(GLint i) {
	id = i;
}

GLint Shape::getId() {
	return id;
}

void Shape::ctmMultiply() {
	GLfloat M[16]={
	mc.mat[0][0],
	mc.mat[1][0],
	mc.mat[2][0],
	0,
	mc.mat[0][1],
	mc.mat[1][1],
	mc.mat[2][1],
	0,
	mc.mat[0][2],
	mc.mat[1][2],
	mc.mat[2][2],
	0,
	mc.mat[0][3],
	mc.mat[1][3],
	mc.mat[2][3],
	1};
	glMultMatrixf(M);
}
