#ifndef BEZIER_CURVE_PAINTER_H
#define BEZIER_CURVE_PAINTER_H

#include "CalculadorCurva.h"
#include <stdexcept>
#include <exception>

/**
 * @brief Se encarga del cálculo de puntos de una curva utilizando el metodo de Bezier.
 */
class CalculadorBezier : public CalculadorCurva{
    public:

        /** @brief Constructor */
        CalculadorBezier(unsigned int cantidadPuntos);

        /** @brief Destructor */
        virtual ~CalculadorBezier();

        /**
         * @brief Calcula los puntos de la curva.
         * @return Vector con los puntos de la curva calculados.
         */
        std::vector<Coordenadas> calcularPuntos();

        /**
		 * @brief Establece los puntos de control de la curva.
		 * @param control_points Puntos de control a establecerle a la curva.
		 */
        void setPuntosControl(const std::vector<Coordenadas> &control_points)
        throw(std::runtime_error) ;

    private:

        /**
        * @brief Computa los puntos.
        */
        void computePoint(float u, Coordenadas *point, int *c, std::vector<Coordenadas> temp);

        /**
        * @brief Calcula los coeficientes de las bases de Berstein.
        */
        void computeCoefficients(int n, int *c);

        /**
         * @brief Calcula bezier para un número reducido de puntos y los carga en un vector
         */
        void loadCurvePoints(std::vector<Coordenadas>& curveP,const std::vector<Coordenadas>& controlP) ;

};

#endif // BEZIER_CURVE_PAINTER_H
