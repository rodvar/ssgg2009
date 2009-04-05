#ifndef GRILLA_H
#define GRILLA_H

#include "../Geometria/Cuadrado.h"
#include <map.h>


#define ORIGEN_X 60
#define ORIGEN_Y 517
#define ANCHO	800
#define ALTO	600

using namespace std;

class Grilla
{
    public:
        /**
         * Constructor
         * La grilla queda construida en la posicion "origen"
         * @param filas Es la cantidad de filas de la grilla. Minimo 1
         * @param filas Es la cantidad de columnas de la grilla. Minimo 1
         * @param dx Es la minima medida de una celda en direccion x
         * @param dy Es la minima medida de una celda en direccion y
         * @param posicion Es la posicion NorOeste de la grilla para ubicarla en pantalla
         */
        Grilla(int filas, int columnas, float dx, float dy, Coordenadas* posicion);

        virtual ~Grilla();

        /**
         * Dibuja la grilla en la pantalla actual
         */
        void dibujar();

        /**
         * @param x La coordenada absisa en el SR del hardware
         * @param y La coordenada ordenada en el SR del hardware
         * @return La celda correspondiente en la Grilla, NULL si no existe
         */
        Rectangulo* obtenerCelda(float x, float y);

    protected:
    private:
        int filas,columnas,unidadX,unidadY;
        Coordenadas* origen;
        // La clave del mapa es la coordenada que tiene sentido para la grilla.
        // Ademas el valor, tiene su propia coordenada donde se dibuja
        map<Coordenadas*,Rectangulo*> mapa;

        // Dibuja el eje X,Y de acuerdo a la poscion de la grilla
        void dibujarEjeX();
        void dibujarEjeY();
};

#endif // GRILLA_H
