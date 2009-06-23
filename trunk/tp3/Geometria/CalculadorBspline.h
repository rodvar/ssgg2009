#ifndef __BSPLINECURVEPAINTER_H__
#define __BSPLINECURVEPAINTER_H__

#include "CalculadorCurva.h"
#include <stdexcept>
#include <exception>

/**
 * @brief Se encarga del cálculo de puntos de una curva utilizando el metodo de BSpline cúbica,
 * con k=4 (orden) y bases de grado 3 (polinomios cúbicos)
 */
class CalculadorBspline : public CalculadorCurva
{
	private:
		/** Almacena los puntos totales de toda la curva, que es unión de varias BSpline */
		std::vector<Coordenadas> curvePoints ;

    public:

        /** @brief Constructor */
    	CalculadorBspline(unsigned int nroCurvePoints);
    	CalculadorBspline(unsigned int nroCurvePoints,
    			std::vector<Coordenadas>& pC) throw(std::runtime_error) ;

        /** @brief Destructor */
        virtual ~CalculadorBspline();

        /**
         * @brief Establece los puntos de control de la curva, deben ser 4 o más y
         * además internamente calcula el vector resultado para graficar la curva según
         * esos puntos de control. También calcula internamente la posición de los árboles.
         * @param control_points Puntos de control a establecerle a la curva.
         */
        void setControlPoints(const std::vector<Coordenadas> &control_points)
        throw(std::runtime_error) ;

        /**
         * @brief Obtenie el conjunto de puntos resultado que está almacenado internamente.
         * @return Vector con los puntos de la curva calculados.
         */
        std::vector<Coordenadas> calcularPuntos();

        /**
         * @brief Obtiende un conjunto de puntos que está almacenado internamente, representa
         * a las posiciones de los árboles. (coordenadas locales a la vista 2D)
         * @return Vector con los puntos de los árboles calculados.
         */
        std::vector<Coordenadas> calculateTreePoints() ;

        /* setters y getters */
        void setTreesPerSegment(unsigned int number) ;

        unsigned int getTreesPerSegment() const ;

    private:

		/**
		 * @brief Carga el vector de resultados en el atributo interno de la clase (curvePoints).
		 * Este método es invocado cuando se hace el setControlPoints o si se pasa un
		 * vector de puntos de control al contructor del objeto.
		 */
    	void loadCurvePointsVector() ;

    	/**
    	 * @brief Calcula los puntos resultado para un segmento de curva, formado por el vector
    	 * temporal pasado por parámetro, que contiene cuatro puntos de control. Aplica la sumatoria
    	 * de la forma BSpline de orden k=4, grado 3.
    	 * @param temp Vector con cuatro puntos de control que definen el segmento a calcular.
    	 * @param curvePoints True si se quieren calcular los puntos de la curva, False si
    	 * se quieren calcular los puntos de los árboles.
    	 */
    	void loadSegmentPoints( std::vector<Coordenadas>& temp,bool curve) ;

};

#endif // __BSPLINECURVEPAINTER_H__
