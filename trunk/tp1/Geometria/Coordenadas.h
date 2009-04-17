#ifndef COORDENADAS_H
#define COORDENADAS_H

#include "GL/glut.h"
#include <math.h>

/**
 * Clase que representa Coordenadas cartesianas sobre un plano de 2 Dimensiones
 */

class Coordenadas
{
    public:
        Coordenadas();
        Coordenadas(int x, int y);
        virtual ~Coordenadas();
        int getX() { return x; }
        void setX(int val) { x = val; }
        int getY() { return y; }
        void setY(int val) { y = val; }

        /**
         * Devuelve una copia de las coordenadas
         */
        virtual Coordenadas* copia(){ return new Coordenadas(this->x,this->y);}

        /**
         * Devuelve TRUE si this tiene mayor o igual valor en x que el parametro c.
         * FALSE en caso contrario
         */
        bool tieneMayorX(Coordenadas* c);

        /**
         * Devuelve las Coordenadas de mayor valor en X
         */
        Coordenadas* mayorX(Coordenadas* c);

        /**
         * Devuelve las Coordenadas de menor valor en X
         */
        Coordenadas* menorX(Coordenadas* c);

        /**
         * Devuelve las Coordenadas de mayor valor en Y
         */
        Coordenadas* mayorY(Coordenadas* c);

        /**
         * Devuelve las Coordenadas de menor valor en Y
         */
        Coordenadas* menorY(Coordenadas* c);

        /**
         * Devuelve la distancia hasta las coordenadas pasadas por parametro
         */
        virtual float distancia (Coordenadas* hasta);

        /** Sobrecarga del operador = **/
        bool operator == (Coordenadas* coordenadas);

    protected:
    private:
        int x;
        int y;
};

#endif // COORDENADAS_H
