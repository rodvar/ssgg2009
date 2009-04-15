#include "Segmento.h"
#include "../Motor.h"

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
    glColor3f(this->borde->getRojo(), this->borde->getVerde(), this->borde->getAzul());
    switch (Motor::getInstancia()->getModo()){
        case 'D':
            this->dibujarDDA();
            break;
        case 'B':
            this->dibujarBresenham();
            break;
        default:
            break;
    }
}

void Segmento::dibujarPunteado() {
    glColor3f(this->borde->getRojo(), this->borde->getVerde(), this->borde->getAzul());
    switch (Motor::getInstancia()->getModo()){
        case 'D':
            this->dibujarDDAPunteado();
            break;
        case 'B':
            this->dibujarBresenham();
            break;
        default:
            break;
    }
}

void Segmento::dibujarDDA() {
	int dx = this->hasta->getX()-this->desde->getX();
	int dy = this->hasta->getY()-this->desde->getY();
	int steps, k;
	float xIncrement, yIncrement, x=this->desde->getX(), y=this->desde->getY();
	if (abs(dx)>abs(dy)) {
		steps = abs(dx);
	} else {
		steps = abs(dy);
	}
	xIncrement = dx / (float)steps;
	yIncrement = dy / (float)steps;
	glVertex2i((int)(x+0.5), (int)(y+0.5));
	for(k=0;k<steps;k++) {
		x+=xIncrement;
		y+=yIncrement;
		glVertex2i((int)(x+0.5), (int)(y+0.5));
	}
}

void Segmento::dibujarDDAPunteado() {
	int pixelCounter = 1;
	int canDraw = true;
	int dx = this->hasta->getX()-this->desde->getX();
	int dy = this->hasta->getY()-this->desde->getY();
	int steps, k;
	float xIncrement, yIncrement, x=this->desde->getX(), y=this->desde->getY();
	if (abs(dx)>abs(dy)) {
		steps = abs(dx);
	} else {
		steps = abs(dy);
	}
	xIncrement = dx / (float)steps;
	yIncrement = dy / (float)steps;
	glVertex2i((int)(x+0.5), (int)(y+0.5));
	for(k=0;k<steps;k++) {
		x+=xIncrement;
		y+=yIncrement;
		if(canDraw) {
			glVertex2i((int)(x+0.5), (int)(y+0.5));
		}
		pixelCounter++;
		if(pixelCounter==10) {
			pixelCounter=0;
			canDraw=!canDraw;
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

void Segmento::rellenar() {

}

bool Segmento::contiene(int x, int y){
    //TODO
    return false;
}