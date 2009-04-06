#ifndef CIRCUNFERENCIA_H
#define CIRCUNFERENCIA_H

#include "FiguraGeometrica.h"

/**
 * Clase que representa una circunferencia en el plano 2D
**/

class Circunferencia : public FiguraGeometrica
{
public:
    /**
     * @param radio Es el radio de la circunferencia
     * @param centro Las coordenadas del centro de la misma
     * @note Se hace responsable por la destruccion del centro
     */
    Circunferencia(float radio, Coordenadas* centro);

    virtual ~Circunferencia();
    float getRadio() { return radio; }
    unsigned int getXCentro(){ return this->centro->getX(); }
    unsigned int getYCentro(){ return this->centro->getY(); }

    /**
     * Dibuja la circunferencia en la pantalla actual
     */
    void dibujar();

    /**
     * Rellena la circunferencia en la pantalla actual
     */
    void rellenar();

    /**
     * Devuelve true si la figura contiene al punto (x,y)
     */
    bool contiene(int x, int y);

protected:
private:
    // Dibuja por el algoritmo DDA
    void dibujarDDA();
    // Dibuja por el algoritmo Bresenham
    void dibujarBresenham();

    // Variables miembro
    float radio;
    Coordenadas* centro;
};

#endif // CIRCUNFERENCIA_H
