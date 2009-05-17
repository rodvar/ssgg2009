#include "Triangulo.h"
#include "Segmento.h"
#include "../Visualizacion/Scanline.h"

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
    segmentoAB->setColorBorde(this->borde);
    segmentoBC->setColorBorde(this->borde);
    segmentoCA->setColorBorde(this->borde);
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
    if (this->esRellenable){
        Scanline scanline;
        int cnt=3;

        dcPt *PolyVertices;
        PolyVertices = (dcPt *)calloc(cnt, sizeof(dcPt));

        PolyVertices[0].x = this->verticeA->getX(); PolyVertices[0].y = this->verticeA->getY();
        PolyVertices[1].x = this->verticeB->getX(); PolyVertices[1].y = this->verticeB->getY();
        PolyVertices[2].x = this->verticeC->getX(); PolyVertices[2].y = this->verticeC->getY();

        glColor3f(this->relleno.getRojo(), this->relleno.getVerde(), this->relleno.getAzul());
        scanline.scanFill(cnt,PolyVertices);

        delete PolyVertices;
    }
}

bool Triangulo::contiene(int x, int y){
    return false;
}
