#include <stdio.h>
#include "Camera.hpp"
#include "Matrix.hpp"
#include <math.h>

bool DEBUG = false;

Camera::Camera(){
	eye.set(5.0, 5.0, 10.0);
	ref.set(0, 0, 0);
	viewup.set(0, 0, 1);
	aspect = 1.0, vangle = 40.0, dnear = 1.0, dfar = 15.0;
	setViewNorm();

}

void Camera::reset(void) { // make default camera
	eye.set(5.0, 5.0, 10.0);
	ref.set(0, 0, 0);
	viewup.set(0, 0, 1);
	aspect = 1.0, vangle = 40.0, dnear = 1.0, dfar = 15.0;
	setViewNorm();
}

void Camera::set(Point Eye, Point Look, Vector Up) {
	eye.set(Eye);
	ref.set(Look);
	viewup.set(Up);
	aspect = 1.0;
	vangle = 40.0;
	dnear = 1.0;
	dfar = 15.0;
	setViewNorm();
}

void Camera::setViewNorm() {
	GLfloat x, y, z, sr;
	x = ref.x-eye.x;
	y = ref.y-eye.y;
	z = ref.z-eye.z;
	sr = sqrt(x*x + y*y + z*z);
	x = x/sr;
	y = y/sr;
	z = z/sr;
	viewNorm.set(x, y, z);
}

void Camera::rotate(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle){
Matrix rotationMatrix;
rotationMatrix.rotateMatrix(rx,ry,rz,angle);
Vector eyeVector(eye.x - ref.x, eye.y - ref.y,eye.z-ref.z);

GLfloat eyeVecArray[4]= {eyeVector.x, eyeVector.y, eyeVector.z, 1.0f};
rotationMatrix.multiplyVector(eyeVecArray);
eye.set(ref.x + eyeVecArray[0], ref.y +eyeVecArray[1],ref.z+eyeVecArray[2]);
setViewNorm(); 
}

void Camera::translate(GLfloat tx, GLfloat ty, GLfloat tz) {
eye.x += tx;
eye.y += ty;
eye.z += tz;

ref.x += tx;
ref.y += ty;
ref.z += tz;
}

void Camera::setProjectionMatrix() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(vangle, aspect, dnear, dfar);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(eye.x, eye.y, eye.z, ref.x, ref.y, ref.z, viewup.x,viewup.y,viewup.z);
}
void Camera::set(float ex, float ey, float ez, float lx, float ly, float lz, float upx, float upy, float upz) {
	eye.set(ex, ey, ez);
	ref.set(lx, ly, lz);
	viewup.set(upx, upy, upz);
	aspect = 1.0;
	vangle = 40.0;
	dnear = 1.0;
	dfar = 15.0;
	setViewNorm();
}
void Camera::setViewVolume(float viewAngle, float aspect, float Near, float Far) {
	vangle = viewAngle;
	this->aspect = aspect;
	dnear = Near;
	dfar = Far;
}
void Camera::setAspect(float aspect) {
	this->aspect = aspect;
}


