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
    Segmento* segmentoAB = new Segmento(this->verticeA->copia(), this->verticeB->copia());
    Segmento* segmentoBC = new Segmento(this->verticeB->copia(), this->verticeC->copia());
    Segmento* segmentoCA = new Segmento(this->verticeC->copia(), this->verticeA->copia());
    segmentoAB->setColorBorde(this->borde->copia());
    segmentoBC->setColorBorde(this->borde->copia());
    segmentoCA->setColorBorde(this->borde->copia());
    segmentoAB->dibujar();
    segmentoBC->dibujar();
    segmentoCA->dibujar();
    delete segmentoAB;
    delete segmentoBC;
    delete segmentoCA;
}

void Triangulo::dibujarPunteado() {
	return dibujar();
}

void Triangulo::rellenar() {
    glColor3f(this->relleno->getRojo(), this->relleno->getVerde(), this->relleno->getAzul());
}
