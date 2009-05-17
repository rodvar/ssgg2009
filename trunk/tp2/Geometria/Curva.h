#ifndef CURVA_H
#define CURVA_H

#include "FiguraGeometrica.h"
#include <list>
using namespace std;


typedef struct tdcPt3 {
    float x;
    float y;
    float z;
} wcPt3;

class Curva : public FiguraGeometrica
{
    public:
        /**
         * Constructor
         * @brief La curva no se hace responsable por la eliminacion de los puntos de control
         * @param puntosControl Es la lista de puntos de control que definen la curva
         */
        Curva(list<Coordenadas*> puntosControl);
        virtual ~Curva();
        list<Coordenadas*> getPuntosControl() { return this->puntosControl; }

        void dibujar();
        void dibujarPunteado();
        void rellenar();
        bool contiene(int x, int y);

        // Dibuja segun algoritmo de Bezier
        void dibujarBezier();
        // Dibuja segun algoritmo Spline
        void dibujarBSplines();

    protected:
    private:
        list<Coordenadas*> puntosControl;


        //BSpline C
        void bsplineu(int npts,int k,int p1, float b[], float p[]);
        void basis(int c,float t,int npts,int x[],float n[]);
        void knotu(int n,int c,int x[]);

        // Bezier C
        void bezier(int n, int t, wcPt3 *control, wcPt3 *output, int num_output);
        // calcula el valor de la mezcla (blending value)
        double blend(int k, int t, int *u, double v);
        // averigua los nudos
        void compute_intervals(int *u, int n, int t);
        void compute_point(int *u, int n, int t, double v, wcPt3 *control, wcPt3 *output);

        void dibujarCurvaBezier4Puntos(wcPt3 *control);
};

#endif // CURVA_H
