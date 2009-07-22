#include "Domo.h"

#define BASE  0.55f
#define PASO  (float)1/6
#define TECHO 1.00f
#define PISO  0.00f

Domo::Domo(const float lado, const float altura) {
	this->lado = lado;
	this->altura = altura;
}

Domo::~Domo() {}

void Domo::dibujar() {
    glClearColor (155.0f/256.0f, 196.0f/256.0f, 226.0f/256.0f, 0.0f);
    OpenGLHelper::aplicarTextura = true;
    OpenGLHelper::dibujarCilindro(50.0f,this->lado/2, 0.0f, this->altura);
    OpenGLHelper::aplicarTextura = false;
}
