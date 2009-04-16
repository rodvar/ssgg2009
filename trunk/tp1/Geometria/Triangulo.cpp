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
    this->rellenar();
}

void Triangulo::dibujarPunteado() {
	return dibujar();
}

void Triangulo::rellenar() {
    int yMin,yMax,xMin,xMax;
    Coordenadas* coordenadas;
    if (this->relleno){
        glColor3f(this->relleno->getRojo(), this->relleno->getVerde(), this->relleno->getAzul());
        /* TODO
            Hay q hacer un preprocesamiento antes de pintar para ver los limites desde
            y hasta de X para cada Y del triangulo! (se puede usar una matriz entera
            de Y filas por 2 columnas (Xmin, Xmax)
        */
        /*coordenadas = this->verticeA->menorY(this->verticeB);
        coordenadas = this->verticeC->menorY(coordenadas);
        yMin = coordenadas->getY();
        coordenadas = this->verticeA->mayorY(this->verticeB);
        coordenadas = this->verticeC->mayorY(coordenadas);
        yMax = coordenadas->getY();
        coordenadas = this->verticeA->menorX(this->verticeB);
        coordenadas = this->verticeC->menorX(coordenadas);
        xMin = coordenadas->getX();
        coordenadas = this->verticeA->mayorX(this->verticeB);
        coordenadas = this->verticeC->mayorX(coordenadas);
        xMax = coordenadas->getX();*/

    }
}

bool Triangulo::contiene(int x, int y){
    return false;
}
