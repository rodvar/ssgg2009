#ifndef CURVA_H
#define CURVA_H

#include "FiguraGeometrica.h"
#include <list>
using namespace std;


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
        Curva(list<Coordenadas*> puntosControl);
        virtual ~Curva();
        list<Coordenadas*> getPuntosControl() { return this->puntosControl; }

        void dibujar();
        void dibujarPunteado();
        void rellenar();
        bool contiene(int x, int y);

    protected:
    private:
        list<Coordenadas*> puntosControl;

        // Dibuja segun algoritmo de Bezier
        void dibujarBezier();
        // Dibuja segun algoritmo Spline
        void dibujarBSplines();

        // Bezier C
        void computeCoefficients(int n, int* c);
        void computePoint(float u, wcPt3* pt,  int ncontrols, wcPt3* controls, int* c);
        void bezier(wcPt3* controls, int ncontrols, int m, wcPt3* curve);
        // Bsplines C
        /*********************************************************************
        Parametros:
          n          - cantidad de puntos de control menos 1
          t          - el grado del polinomio mas 1
          control    - vector de puntos de control proveniente de una estructura de tipo wcPt3
          output     - vector en el cual se insertan los puntos calculados por el spline
          num_output - cantidad de puntos a calcular por el spline

        Pre-condiciones:
          n+2>t  (no hay resultados de la curva si n+2<=t)
          el vector control contiene la cantidad de puntos especificados por el parametro n
          el vector output tiene el tamaño adecuado para soportar num_output puntos
        **********************************************************************/
        void bspline(int n, int t, wcPt3 *control, wcPt3 *output, int num_output);
        // calcula el valor de la mezcla (blending value)
        double blend(int k, int t, int *u, double v);
        // averigua los nudos
        void compute_intervals(int *u, int n, int t);
        void compute_point(int *u, int n, int t, double v, wcPt3 *control, wcPt3 *output);

};

#endif // CURVA_H
