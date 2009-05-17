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
    if (this->desde->tieneMayorX(this->hasta)){
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
    return (this->desde->distancia(*hasta));
}

void Segmento::dibujar(){
    glColor3f(this->borde.getRojo(), this->borde.getVerde(), this->borde.getAzul());
    glLineWidth(1); // ancho!
    glDisable(GL_LIGHTING);
    glBegin(GL_LINES);
        glVertex3f(this->desde->getX(), this->desde->getY(), this->desde->getZ());
        glVertex3f(this->hasta->getX(), this->hasta->getY(), this->hasta->getZ());
    glEnd();
    glEnable(GL_LIGHTING);
}

void Segmento::dibujarPunteado() {
    glEnable(GL_LINE_STIPPLE);
    glLineStipple (4, 0xAAAA);
    glColor3f(1,1,1);
    glBegin (GL_LINES);
		glVertex3f(this->desde->getX(), this->desde->getY(), this->desde->getZ());
		glVertex3f(this->hasta->getX(), this->hasta->getY(), this->hasta->getZ());
    glEnd();
    glDisable(GL_LINE_STIPPLE);
}

void Segmento::rellenar() {

}

bool Segmento::contiene(int x, int y){
    //TODO
    return false;
}
