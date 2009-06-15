#ifndef FARO_H
#define FARO_H

#include "../Visualizacion/Dibujable.h"

#define ANCHO 1.0f

/**
 * Representa un faro que ilumina el mar de noche para que la isla sea visible. Su Foco gira
 * segun la orientacion del faro a cada instante
 */
class Faro : public Dibujable
{
    public:
        /**
         * @brief Construye el faro y queda listo para poder dibujarse, proporcional a su altura
         * @param velocidadGiro Es la variacion que hace en grados para cada render
         * @param altura Es la altura del faro medida en pixeles
         */
        Faro(const double velocidadGiro, const double altura);
        ~Faro();

        /* Dibuja el faro en el origen de coordenadas*/
        void dibujar();
    private:
        double velocidadGiro; // deltaAngulo que rota a cada insante la lente del faro
        double altura;
        double orientacion; // angulo respecto eje x a donde mira el faro

        /* Dibuja el cuerpo del faro como una superficie de revolucion */
        void dibujarColumna();
        /* Dibuja la cabina concibiendo esta como el ventanal + el foco emisor de luz
            como una superficie de revolucion*/
        void dibujarCabina();
        /* Dibuja el sombrero que cerra la cabeza del faro usando superficies de revolucion y acumulacion*/
        void dibujarSombrero();

};

#endif // FARO_H
