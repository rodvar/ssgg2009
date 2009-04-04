#ifndef GRILLA_H
#define GRILLA_H

#include "../Geometria/Cuadrado.h"
#include <map.h>

using namespace std;

class Grilla
{
    public:
        /**
         * Constructor
         * @param filas Es la cantidad de filas de la grilla. Minimo 1
         * @param filas Es la cantidad de columnas de la grilla. Minimo 1
         * @param dx Es la minima medida de una celda en direccion x
         * @param dy Es la minima medida de una celda en direccion y
         */
        Grilla(int filas, int columnas, float dx, float dy);

        virtual ~Grilla();

        /**
         * Dibuja la grilla en la pantalla actual
         */
        void dibujar();

    protected:
    private:
        // La clave del mapa es la coordenada que tiene sentido para la grilla.
        // Ademas el valor, tiene su propia coordenada donde se dibuja
        map<Coordenadas*,Rectangulo*> mapa;
};

#endif // GRILLA_H
