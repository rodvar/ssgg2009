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

void Circunferencia::dibujarPunteado() {
	return dibujar();
}

void Circunferencia::dibujarBresenham(){
    int x, y, e;
    unsigned int xCentro = this->centro->getX();
    unsigned int yCentro = this->centro->getY();
    x = floor(this->radio);
    y = 0;
    e = 0;

	glBegin(GL_POINTS);

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

    glEnd();
}

void Circunferencia::dibujarDDA() {
    int x, y, r2;
    int xCenter = this->centro->getX();
    int yCenter = this->centro->getY();

    r2 = radio*radio;

	glBegin(GL_POINTS);

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

    glEnd();
}

void Circunferencia::rellenar() {
	glBegin(GL_POINTS);

    if (this->relleno){
        glColor3f(this->relleno->getRojo(), this->relleno->getVerde(), this->relleno->getAzul());

    }

    glEnd();
}

bool Circunferencia::contiene(int x, int y){
    //TODO
    return false;
}

double Circunferencia::calcularX(int y, bool positivo){
    double x = this->centro->getX();

    if (this->enRangoY(y)){
        y -= this->centro->getY();
        if (positivo)
            x += sqrt(this->radio*this->radio - y*y);
        else
            x -= sqrt(this->radio*this->radio - y*y);
    }
    return x;
}

double Circunferencia::distanciaX(Coordenadas c){
    double x = this->calcularX(c.getY(), true);
    return (c.getX() - x);
}

bool Circunferencia::enRangoY(int y ){
    return ((y >= (this->centro->getY() - this->radio)) && (y <= (this->centro->getY() + this->radio)));
}
