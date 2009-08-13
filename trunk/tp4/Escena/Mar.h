#ifndef MAR_H
#define MAR_H

#include "../Visualizacion/Texturable.h"
#include "../Geometria/Matematica.h"

#define MAX_FILTRO 4 // Debe ser par
#define DIMENSION_FILTRO 5 // Debe ser multiplo de 5

/**
 * Simula un Mar plano que a traves del tiempo tiene cierto patron de oleaje. Esto se
 * logra con llamadas sucesivas al metodo dibujar().
 */
class Mar : public Texturable
{
    public:
        /**
         * @brief Construye el Mar dejandolo listo para generarse
         * @param dimension Determina el largo=ancho del mar
         * @param alturaOlasMax Determina la Max altura que puede tener una ola medida
         *                      en m
         * @param dimension debe ser multiplo de 10
         */
        Mar(const unsigned short dimension, const float alturaOlasMax);

        ~Mar();

        /** Para uso de Listas graficas de la libreria **/
        void setDL(int dl){ this->punteroDL = dl; }

        /**
         * @brief Genera el mar para que pueda dibujarse
         */
        void generar();

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
        /* Suaviza la matriz */
        void aplicarFiltro();
        /* Suaviza aun mas la matriz para la zona de alta profundidad */
        void aplicarFiltroAltaProfundidad();
        /* Calcula las de los puntos de control de la ola para el (x,y) dado */
        void calcularAlturas(float* alturas,const unsigned short int x, const unsigned short int y);
        /* Precalcula las normales que se usaran para la animacion */
        void generarNormales();
        /* Precarga como debe dibujarse el mar en listas de la libreria grafica */
        void precargarDibujado();

        int punteroDL; // puntero a las listas de la libreria grafica
        bool detenido;
        float alturaOlasMax;
        unsigned short int dimension;
        unsigned short int lineaBarrido;
        float** alturaOlas; // Matriz de dimensionXdimension
        Coordenadas** normalOlas; // Matriz de dimensionxdimension
};

#endif // MAR_H
