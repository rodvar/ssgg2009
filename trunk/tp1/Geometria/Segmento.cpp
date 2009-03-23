#include "Segmento.h"

Segmento::Segmento(Coordenadas* desde, Coordenadas* hasta)
{
    this->desde = desde;
    this->hasta = hasta;
}

Segmento::~Segmento()
{
    delete this->desde;
    delete this->hasta;
}

float Segmento::pendiente(){
    // TODO
    return 0;
}

void Segmento::dibujar(){
    this->dibujarDDA();
    //this->dibujarBresenham();
}

void Segmento::dibujarDDA(){
    unsigned int x = this->desde->getX();
    unsigned int y = this->desde->getY();
    unsigned int fin;

    if (this->hasta->getY() == y){ //paralela eje x
        fin = this->hasta->getX();
        if (x > this->hasta->getX()){
            fin = x;
            x = this->hasta->getX();
        }
        for ( unsigned int i = x ; i < fin; i++)
            glVertex2i(i, y);
    }
    else if (this->hasta->getX() == x){//paralela eje y
        fin = this->hasta->getY();
        if (y > this->hasta->getY()){
            fin = y;
            y = this->hasta->getY();
        }
        for (unsigned int i = y; i < fin; i++)
            glVertex2i(x, i);
    }
    else{
        int deltay = this->hasta->getY() - y;
        int deltax = this->hasta->getX() - x;
        float pendiente = (float)deltay/deltax;
        if (fabs(pendiente) < 1){ // x guia
            float yReal = (float)y;
            fin = this->hasta->getX();
            if (x > this->hasta->getX()){
                fin = x;
                x = this->hasta->getX();
                yReal = (float)this->hasta->getY();
            }
            for (unsigned int i = x; i < fin; i++){
                glVertex2i(i, y);
                yReal = yReal + pendiente;
                y = floor(yReal);
            }
        }
        else{// y guia
            float xReal = (float)x;
            float paso = (1/pendiente);
            fin = this->hasta->getY();
            if (y > this->hasta->getY()){
                fin = y;
                y = this->hasta->getY();
                xReal = (float)this->hasta->getX();
            }
            for (unsigned int i = y; i <fin; i++){
                glVertex2i(x, i);
                xReal = xReal + paso;
                x = floor(xReal);
            }
        }
    }
}

void Segmento::dibujarBresenham(){
    //TODO: haceme nico!! jaja
}
