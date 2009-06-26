#ifndef OPENGLHELPER_H
#define OPENGLHELPER_H

#include <list>
#include <string>
#include "GL/glut.h"
#include "../Geometria/Matematica.h"

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
         * @brief Dibuja un cuadrado con todos sus vertices positivos, y uno de ellos
         *        centrado en el origen. La base queda siempre apoyada contra el eje X
         * @param lado La longitud del lado del cuadrado
         */
        static void dibujarRectangulo(const float base, const float altura);

        /**
         * @brief LLama a dibujar Rectangulo con los lados iguales
         * @see OpenGLHelper::dibujarRectangulo
         */
        static void dibujarCuadrado(const float lado);

        /**
         * @brief Dibuja la curva uniendo sus puntos discretos con GL_LINE_STRIP
         */
        static void dibujarCurva(std::list<Coordenadas> discretizacion);

        /**
         * @brief Dibuja una circunferencia unitaria en el origen
         * @param paso Es el paso de discretizacion medido en radianes (menor a 2PI)
         */
        static void dibujarCircunferencia(const float paso);

        /**
         * @see OpenGLHelper::dibujarCircuenferencia
         * @brief Idem dibujarCircunferencia pero pinta la superficie que encierra
         */
        static void dibujarCirculo(const float paso);

        /**
         * @brief Dibuja un cilindro unitario en el origen con la precision dada
         */
        static void dibujarCilindro(const float precision);

        /**
         * @brief Dibuja un abanico unitario abierto de par en par
         * @param paso el ancho maximo de sus hastas en radianes
         */
        static void dibujarAbanico(const float paso);

        /**
         * @brief Dibuja la forma del clasico juego de parque de diversiones con medidas unitarias
         * @param precision La cantidad de gajos que se quieren
         */
        static void dibujarSamba(const float precision);

        /**
         * Dibuja los ejes cartesianos x,y,z
         */
        static void dibujarEjes();

        /**
         * @brief Dibuja una grilla XY en el plano z=0
         */
        static void dibujarGrillaXY();

        /**
         * Hace el switch entre modo SOLIDO y modo "ALAMBRE" para el dibujado de poligonos
         */
        static void cambiarModoPoligonos();

        /**
         * Configura el pipeline grafico para dibujar materiales translucidos
         */
        static void setMaterialEspejado();

        /**
         * Setea la configuracion estandart de materiales
         */
        static void setMaterialStd();

        /**
         * @brief Muestra si hubo algun error en el pipeline grafico por pantalla
         * @return true si hubo error, false en caso contrario
         */
        static bool mostrarError();

    private:
};

#endif // OPENGLHELPER_H
