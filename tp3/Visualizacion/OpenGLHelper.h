#ifndef OPENGLHELPER_H
#define OPENGLHELPER_H

#include <list>
#include <string>
#include "GL/glut.h"
#include "../Escena/Coordenadas.h"

#define GL_PI 3.14159265359f

/**
 * @brief Esta clase funciona como wrapper de la libreria grafica OpenGL. Su funcionalidad
 * es bridar 'primitivas' sencillas que permitan modelar dibujos complejos. Todos los dibujos
 * se realizan con centro en el origen
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
         * @param paso Es el paso de discretizacion medido en radianes (menor a 2PI)
         */
        static void dibujarCircunferencia(const float radio, const float paso);

        /**
         * @brief Dibuja un abanico abierto de par en par
         * @param radio El radio max del abanico
         * @param paso el ancho maximo de sus hastas en radianes
         */
        static void dibujarAbanico(const float radio, const float paso);

        /**
         * @brief Dibuja un barandal de proteccion en forma de abanico
         * @param radio El radio max del abanico
         * @param paso el ancho maximo de sus hastas en radianes
         * @param alto La altura de la baranda
         */
        static void dibujarBarandal(const float radio, const float paso, const float alto);

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

    private:
        /**
         * Carga el vector c con los puntos resultantes de la discretizacion de una curva
         * de radio, usando paso para la misma
         */
        static void discretizarCurva(Coordenadas* vector, const float radio, const float paso);
};

#endif // OPENGLHELPER_H
