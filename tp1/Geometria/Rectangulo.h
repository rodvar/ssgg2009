#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "FiguraGeometrica.h"

/**
 * Clase que representa un rectángulo
 */
class Rectangulo : public FiguraGeometrica
{
    public:
        /**
         * Constructor
         * @param centro Es la posicion del centro del rectangulo en la pantalla.
         * @param base La base del rectangulo
         * @param altura La altura del rectangulo
         */
        Rectangulo(float base, float altura, Coordenadas* centro);

        virtual ~Rectangulo();
        float getBase() { return base; }
        float getAltura() { return altura; }
        Coordenadas getCentro() { return *this->centro; }

        /* Devuelve las coordenadas del vertice NorOeste del rectangulo*/
        Coordenadas* getVerticeNO();
        /* Devuelve las coordenadas del vertice NorEste del rectangulo*/
        Coordenadas* getVerticeNE();
        /* Devuelve las coordenadas del vertice SurOeste del rectangulo*/
        Coordenadas* getVerticeSO();
        /* Devuelve las coordenadas del vertice SurEste del rectangulo*/
        Coordenadas* getVerticeSE();

        /**
         * Dibuja el rectangulo en la pantalla actual
         */
        void dibujar();

        /**
         * Rellena el rectangulo del color de relleno seteado
         */
        void rellenar();

        /**
         * Devuelve true si la figura contiene al punto (x,y)
         */
        bool contiene(int x, int y);

    protected:
        float base;
        float altura;
        Coordenadas* centro;
};

#endif // RECTANGULO_H
