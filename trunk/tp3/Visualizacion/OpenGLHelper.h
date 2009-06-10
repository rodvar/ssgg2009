#ifndef OPENGLHELPER_H
#define OPENGLHELPER_H

#include <list>
#include <string>
#include "GL/glut.h"
#include "../Escena/Coordenadas.h"

#define GL_PI 3.14159265359

/**
 * @brief Esta clase funciona como wrapper de la libreria grafica OpenGL. Su funcionalidad
 * es bridar 'primitivas' sencillas que permitan modelar dibujos complejos.
 */
class OpenGLHelper
{
    public:
        OpenGLHelper();
        ~OpenGLHelper();

        /**
         * @brief Dibuja una recta desde el punto (0,0,0) hasta el punto (0,0,longitud)
         */
        static void dibujarRecta(const float longitud);

        /**
         * @brief Dibuja la curva uniendo sus puntos discretos con GL_LINE_STRIP
         */
        static void dibujarCurva(std::list<Coordenadas> discretizacion);

        /**
         * @brief Dibuja una circunferencia en el origen con el radio especificado
         * @param precision Es el paso de discretizacion medido en radianes (menor a 2PI)
         */
        static void dibujarCircunferencia(const float radio, const float precision);

        /**
         * Dibuja los ejes cartesianos x,y,z
         */
        static void dibujarEjes();

        /**
         * @brief Dibuja una grilla XY en el plano z=0
         */
        static void dibujarGrillaXY();

        /**
         * @brief Muestra si hubo algun error en el pipeline grafico por pantalla
         * @return true si hubo error, false en caso contrario
         */
        static bool mostrarError();



    protected:
    private:
};

#endif // OPENGLHELPER_H
