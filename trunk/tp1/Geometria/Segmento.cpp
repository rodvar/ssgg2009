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
    float pendiente = 0;
    Coordenadas* inicio = this->desde;
    Coordenadas* fin = this->hasta;
    int dx, dy;
    if (this->desde->mayorX(this->hasta)){
        inicio = this->hasta;
        fin = this->desde;
    }
    dy = fin->getY() - inicio->getY();
    dx = fin->getX() - inicio->getX();
    if (dx == 0)
        pendiente = INFINITO;
    else
        pendiente = (float)(dy)/(dx);
    return pendiente;
}

double Segmento::longitud(){
    return (this->desde->distancia(hasta));
}

void Segmento::dibujar(){
    //this->dibujarDDA();
    this->dibujarBresenham();
}

void Segmento::dibujarDDA() {
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

void Segmento::dibujarBresenham() {
    unsigned int x0 = floor(this->desde->getX());
    unsigned int y0 = floor(this->desde->getY());
    unsigned int x1 = floor(this->hasta->getX());
    unsigned int y1 = floor(this->hasta->getY());

    int dx = x1 - x0;
    int dy = y1 - y0;

    glVertex2i(x0,y0);
    if (abs(dx) > abs(dy)) {          // pendiente < 1
        float m = (float) dy / (float) dx;
        float b = y0 - m*x0;
        if(dx<0) {
            dx = -1;
        } else {
            dx =  1;
        }
        while (x0 != x1) {
            x0 += dx;
            y0 = round(m*x0 + b);
            glVertex2i(x0,y0);
        }
    } else {
        if (dy != 0) {
            float m = (float) dx / (float) dy;
            float b = x0 - m*y0;
            if(dy<0) {
                dy = -1;
            } else {
                dy = 1;
            }
            while (y0 != y1) {
                y0 += dy;
                x0 = round(m*y0 + b);
                glVertex2i(x0,y0);
            }
        }
    }
}
