#include "Coordenadas.h"

Coordenadas::Coordenadas()
{
    this->x = 0;
    this->y = 0;
}

Coordenadas::Coordenadas(int x, int y){
    this->x = x;
    this->y = y;
}


Coordenadas::~Coordenadas()
{
    //dtor
}

bool Coordenadas::mayorX(Coordenadas* c){
    bool mayor;
    (this->x >= c->getX())? mayor = true : mayor = false;
    return mayor;
}

double Coordenadas::distancia (Coordenadas* hasta){
    int deltaX = hasta->getX() - this->x;
    int deltaY = hasta->getY() - this->y;
    return sqrt(deltaX*deltaX + deltaY*deltaY);
}
