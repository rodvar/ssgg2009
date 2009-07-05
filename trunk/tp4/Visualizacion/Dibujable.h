#ifndef DIBUJABLE_H
#define DIBUJABLE_H

#include <GL/glut.h>

/**
 * Interfase el comportamiento que debe tener todo elemento
 * que se pueda dibujar
 */
class Dibujable
{
    public:
        /** Dibujar el elemento dibujable **/
        virtual void dibujar() = 0;
};

#endif // DIBUJABLE_H
