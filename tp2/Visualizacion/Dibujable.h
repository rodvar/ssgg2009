#ifndef DIBUJABLE_H
#define DIBUJABLE_H

#include <stdlib.h>
#include "Color.h"
#include <GL/glut.h>

/**
 * Clase abstracta que define el comportamiento que debe tener todo elemento
 * que se pueda dibujar, incluyendo sus 2 posibles colores
 */
class Dibujable
{
    public:
        /** CONSTRUCTOR **/
        Dibujable();
        /** DESTRUCTOR **/
        virtual ~Dibujable();

        /** Dibujar el elemento dibujable **/
        virtual void dibujar() = 0;

        // Getters colores
        Color getColorBorde() { return this->borde; }
        Color getColorRelleno() { return this->relleno; }
        // Setters colores
        void setColorBorde(Color color);
        void setColorRelleno(Color color);
        void setColorRelleno(float r, float g, float b);
        void quitarColorRelleno() { this->esRellenable = false; }

    protected:
        Color borde;
        Color relleno;
        bool esRellenable;
};

#endif // DIBUJABLE_H
