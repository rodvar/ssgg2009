#ifndef CURVA_H
#define CURVA_H

#include "FiguraGeometrica.h"
#include <list.h>


typedef struct tdcPt3 {
    int x;
    int y;
    int z;
} wcPt3;
class Curva : public FiguraGeometrica
{
    public:
        /**
         * Constructor
         * @param puntosControl Es la lista de puntos de control que definen la curva
         */
        Curva(list<Coordenadas> puntosControl);
        virtual ~Curva();
        list<Coordenadas> getPuntosControl() { return this->puntosControl; }


        void dibujar();
        void dibujarPunteado();
        void rellenar();
        bool contiene(int x, int y);

    protected:
    private:
        list<Coordenadas> puntosControl;

        // Dibuja segun algoritmo de Bezier
        void dibujarBezier();
        // Dibuja segun algoritmo Spline
        void dibujarSplines();

        // Bezier C
        void computeCoefficients(int n, int* c);
        void computePoint(float u, wcPt3* pt,  int ncontrols, wcPt3* controls, int* c);
        void bezier(wcPt3* controls, int ncontrols, int m, wcPt3* curve);
};

#endif // CURVA_H
