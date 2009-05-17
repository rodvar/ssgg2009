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
        /**  Constructor: Construye una rama de orientacion aleatoria con hojas de orientacion aleatoria
         * @param modeladoHoja Es el modelo de hoja para las hojas de la rama
         * @param orientacion Es la orientacion que se quiere para la rama respecto al eje Z [0,360)
         * @param angulo Es la separacion con respecto al eje z [0,180]
         **/
        Rama(Curva* modeladoHoja, float orientacion, float angulo);

        virtual ~Rama();

        float getOrientacion() { return this->orientacion; }
        float getAngulo() { return this->angulo; }

        /**
         * Dibuja una rama en el origen de coordenadas cartesianas, con su base en el plano
         * z=0 orientada hacia los z positivos.
         */
        void dibujar();

    private:
        GLUquadricObj * qobj;
        Color color;
        float orientacion;
        float angulo;
        Hoja* hoja1;
        Hoja* hoja2;
        Hoja* hoja3;

        //Calcula un numero aletorio de orientacion entre [-45,45] **/
        float calcularOrientacionHoja();
};

#endif // RAMA_H
