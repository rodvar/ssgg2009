#ifndef OPENGLHELPER_H
#define OPENGLHELPER_H

#include <list>
#include "GL/glut.h"
#include "../Geometria/Matematica.h"

/**
 * @brief Esta clase funciona como wrapper de la libreria grafica OpenGL(extension GLUT)
 * Su funcionalidad es bridar 'primitivas' sencillas que permitan modelar dibujos complejos.
 * Todos los dibujos se realizan con base en el origen. La normal es siempre Z+ a menos que
 * se especifique una.
 */
class OpenGLHelper
{
    public:
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
         * @param radio El radio del a circunferencia
         */
        static void dibujarCircunferencia(const float paso, const float radio);

        /**
         * @see OpenGLHelper::dibujarCircuenferencia
         * @brief Idem dibujarCircunferencia pero pinta la superficie que encierra
         */
        static void dibujarCirculo(const float paso, const float radio);

        /**
         * @brief Dibuja un cilindro unitario con base en el origen con la precision dada
         */
        static void dibujarCilindro(const float precision, const float radioBase,
                                        const float radioTapa, const float altura);

        /**
         * @brief Dibuja un abanico unitario abierto de par en par
         * @param paso el ancho maximo de sus hastas en radianes
         * @param radio El radio maximo del abanico
         */
        static void dibujarAbanico(const float paso, const float radio);

        /**
         * @brief Dibuja la forma del clasico juego de parque de diversiones con medidas unitarias
         *        Las normales son todas salientes, y en la interseccion el promedio
         * @param precision La cantidad de gajos que se quieren
         * @param radio El radio maximo del abanico
         */
        static void dibujarSamba(const float precision, const float radio, const float altura);

        /**
         * Dibuja los ejes cartesianos x,y,z
         */
        static void dibujarEjes();

        /**
         * Hace el switch entre modo SOLIDO y modo "ALAMBRE" para el dibujado de poligonos
         */
        static void cambiarModoPoligonos();

        /**
         * @brief Muestra si hubo algun error en el pipeline grafico por pantalla
         * @return true si hubo error, false en caso contrario
         */
        static bool mostrarError();

        /*********/
        /** Si esta activado, genera coordenadas para los texturados de los objetos **/
        static bool aplicarTextura;
};

#endif // OPENGLHELPER_H
