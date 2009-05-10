#ifndef RAMA_H
#define RAMA_H

#include "Hoja.h"

#define HOJAS_DEFECTO 3

/**
 * Clase que representa la rama de un arbol
 */
class Rama : public Dibujable
{
    public:
        /**  Constructor
         * @param hoja Es el modelo de hoja para las hojas de la rama
         * @param orientacion Es la orientacion en grados medidos desde la perpendicular [-45,45]
         **/
        Rama(Hoja hoja, const short orientacion);

        virtual ~Rama();
        unsigned short int getOrientacionHojas() { return this->orientacionHojas; }

        /** Setea la nueva orientacion verificando que se encuentre en el rango [-45,45]. Si no
         * lo esta asigna 0**/
        void setOrientacionHojas(const short int orientacion);

        /**
         * Dibuja una rama en el origen de coordenadas cartesianas, con su base en el plano
         * z=0 orientada hacia los z positivos.
         */
        void dibujar();


    protected:
    private:
        GLUquadricObj * qobj;
        Hoja hojas[HOJAS_DEFECTO];
        Color color;
        short int orientacionHojas;
};

#endif // RAMA_H
