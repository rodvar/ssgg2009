#ifndef ISLA_H
#define ISLA_H

#include "../Visualizacion/Dibujable.h"
#include "../Geometria/Coordenadas.h"
#include <vector>

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

        /** Dibuja la isla como una superficie de acumulacion- **/
        void dibujar();

    private:
        float altura;
        float angulo; //Valor constante de rotacion para cada pedazo de la isla en grados

        /* Genera los puntos de control de la curva Base Bspline en los niveles primarios */
        std::vector<Coordenadas> generarCurvaNivel0();
        /* misma curva levemente rotaada y elevada en z*/
        std::vector<Coordenadas> generarCurvaNivel1();
};

#endif // ISLA_H
