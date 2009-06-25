#ifndef __PintorCurva_H__
#define __PintorCurva_H__

#include "../Geometria/Coordenadas.h"
#include <vector>

/**
 * @brief Sirve para dibujar una curva.
 */
class PintorCurva
{
    public:

        /** @brief Constructor */
        PintorCurva();

        /** @brief Destructor */
        virtual ~PintorCurva();

        /**
         * @brief Dibuja a la curva.
         * @param puntos Conjunto de puntos de la curva que se quiere dibujar.
         */
        void pintar(std::vector<Coordenadas> &puntos);

        /**
         * @brief Pinta la superficie que forma el contorno de la curva cerrada pasada
         * @param puntos Los puntos que delimitan la curva cerrada
         */
        void pintarSuperficie(std::vector<Coordenadas> &puntos);

        /**
         * @brief Dibuja la superficie que encierran ambas curvas. Toma como normal la perpendicular
         *        puntosA debe corresponder a la curva que se dibuja antes que la de puntosB
         * @pre Ambas curvas deben tener la misma cantidad de puntos
         * @param puntosA,puntosB Los puntos de las curvas A y B
         */
        void pintarGajo(std::vector<Coordenadas> &puntosA, std::vector<Coordenadas> &puntosB);

        /**
         * @brief Pinta los puntos de control.
         * @param cPoints Vector que almacena los puntos de control.
         * @param radius Radio con el que se dibujaran los puntos de control.
         * @param bezierCP True si los puntos de control pertenecen a una curva de Bezier,
         * para que el primer y último punto sean dibujados en verde.
         */
        void pintarPuntosControl(std::vector<Coordenadas>& puntosControl, double radio, bool bezier = false) ;

    private:

    	/**
    	 * @brief Dibuja un círculo relleno.
    	 * @param x Coordenada x del centro.
    	 * @param y Coordenada y del centro.
    	 * @param radius Radio del círculo.
    	 */
    	void dibujarCirculoRelleno(double x,double y,double radius) ;
};

#endif // __PintorCurva_H__
