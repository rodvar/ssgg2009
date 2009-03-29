#ifndef CUADRADO_H
#define CUADRADO_H

#include "Rectangulo.h"

/**
 * Clase que representa un cuadrado.
 */
class Cuadrado : public Rectangulo
{
    public:
        /**
         * Constructor
         * @param lado Es el tamaño del lado del cuadrado
         * @param centro Es la posicion de su centro en la pantalla
         */
        Cuadrado(float lado, Coordenadas* centro);

        virtual ~Cuadrado();
        float getLado(){ return this->base; }


    protected:
    private:
};

#endif // CUADRADO_H
