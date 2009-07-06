#include "Camara.h"
#include <GL/glut.h>

Camara::Camara()
{
    this->eye[0] = 15.0;
    this->eye[1] = 15.0;
    this->eye[2] = 5.0;
    this->at[0] = 0.0f;
    this->at[1] = 0.0f;
    this->at[2] = 0.0f;
    this->up[0] = 0.0f;
    this->up[1] = 0.0f;
    this->up[2] = 1.0f;
    this->zoom = 45.0;
    this->anguloXY = 0.0;
    this->anguloZ = 0.0;
}

void Camara::incrementarRotacionXY(const float incremento){
    this->anguloXY += incremento;
}
void Camara::incrementarRotacionZ(const float incremento){
    this->anguloZ += incremento;
}
void Camara::incrementarZoom(const float incremento){
    this->zoom += incremento;
}
void Camara::incrementarZVer(const float incremento){
    this->at[2] += incremento;
}

void Camara::preparar(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (eye[0], eye[1], eye[2], at[0], at[1], at[2], up[0], up[1], up[2]);
	glRotatef(anguloZ,-1,1,0);
	glRotatef(anguloXY,0,0,1);
}
