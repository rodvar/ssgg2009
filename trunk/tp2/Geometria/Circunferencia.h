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
    float getXCentro(){ return this->centro->getX(); }
    float getYCentro(){ return this->centro->getY(); }

    /**
     * Calcula la coordenada x perteneciente a la circunferencia, correspondiente al Y pasado por parametro
     * @param y Es el la ordenada al origen del punto cuyo x quiero calcular
     * @param positivo Si es TRUE, devuelve el X a derecha del centro, el izq en caso contrario
     */
    double calcularX(int y, bool positivo);

    /**
     * Devuelve la distancia a la circunferencia paralela al eje X del punto c
     */
    double distanciaX(Coordenadas c);

    /**
     * Dibuja la circunferencia en la pantalla actual
     */
    void dibujar();

    /**
     * Dibuja la circunferencia punteada en la pantalla actual
     */
    void dibujarPunteado();

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
    // True si el valor y esta comprendido dentro de los valores posible de la circunferencia
    bool enRangoY(int y);

    // Variables miembro
    float radio;
    Coordenadas* centro;
};

#endif // CIRCUNFERENCIA_H
