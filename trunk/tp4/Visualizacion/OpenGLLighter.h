#ifndef OPENGLLIGHTER_H
#define OPENGLLIGHTER_H

#include <GL/glut.h>

/**
 * Esta clase actua como "wrapper" de toda la funcionalidad de iluminacion de la libreria
 * gráfica. Además brinda funcionalidades de configuracion base para el sistema.
 */
class OpenGLLighter
{
    public:
        /**
         * @brief Configura el modelo de iluminacion.
         * @param ambiente Valores RGBA de la iluminacion ambiente global
         * @param local Coordenadas del viewpoint locales (true, mas realista,menos eficiente)
         * @param dobleCara Aplicar iluminacion para ambas caras de los poligonos(true, mas real, menos efic)
         */
        static void setModeloIluminacion(const float ambiente[], bool local, bool dobleCara);
        static void setModeloIluminacionPorDefecto();

        /**
         * @brief Setea el factor n de la funcion coseno que indica cuan focalizada esta la luz
         */
        static void setFactorFocalizacion(const int luz, const float n);

        /**
         * @brief Setea el angulo de apertura para una luz posicional/spot
         * @param luz La luz a modificar. Es responsabilidad del usuario q esta sea direccional
         */
        static void setAperturaSpot(const int luz, const float cutoff);

        /**
         * Prende/Apaga la luz i
         */
        static void switchIluminador(const int i);

        /**
         * @brief Setea la atenuacion indicada para la luz indicada
         * @param luz La luz cuya atenuacion se quiere modificar [0-7]
         * @param constante El valor de la atenuacion constante
         * @param lineal El valor de la atunuacion lineal (crece con la distancia)
         * @param cuad El valor de la atunuacion cuadratica (crece con el cuadrado de la distancia)
         */
        static void setAtenuacion(const int luz, const float constante, const float lineal, const float cuad);

        /**
         * Genera la iluminacion ambiente por defecto usando las primeras 4 luces
         */
        static void generarLuzAmbiente();

        /**
         * Genera iluminacion ambiente utilizando las primeras 5 luces (0 a 4) tanto
         * para el caso diurno como nocturno.
         */
        static void generarLuzAmbienteDiurna();
        static void generarLuzAmbienteNocturna();

        /**
         * Genera una luz posicional por defecto (la numero i=4)
         */
        static void generarLuzSpot();
};

#endif // OPENGLLIGHTER_H
