#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "Coordenadas.h"

#define INFINITO 10000000

class FiguraGeometrica : public Dibujable
{
    public:
        /**
         * Metodo abstracto Dibujar.
         * Dibuja la figura en la pantalla de trabajo actual.
         */
        virtual void dibujar() = 0;

        /**
         * Metodo abstracto Dibujar.
         * Dibuja la figura en la pantalla de trabajo actual.
         */
        virtual void dibujarPunteado() = 0;

        /**
         * Metodo abstracto Rellenar.
         * Rellena la figura en la pantalla de trabajo actual.
         */
        virtual void rellenar() = 0;

        /**
         * Metodo abstracto contiene (x,y)
         * Devuelve true si la figura contiene al punto (x,y)
         */
        virtual bool contiene(int x, int y) = 0;
};

#endif // FIGURAGEOMETRICA_H
