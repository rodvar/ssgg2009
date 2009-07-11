#ifndef MAR_H
#define MAR_H

#include "../Visualizacion/Dibujable.h"

#define MAX_FILTRO 4 // Debe ser par
#define DIMENSION_FILTRO 5 // Debe ser multiplo de 5

/**
 * Simula un Mar plano que a traves del tiempo tiene cierto patron de oleaje. Esto se
 * logra con llamadas sucesivas al metodo dibujar().
 */
class Mar : public Dibujable
{
    public:
        /**
         * @brief Construye el Mar con todo lo necsario para dibujarlo dinamicamente
         * @param dimension Determina el largo=ancho del mar
         * @param alturaOlasMax Determina la Max altura que puede tener una ola medida
         *                      en m
         * @param dimension debe ser multiplo de 10
         */
        Mar(const unsigned short dimension, const float alturaOlasMax);

        ~Mar();

        /**
         * @brief Detiene/Continua el oleaje
         */
        void switchCalmoInquieto();

        /**
         * @brief Dibuja el mar cuyas olas va del plano z=0 hasta la alturaOlasMax.
         *        En cada llamada, la altura de cada punto varia entre estos valores.
         */
        void dibujar();

    private:
        /* Carga la matriz con valores entre 0 y altura maxima */
        void generar();
        /* Suaviza la matriz */
        void aplicarFiltro();
        /* Calcula las de los puntos de control de la ola para el (x,y) dado */
        void calcularAlturas(float* alturas,const unsigned short int x, const unsigned short int y);

        bool detenido;
        float alturaOlasMax;
        unsigned short int dimension;
        unsigned short int lineaBarrido;
        float** alturaOlas; // Matrix de dimensionXdimension
};

#endif // MAR_H
