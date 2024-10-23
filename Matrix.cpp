
#include "Matrix.hpp"
#include <stdio.h>
#include <math.h>
#include <iostream>

using namespace std;

Matrix::Matrix() {
	loadIdentity();
}

// mat <- identity matrix
void Matrix::loadIdentity() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j)
				mat[i][j] = 1;
			else
				mat[i][j] = 0;
		}
	}
}

// multiplication  mat <- m * mat
void Matrix::matrixPreMultiply(Matrix* m) {
	Matrix temp;
	for (int i = 0; i <4; i++){
		for (int j = 0; j <4; j++){
			temp.mat[i][j]=0;
			for (int k =0; k<4; k++){
				temp.mat[i][j]+= m->mat[i][k] * mat[k][j];
			}
		}
	}
	for (int i = 0; i<4; i++){
		for (int j=0;j<4;j++){
			mat[i][j]=temp.mat[i][j];
		}
	}
}

// transpose  mat <- mat'
void Matrix::transpose() {
	for (int i = 0; i<4;i++){
		for(int j= i+1;j<4;j++){
			std::swap(mat[i][j],mat[j][i]);
		}
	}
}

// normalize MC
void Matrix::normalize() {
	GLfloat scale = sqrt(mat[0][0] *mat[0][0] +mat[1][0]* mat[1][0]+ mat[2][0] *mat[2][0]);
	if (scale !=0.0f){
	for (int i = 0; i<3;i++){
		for(int j = 0; j<3;j++) {
			mat[i][j] /= scale;
		}
		}
	}
}

// v  <- mat * v
void Matrix::multiplyVector(GLfloat* v) {
	GLfloat temp[4] = {0.0f};
	for(int i=0; i<4;i++){
		temp[i]=0;
		for(int j=0;j<4;j++){
			temp[i]+=mat[i][j]*v[j];

		}
	}
	for(int i=0; i<4;i++){
		v[i]=temp[i];
	}
}

void Matrix::rotateMatrix(GLfloat rx, GLfloat ry, GLfloat rz, GLfloat angle) {

	GLfloat radAngle = angle *M_PI / 180.0f;
	GLfloat c = std::cos(radAngle);
	GLfloat s = std::sin(radAngle);
	GLfloat len = std::sqrt(rx *rx +ry *ry + rz *rz);

	if (len == 0.0f) return;

	rx /= len;
	ry /= len;
	rz /= len;

	Matrix rotation;

	rotation.mat[0][0] = c+ (1-c)*rx *rx;
	rotation.mat[0][1] = (1-c) * rx *ry -s *rz;
	rotation.mat[0][2] = (1-c) * rx *rz +s *ry;
	rotation.mat[1][0] = (1-c) * ry *rx + s *rz;
	rotation.mat[1][1] = c+ (1-c) *ry *ry;
	rotation.mat[1][2] = (1-c) * ry *rz -s *rx;
	rotation.mat[2][0] = (1-c) * rz *rx -s *ry;
	rotation.mat[2][1] = (1-c) * rz *ry +s *rx;
	rotation.mat[2][2] = c+ (1-c) * rz *rz;

	matrixPreMultiply(&rotation);
}



