#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "FiguraGeometrica.h"

/**
 * Clase que representa un Triangulo, definido por sus 3 vertices.
 */
class Triangulo : public FiguraGeometrica
{
public:
    /**
     * Constructor
     * PRECONDICION: A,B y C simultaneamente no deben ser puntos colineares
     * @param verticeA Es uno de los vertices del triangulo
     * @param verticeB Es uno de los vertices del triangulo
     * @param verticeC Es uno de los vertices del triangulo
     */
    Triangulo(Coordenadas* verticeA, Coordenadas* verticeB, Coordenadas* verticeC);

    virtual ~Triangulo();
    Coordenadas* getVerticeA() { return verticeA; }
    Coordenadas* getVerticeB() { return verticeB; }
    Coordenadas* getVerticeC() { return verticeC; }

    /**
     * Dibuja el triangulo en la pantalla actual
     */
    void dibujar();

protected:
private:
    Coordenadas* verticeA;
    Coordenadas* verticeB;
    Coordenadas* verticeC;
};

#endif // TRIANGULO_H
