#ifndef GRILLA_H
#define GRILLA_H

#include "../Geometria/Cuadrado.h"
#include "../Geometria/Numero.h"
#include <map>
#include "GL/glut.h"


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
        Coordenadas getOrigen() { return *this->origen; }

        /**
         * Dibuja la grilla en la pantalla actual
         */
        void dibujar();

        /**
         * @param x La coordenada absisa en el SR del hardware
         * @param y La coordenada ordenada en el SR del hardware
         * @return La celda correspondiente en la Grilla, NULL si no existe
         */
        Rectangulo* obtenerCelda(int x, int y);

        /**
         * @param posicion La posicion de la celda en la grilla
         * @return La celda correspondiente en la Grilla, NULL si no existe
         */
        Rectangulo* obtenerCelda(Coordenadas posicion);

        /**
         * Traduce las coordenadas pasadas coomo x,y a las coordenadas en el
         * Sistema de Referencia de la grilla
         */
        Coordenadas posicionEnGrilla(int x, int y);

        /**
         * Si para un cierto valor x, este esta fuera del rango de la grilla, este
         * metodo devuelve el numero de columna donde estaria de existir la celda correspondiente
         */
        int posicionVirtual (const int x);

        /**
         * Devuelve las coordenadas en la grilla de la celda pasada por parametro
         */
        Coordenadas obtenerPosicion(Rectangulo celda);

        /**
         * Devuelve las coordenadas OpenGL de la celda superior derecha
         */
        Coordenadas* getExtremoNE();

        /**
         * Devuelve las coordenadas OpenGL de la celda inferior derecha
         */
        Coordenadas* getExtremoSE();

        /**
         * @return La distancia al origen de la grilla
         * @param punto El punto distante al origen
         */
        float distanciaOrigen(Coordenadas punto);

        /**
         * @return TRUE si es un punto perteneciente a la grilla, false en caso
         *         contrario
         */
        bool enRango(int x, int y);

        // Deja los valores por defecto de las celdas
        void regenerar();

    protected:
    private:
        int filas,columnas,unidadX,unidadY;
        Coordenadas* origen;
        // La clave del mapa es la coordenada que tiene sentido para la grilla.
        // Ademas el valor, tiene su propia coordenada donde se dibuja
        map<Coordenadas*,Rectangulo*> mapa;
        //map<Coordenadas*,Rectangulo*, bool(*)(Coordenadas*,Coordenadas*)> mapa; Probar esto!

        // Dibuja el eje X,Y de acuerdo a la poscion de la grilla
        void dibujarEjeX();
        void dibujarEjeY();
};

#endif // GRILLA_H
