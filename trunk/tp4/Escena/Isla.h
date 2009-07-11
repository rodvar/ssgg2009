#ifndef ISLA_H
#define ISLA_H

#include "../Visualizacion/Dibujable.h"
#include "../Geometria/Coordenadas.h"
#include <vector>

// Valores que delimitan ancho de la isla
#define ISLA_MAX_X 14.0f
#define ISLA_MIN_X -9.0f
#define ISLA_MAX_Y 9.0f
#define ISLA_MIN_Y -9.0f

/**
 * Representa una isla de tierra
 */
class Isla : public Dibujable
{
    public:
        /** Constructor
         * @brief La isla queda construida y lista para su dibujado
         * @param altura Es la altura sobre el nivel del mar en el punto mas alto de isla
        **/
        Isla(const float altura);
        ~Isla();

        /** Dibuja la isla como una superficie de acumulacion a partir de una curva de
         * nivel 0 que rodea el origen de coordenadas
        **/
        void dibujar();

    private:
        float altura;
        float angulo; //Valor constante de rotacion para cada pedazo de la isla en grados

        /* Genera los puntos de control de la curva Base Bspline en los niveles primarios */
        std::vector<Coordenadas> generarCurvaNivel0();

        void rotarPunto(Coordenadas& punto, float angulo);
};

#endif // ISLA_H
