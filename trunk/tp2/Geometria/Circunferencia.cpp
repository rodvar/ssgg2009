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
    glColor3f(this->borde.getRojo(), this->borde.getVerde(), this->borde.getAzul());

    float angle;
    glDisable(GL_LIGHTING);
    glBegin(GL_LINE_LOOP);
    for(int i=0; i<100; i++) {
		angle = i*2*M_PI/100;
		glVertex3f(this->centro->getX() + (cos(angle) * this->radio), this->centro->getY() + (sin(angle) * this->radio), 0.0);
		for(float j=0;j<this->radio;j=j+((float)this->radio/10)) {
			glVertex3f(this->centro->getX() + (cos(angle) * j), this->centro->getY() + (sin(angle) * j), 0.0);
		}
	}
    glEnd();
    glEnable(GL_LIGHTING);
}

void Circunferencia::dibujarPunteado() {
	return dibujar();
}

void Circunferencia::dibujarBresenham(){
    float x, y, e;
    float xCentro = this->centro->getX();
    float yCentro = this->centro->getY();
    x = this->radio;
    y = 0;
    e = 0;

    glDisable(GL_LIGHTING);
	glBegin(GL_POINTS);

    while ( y <= x) {
        glVertex3f(xCentro + x, yCentro + y, 0); glVertex3f(xCentro + y, yCentro + x, 0);
        glVertex3f(xCentro - x, yCentro + y, 0); glVertex3f(xCentro - y, yCentro + x, 0);
        glVertex3f(xCentro + x, yCentro - y, 0); glVertex3f(xCentro + y, yCentro - x, 0);
        glVertex3f(xCentro - x, yCentro - y, 0); glVertex3f(xCentro - y, yCentro - x, 0);
        e = e + 2*y + 0.000976;
        y=y+0.000976;
        if ( 2*e > ( 2*x - 0.000976)) {
        	x=x-0.000976;
            e = e - 2*x + 0.000976;
        }
    }

    glEnd();
    glEnable(GL_LIGHTING);
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

    if (this->esRellenable){
        glColor3f(this->relleno.getRojo(), this->relleno.getVerde(), this->relleno.getAzul());

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
