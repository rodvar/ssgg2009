#include "Coordenadas.h"
#include "Circunferencia.h"

Coordenadas::Coordenadas() { this->x = 0; this->y = 0; this->z = 0; }

Coordenadas::Coordenadas(int x, int y) { this->x = x; this->y = y; this->z = 0; }
Coordenadas::Coordenadas(int x, int y, int z) { this->x = x; this->y = y; this->z = z; }

Coordenadas::Coordenadas(float x, float y) { this->x = x; this->y = y; this->z = 0; }
Coordenadas::Coordenadas(float x, float y, float z) { this->x = x; this->y = y; this->z = z; }

Coordenadas::Coordenadas(double x, double y) { this->x = x; this->y = y; this->z = 0; }
Coordenadas::Coordenadas(double x, double y, double z) { this->x = x; this->y = y; this->z = z; }


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

double Coordenadas::distancia (Coordenadas hasta){
	float deltaX = hasta.getX() - this->x;
	float deltaY = hasta.getY() - this->y;
    return sqrt(deltaX*deltaX + deltaY*deltaY);
}

bool Coordenadas::operator == (Coordenadas coordenadas){
    return ((this->x == coordenadas.getX()) && (this->y == coordenadas.getY()));
}

void Coordenadas::dibujar(){
    Circunferencia c(5,this->copia());
    c.setColorBorde(this->borde);
    c.setColorRelleno(this->borde);
    c.dibujar();
}
