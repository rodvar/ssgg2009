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
    this->dibujarBresenham();
    //this->dibujarDDA();
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

void Circunferencia::dibujarDDA(){
    //TODO: Haceme nicaaaa ;)
}
