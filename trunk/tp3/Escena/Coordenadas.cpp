#include "Coordenadas.h"

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

Coordenadas::Coordenadas(const Coordenadas& coordenadas){
    this->x = coordenadas.x;
    this->y = coordenadas.y;
    this->z = coordenadas.z;
}

bool Coordenadas::tieneMayorX(Coordenadas* c){
    bool mayor;
    (this->x >= c->getX())? mayor = true : mayor = false;
    return mayor;
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
    glVertex3f(this->x,this->y,this->z);
}
