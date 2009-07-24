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
    static void dibujarRecta(const float longitud);
    static void dibujarRectangulo(const float base, const float altura);
    static void dibujarCuboide(const float ancho, const float alto, const float largo);
    static void dibujarCuadrado(const float lado);
    static void dibujarCurva(std::list<Coordenadas> discretizacion);
    static void dibujarCircunferencia(const float paso, const float radio);
    static void dibujarCirculo(const float paso, const float radio);
    static void dibujarEsfera(const float radio, const int precision);
    static void dibujarCilindro(const float precision, const float radioBase, const float radioTapa, const float altura);
    static void dibujarAbanico(const float paso, const float radio);
    static void dibujarSamba(const float precision, const float radio, const float altura);
    static void dibujarEjes();
    static void cambiarModoPoligonos();
    static bool mostrarError();
    static bool aplicarTextura;
private:
	void dibujarSeccionAbanico(Coordenadas puntos, int j);
};

#endif // OPENGLHELPER_H
