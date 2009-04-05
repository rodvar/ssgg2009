#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H

#include "Coordenadas.h"
#include "../Visualizacion/Color.h"

#define INFINITO 10000000

class FiguraGeometrica
{
    public:
        // Contructor: Crea con color de relleno por defecto NULL, y de borde Blanco
        FiguraGeometrica();
        virtual ~FiguraGeometrica();

        /**
         * Metodo abstracto Dibujar.
         * Dibuja la figura en la pantalla de trabajo actual.
         */
        virtual void dibujar() = 0;

        /**
         * Metodo abstracto Rellenar.
         * Rellena la figura en la pantalla de trabajo actual.
         */
        virtual void rellenar() = 0;

        /**
         * Metodo abstracto contiene (x,y)
         * Devuelve true si la figura contiene al punto (x,y)
         */
        virtual bool contiene(float x, float y) = 0;

        // Getters colores
        Color* getColorBorde() { return this->borde; }
        Color* getColorRelleno() { return this->relleno; }
        // Setters colores
        void setColorBorde(Color* color);
        void setColorRelleno(Color* color);

    protected:
        Color* borde;
        Color* relleno;
    private:
};

#endif // FIGURAGEOMETRICA_H
