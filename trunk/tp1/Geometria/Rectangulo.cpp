#include "Rectangulo.h"
#include "Segmento.h"
#include <stdio.h>

Rectangulo::Rectangulo(float base, float altura, Coordenadas* centro)
{
    this->base = base;
    this->altura = altura;
    this->centro = centro;
}

Rectangulo::~Rectangulo()
{
    delete this->centro;
}

Coordenadas* Rectangulo::getVerticeNO(){
    int x = this->centro->getX() - floor(this->base/2);
    int y = this->centro->getY() - floor(this->altura/2);
    return new Coordenadas(x,y);
}

Coordenadas* Rectangulo::getVerticeNE(){
    int x = this->centro->getX() + floor(this->base/2);
    int y = this->centro->getY() - floor(this->altura/2);
    return new Coordenadas(x,y);
}

Coordenadas* Rectangulo::getVerticeSO(){
    int x = this->centro->getX() - floor(this->base/2);
    int y = this->centro->getY() + floor(this->altura/2);
    return new Coordenadas(x,y);
}

Coordenadas* Rectangulo::getVerticeSE(){
    int x = this->centro->getX() + floor(this->base/2);
    int y = this->centro->getY() + floor(this->altura/2);
    return new Coordenadas(x,y);
}

void Rectangulo::dibujar(){
    glColor3f(this->borde->getRojo(), this->borde->getVerde(), this->borde->getAzul());
    Segmento* baseSur = new Segmento(this->getVerticeSO(), this->getVerticeSE());
    Segmento* baseNorte = new Segmento(this->getVerticeNE(), this->getVerticeNO());
    Segmento* alturaOeste = new Segmento(this->getVerticeNO(), this->getVerticeSO());
    Segmento* alturaEste = new Segmento(this->getVerticeSE(), this->getVerticeNE());
    baseSur->setColorBorde(this->borde->copia());
    baseNorte->setColorBorde(this->borde->copia());
    alturaEste->setColorBorde(this->borde->copia());
    alturaOeste->setColorBorde(this->borde->copia());
    baseSur->dibujar();
    alturaEste->dibujar();
    baseNorte->dibujar();
    alturaOeste->dibujar();
    delete baseSur;
    delete baseNorte;
    delete alturaEste;
    delete alturaOeste;
    this->rellenar();
}

void Rectangulo::dibujarPunteado() {
    glColor3f(this->borde->getRojo(), this->borde->getVerde(), this->borde->getAzul());
    Segmento* baseSur = new Segmento(this->getVerticeSO(), this->getVerticeSE());
    Segmento* baseNorte = new Segmento(this->getVerticeNE(), this->getVerticeNO());
    Segmento* alturaOeste = new Segmento(this->getVerticeNO(), this->getVerticeSO());
    Segmento* alturaEste = new Segmento(this->getVerticeSE(), this->getVerticeNE());
    baseSur->setColorBorde(this->borde->copia());
    baseNorte->setColorBorde(this->borde->copia());
    alturaEste->setColorBorde(this->borde->copia());
    alturaOeste->setColorBorde(this->borde->copia());
    baseSur->dibujarPunteado();
    alturaEste->dibujarPunteado();
    baseNorte->dibujarPunteado();
    alturaOeste->dibujarPunteado();
    delete baseSur;
    delete baseNorte;
    delete alturaEste;
    delete alturaOeste;
    this->rellenar();
}

void Rectangulo::rellenar() {
    if (this->relleno){
        glColor3f(this->relleno->getRojo(), this->relleno->getVerde(), this->relleno->getAzul());

        /*Scanline* scanline = new Scanline();
        Coordenadas* coordenadaNO = getVerticeNO();
        int cnt=4;

        dcPt *PolyVertices;
        PolyVertices = (dcPt *)calloc(cnt, sizeof(dcPt));

        PolyVertices[0].x = coordenadaNO->getX(); PolyVertices[0].y = coordenadaNO->getY();
        PolyVertices[1].x = coordenadaNO->getX()+this->base; PolyVertices[1].y = coordenadaNO->getY();
        PolyVertices[2].x = coordenadaNO->getX()+this->base; PolyVertices[2].y = coordenadaNO->getY() + this->altura;
        PolyVertices[3].x = coordenadaNO->getX(); PolyVertices[3].y = coordenadaNO->getY() + this->altura;

        scanline->scanFill(cnt,PolyVertices);

        delete PolyVertices;
        delete coordenadaNO;
        */

        Coordenadas* coordenadaNO = getVerticeNO();
        for(int j=(coordenadaNO->getY()+1);j<(this->altura+coordenadaNO->getY());j++) {
            for(int i=(coordenadaNO->getX()+1);i<(this->base+coordenadaNO->getX());i++) {
                glVertex2i(i,j);
            }
        }
        delete coordenadaNO;
    }
}

bool Rectangulo::contiene(int x, int y){
    Coordenadas* so = this->getVerticeSO();
    Coordenadas* ne = this->getVerticeNE();
    bool contenido = ((x >= so->getX()) && (x <= ne->getX())
                    && (y <= so->getY()) && (y >= ne->getY()));
    delete so;
    delete ne;
    return contenido;
}
