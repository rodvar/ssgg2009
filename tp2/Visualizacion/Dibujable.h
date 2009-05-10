#ifndef DIBUJABLE_H
#define DIBUJABLE_H

#include <stdlib.h>
#include <GL/glut.h>

/**
 * Clase abstracta pura (interfaz) que define el comportamiento que debe tener todo elemento
 * que se pueda dibujar
 */
class Dibujable
{
    public:
        virtual void dibujar() = 0;
};

#endif // DIBUJABLE_H
