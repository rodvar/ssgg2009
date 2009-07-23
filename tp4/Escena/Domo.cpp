#include "Domo.h"
#include "../Visualizacion/OpenGLSurfacer.h"

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
    OpenGLHelper::aplicarTextura = true;
    OpenGLSurfacer::setCielo();
    OpenGLHelper::dibujarCilindro(50.0f,this->lado/2, 0.0f, this->altura);
    OpenGLSurfacer::setPorDefecto();
    OpenGLHelper::aplicarTextura = false;
}
