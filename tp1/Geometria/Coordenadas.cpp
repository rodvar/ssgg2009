#include "Coordenadas.h"

Coordenadas::Coordenadas()
{
    this->x = 0;
    this->y = 0;
}

Coordenadas::Coordenadas(unsigned int x, unsigned int y){
    this->x = x;
    this->y = y;
}


Coordenadas::~Coordenadas()
{
    //dtor
}

double Coordenadas::distancia (Coordenadas* hasta){
    unsigned int deltaX = hasta->getX() - this->x;
    unsigned int deltaY = hasta->getY() - this->y;
    return sqrt(deltaX*deltaX + deltaY*deltaY);
}
