#include "Letra.h"
#include "Segmento.h"

Letra::Letra(Coordenadas* centro, char letra)
{
    this->borde = new Color(0,0,0);
    this->centro = centro;
    this->letra = letra;
}

Letra::~Letra()
{
    delete this->centro;
}

void Letra::setColor(Color* color){
    this->setColorBorde(color);
}

void Letra::dibujar(){
    switch (this->letra){
        case 'E':
            int x = this->centro->getX();
            int y = this->centro->getY();
            Segmento* horizontal = new Segmento(new Coordenadas(x,y), new Coordenadas(x+10,y));
            Segmento* horizontalN = new Segmento(new Coordenadas(x,y-5), new Coordenadas(x+10,y-5));
            Segmento* horizontalS = new Segmento(new Coordenadas(x,y+5), new Coordenadas(x+10,y+5));
            Segmento* vertical = new Segmento(new Coordenadas(x,y-5), new Coordenadas(x,y+5));
            horizontal->setColorBorde(this->borde->copia());
            horizontalN->setColorBorde(this->borde->copia());
            horizontalS->setColorBorde(this->borde->copia());
            vertical->setColorBorde(this->borde->copia());
            horizontal->dibujar();
            horizontalN->dibujar();
            horizontalS->dibujar();
            vertical->dibujar();
            delete horizontal;
            delete horizontalN;
            delete horizontalS;
            delete vertical;
        break;
    }
}

void Letra::dibujarPunteado() {
	return dibujar();
}

void Letra::rellenar(){

}

bool Letra::contiene(int x, int y){
    return false;
}
