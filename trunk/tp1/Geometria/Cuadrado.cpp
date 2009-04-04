#include "Cuadrado.h"

Cuadrado::Cuadrado(float lado, Coordenadas* centro):Rectangulo(lado,lado,centro)
{
    //ctor
}

Cuadrado::~Cuadrado()
{
    delete this->centro;
}
