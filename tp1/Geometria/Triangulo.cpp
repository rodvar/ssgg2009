#include "Triangulo.h"
#include "Segmento.h"

Triangulo::Triangulo(Coordenadas* verticeA, Coordenadas* verticeB, Coordenadas* verticeC)
{
    this->verticeA = verticeA;
    this->verticeB = verticeB;
    this->verticeC = verticeC;
}

Triangulo::~Triangulo()
{
    delete this->verticeA;
    delete this->verticeB;
    delete this->verticeC;
}

void Triangulo::dibujar(){
    glColor3f(this->borde->getRojo(), this->borde->getVerde(), this->borde->getAzul());
    Segmento* segmentoAB = new Segmento(this->verticeA->copia(), this->verticeB->copia());
    Segmento* segmentoBC = new Segmento(this->verticeB->copia(), this->verticeC->copia());
    Segmento* segmentoCA = new Segmento(this->verticeC->copia(), this->verticeA->copia());
    segmentoAB->dibujar();
    segmentoBC->dibujar();
    segmentoCA->dibujar();
    delete segmentoAB;
    delete segmentoBC;
    delete segmentoCA;
}
