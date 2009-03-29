#include "Circunferencia.h"

Circunferencia::Circunferencia(float radio, Coordenadas* centro)
{
    this->radio = radio;
    this->centro = centro;
}

Circunferencia::~Circunferencia()
{
    delete this->centro;
}

void Circunferencia::dibujar(){
    glColor3f(this->borde->getRojo(), this->borde->getVerde(), this->borde->getAzul());
    this->dibujarBresenham();
}

void Circunferencia::dibujarBresenham(){
    int x, y, e;
    unsigned int xCentro = this->centro->getX();
    unsigned int yCentro = this->centro->getY();
    x = floor(this->radio);
    y = 0;
    e = 0;
    while ( y <= x) {
        glVertex2i(xCentro + x, yCentro + y ); glVertex2i(xCentro + y, yCentro + x );
        glVertex2i(xCentro - x, yCentro + y ); glVertex2i(xCentro - y, yCentro + x );
        glVertex2i(xCentro + x, yCentro - y ); glVertex2i(xCentro + y, yCentro - x );
        glVertex2i(xCentro - x, yCentro - y ); glVertex2i(xCentro - y, yCentro - x );
        e = e + 2*y + 1;
        y++;
        if ( 2*e > ( 2*x - 1)) {
            x--;
            e = e - 2*x + 1;
        }
    }
}

void Circunferencia::dibujarDDA() {
    int x, y, r2;
    int xCenter = this->centro->getX();
    int yCenter = this->centro->getY();

    r2 = radio*radio;
    glVertex2i(xCenter, yCenter + radio);
    glVertex2i(xCenter, yCenter - radio);
    glVertex2i(xCenter + radio, yCenter);
    glVertex2i(xCenter - radio, yCenter);

    y = radio;
    x = 1;
    y = (int) (sqrt(r2 - 1) + 0.5);
    while (x < y) {
        glVertex2i(xCenter + x, yCenter + y); glVertex2i(xCenter + x, yCenter - y);
        glVertex2i(xCenter - x, yCenter + y); glVertex2i(xCenter - x, yCenter - y);
        glVertex2i(xCenter + y, yCenter + x); glVertex2i(xCenter + y, yCenter - x);
        glVertex2i(xCenter - y, yCenter + x); glVertex2i(xCenter - y, yCenter - x);
        x += 1;
        y = (int) (sqrt(r2 - x*x) + 0.5);
    }
    if (x == y) {
        glVertex2i(xCenter + x, yCenter + y);
        glVertex2i(xCenter + x, yCenter - y);
        glVertex2i(xCenter - x, yCenter + y);
        glVertex2i(xCenter - x, yCenter - y);
    }
}

void Circunferencia::rellenar() {
    glColor3f(this->relleno->getRojo(), this->relleno->getVerde(), this->relleno->getAzul());
}
