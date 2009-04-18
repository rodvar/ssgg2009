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

bool Coordenadas::tieneMayorX(Coordenadas* c){
    bool mayor;
    (this->x >= c->getX())? mayor = true : mayor = false;
    return mayor;
}

Coordenadas* Coordenadas::mayorX(Coordenadas* c){
    Coordenadas* coordenadas;
    (this->x > c->getX()) ? coordenadas = this : coordenadas = c;
    return coordenadas;
}

Coordenadas* Coordenadas::menorX(Coordenadas* c){
    Coordenadas* coordenadas;
    (this->x < c->getX()) ? coordenadas =  this : coordenadas =  c;
    return coordenadas;
}

Coordenadas* Coordenadas::mayorY(Coordenadas* c){
    Coordenadas* coordenadas;
    (this->y > c->getY()) ? coordenadas =  this : coordenadas =  c;
    return coordenadas;
}

Coordenadas* Coordenadas::menorY(Coordenadas* c){
    Coordenadas* coordenadas;
    (this->y < c->getY()) ? coordenadas =  this : coordenadas =  c;
    return coordenadas;
}

double Coordenadas::distancia (Coordenadas* hasta){
    int deltaX = hasta->getX() - this->x;
    int deltaY = hasta->getY() - this->y;
    return sqrt(deltaX*deltaX + deltaY*deltaY);
}

bool Coordenadas::operator == (Coordenadas* coordenadas){
    return ((this->x == coordenadas->getX()) && (this->y == coordenadas->getY()));
}
