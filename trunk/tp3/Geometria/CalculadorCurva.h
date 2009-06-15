#ifndef CURVECALCULATOR_H
#define CURVECALCULATOR_H

#include <vector>
#include "Coordenadas.h"

/**
* @brief Define una interfaz para calcular los puntos de una curva por diferentes metodos.
*/
class CalculadorCurva
{
    public:

        /**
         * @brief Constructor.
         * @param numberOfCurvePoints Numero de puntos de la curva.
         */
        CalculadorCurva(int numberOfCurvePoints);

        /**
         * @brief Constructor.
         * @param numberOfCurvePoints Numero de puntos de la curva.
         * @param pC Puntos de control de la curva.
         */
        CalculadorCurva(int numberOfCurvePoints, std::vector<Coordenadas> &pC) ;

        /** @brief Destructor */
        virtual ~CalculadorCurva();

        /**
         * @brief Establece el numero de puntos de la curva.
         * @param numberOfCurvePoints Numero de puntos de la curva.
         */
        void setNumberOfCurvePoints(int numberOfCurvePoints);

        /**
         * @brief Devuelve el numero de puntos de la curva.
         * @return Numero de puntos de la curva.
         */
        int getNumberOfCurvePoints() const;

        /**
         * @brief Establece los puntos de control de la curva.
         * @param control_points Puntos de control a establecerle a la curva.
         */
        void setControlPoints(std::vector<Coordenadas> control_points);

        /**
         * @brief Devuelve los puntos de control de la curva.
         * @return Puntos de control de la curva.
         */
        std::vector<Coordenadas> getControlPoints() const;

        /**
         * @brief Calcula los puntos de la curva.
         * @return Vector con los puntos de la curva calculados.
         */
        virtual std::vector<Coordenadas> calcularPuntos() = 0;


    protected:

        /** @brief Numero de puntos de la curva. */
        int numberOfCurvePoints;

        /// @brief Puntos de control de la curva.
        std::vector<Coordenadas> control_points;

};

#endif // CURVECALCULATOR_H
