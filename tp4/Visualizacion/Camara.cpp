#include "Camara.h"
#include "../Escena/Faro.h"
#include <GL/glut.h>

Camara::Camara()
{
    this->setVistaStd();
    this->zoom = 45.0;
    this->rotacionDesdeOjo = false;
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

void Camara::switchVista(){
    static short vista = 0;
    switch(++vista){
        case (1):
            this->setVistaBalconFaro();
            break;
        case (2):
            this->setVistaBaseIsla();
            break;
        case (3):
            this->setVistaAguaLejos();
            break;
        default:
            this->setVistaStd();
            vista = 0;
            break;
    }
}

void Camara::preparar(){
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (eye[0], eye[1], eye[2], at[0], at[1], at[2], up[0], up[1], up[2]);

    /*
    glRotated(roll, 0.0, 0.0, 1.0);
      glRotated(pitch, 0.0, 1.0, 0.0);  probar esto
      glRotated(heading, 1.0, 0.0, 0.0);
    */
	if (this->rotacionDesdeOjo)
        glTranslated(eye[0], eye[1], eye[2]);
    // TODO: Calcular el ejeRotacion de acuerdo a la posicion del ojo!!! :)
	glRotatef(anguloZ,ejeRotacionZ[0],ejeRotacionZ[1],ejeRotacionZ[2]);
	glRotatef(anguloXY,ejeRotacionXY[0],ejeRotacionXY[1],ejeRotacionXY[2]);
	if (this->rotacionDesdeOjo)
        glTranslated(-eye[0], -eye[1], -eye[2]);
}

void Camara::setVistaStd(){
    this->eye[0] = 15.0;
    this->eye[1] = 15.0;
    this->eye[2] = 5.0;
    this->at[0] = 0.0f;
    this->at[1] = 0.0f;
    this->at[2] = 0.0f;
    this->up[0] = 0.0f;
    this->up[1] = 0.0f;
    this->up[2] = 1.0f;
    this->ejeRotacionXY[0] = 0;
    this->ejeRotacionXY[1] = 0;
    this->ejeRotacionXY[2] = 1;
    this->ejeRotacionZ[0] = -1;
    this->ejeRotacionZ[1] = 1;
    this->ejeRotacionZ[2] = 0;
    this->anguloXY = 0.0;
    this->anguloZ = 0.0;
    this->rotacionDesdeOjo = false;
}

void Camara::setVistaBalconFaro(){
    float radio = Faro::getDistanciaVistaStd();
    float posicion[3] = {radio, radio, Faro::getAlturaFoco()+0.5f};
    this->eye[0] = posicion[0];
    this->eye[1] = posicion[1];
    this->eye[2] = posicion[2];
    this->at[0] = -10*posicion[0];
    this->at[1] = 10*posicion[1];
    this->at[2] = 0.0f;
    this->up[0] = 0.0f;
    this->up[1] = 0.0f;
    this->up[2] = 1.0f;
    this->ejeRotacionXY[0] = 0;
    this->ejeRotacionXY[1] = 0;
    this->ejeRotacionXY[2] = 1;
    this->ejeRotacionZ[0] = 1;
    this->ejeRotacionZ[1] = 1;
    this->ejeRotacionZ[2] = 0;
    this->anguloXY = 0.0;
    this->anguloZ = 0.0;
    this->rotacionDesdeOjo = true;
}

void Camara::setVistaBaseIsla(){
    float posicion[3] = {2.0f,0.0f,3.0f };
    this->eye[0] = posicion[0];
    this->eye[1] = posicion[1];
    this->eye[2] = posicion[2];
    this->at[0] = posicion[1]; // invierto xy
    this->at[1] = posicion[0]; // invierto xy
    this->at[2] = posicion[2];
    this->up[0] = 0.0f;
    this->up[1] = 0.0f;
    this->up[2] = 1.0f;
    this->ejeRotacionXY[0] = 0;
    this->ejeRotacionXY[1] = 0;
    this->ejeRotacionXY[2] = 1;
    this->ejeRotacionZ[0] = 1;
    this->ejeRotacionZ[1] = 1;
    this->ejeRotacionZ[2] = 0;
    this->anguloXY = 0.0;
    this->anguloZ = 0.0;
    this->rotacionDesdeOjo = true;
}

void Camara::setVistaAguaLejos(){
    this->eye[0] = 60.0f;
    this->eye[1] = 60.0f;
    this->eye[2] = 0.5f;
    this->at[0] = 0.0f;
    this->at[1] = 0.0f;
    this->at[2] = 0.0f;
    this->up[0] = 0.0f;
    this->up[1] = 0.0f;
    this->up[2] = 1.0f;
    this->ejeRotacionXY[0] = 0;
    this->ejeRotacionXY[1] = 0;
    this->ejeRotacionXY[2] = 1;
    this->ejeRotacionZ[0] = -1;
    this->ejeRotacionZ[1] = 1;
    this->ejeRotacionZ[2] = 0;
    this->anguloXY = 0.0;
    this->anguloZ = 0.0;
    this->rotacionDesdeOjo = false;
}
