#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "Coordenadas.h"

#define INFINITO 10000000

class FiguraGeometrica
{
    public:
        FiguraGeometrica();
        virtual ~FiguraGeometrica();

        /**
         * Metodo abstracto Dibujar.
         * Dibuja la figura en la pantalla de trabajo actual.
         */
        virtual void dibujar() = 0;
    protected:
    private:
};

#endif // FIGURAGEOMETRICA_H
