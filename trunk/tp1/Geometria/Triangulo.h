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

    /**
     * Dibuja el triangulo punteado en la pantalla actual
     */
    void dibujarPunteado();

    /**
     * Devuelve TRUE si (x,y) esta contenido en el triangulo
     */
    bool contiene(int x, int y);

    /**
     * Rellena el triangulo en la pantalla actual
     */
    void rellenar();

protected:
private:
    Coordenadas* verticeA;
    Coordenadas* verticeB;
    Coordenadas* verticeC;
};

#endif // TRIANGULO_H
