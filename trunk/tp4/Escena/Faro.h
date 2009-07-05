#ifndef FARO_H
#define FARO_H

#include "../Visualizacion/Dibujable.h"

#define LUZ_FARO 4
#define PRECISION_COLUMNA 20.0
#define PRECISION_CABINA ((int)((float)PRECISION_COLUMNA*17.0f/20.0f))

/**
 * Representa la construccion Faro que sostiene el Foco que ilumina el mar de noche.
 */
class Faro : public Dibujable
{
    public:
        /**
         * @brief Construye el faro y queda listo para poder dibujarse, proporcional a su altura
         * @param altura Es la altura del faro medida en pixeles
         */
        Faro(const float altura);
        ~Faro();

        /**
         * @brief Devuelve la altura (posicion Z) donde se debe ubicar el foco luminoso
         * @post Luego hay q aplicarle las mismas operaciones que al Faro
         */
        static float getAlturaFoco();

        /**
         * @brief Devuelve la distancia entre el piso y el techo de la Cabina donde se ubica el foco
         * @post Luego hay q aplicarle las mismas operaciones que al Faro
         */
        static float getLargoCabina();

        /**
         * @brief Dibuja el foco luminoso del faro y lo rota en cada llamada
         * @param altura La altura del faro
         */
        static void iluminar(const float altura);

        /* Dibuja el faro en el origen de coordenadas*/
        void dibujar();
    private:
        double altura;
        float radioMin;
        float radioMax;

        /* Dibuja el cuerpo del faro como una superficie de revolucion */
        void dibujarColumna();
        /* Dibuja la cabina concibiendo esta como el ventanal + el foco emisor de luz
            como una superficie de revolucion*/
        void dibujarCabina();
        /* Dibuja el sombrero que cerra la cabeza del faro usando superficies de revolucion y acumulacion*/
        void dibujarSombrero();

};

#endif // FARO_H
