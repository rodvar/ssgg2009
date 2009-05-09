#ifndef RAMA_H
#define RAMA_H

#include "Hoja.h"

#define HOJAS_DEFECTO 3

/**
 * Clase que representa la rama de un arbol
 */
class Rama
{
    public:
        /**  Constructor
         * @param hoja Es el modelo de hoja para las hojas de la rama
         **/
        Rama(Hoja hoja);

        virtual ~Rama();

        /**
         * Dibuja una rama en el origen de coordenadas cartesianas, con su base en el plano
         * z=0 orientada hacia los z positivos.
         */
        void dibujar();


    protected:
    private:
        Hoja hojas[HOJAS_DEFECTO];
        Color color;
};

#endif // RAMA_H
