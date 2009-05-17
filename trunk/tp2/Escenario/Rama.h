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
         **/
        Rama(Curva* modeladoHoja);

        virtual ~Rama();

        Rama* getRamaSecundaria1(){return this->ramaSecundaria1;}
        Rama* getRamaSecundaria2(){return this->ramaSecundaria2;}
        Rama* getRamaSecundaria3(){return this->ramaSecundaria3;}
        // crea las 3 ramas secundarias
        void ramificar();
        // destruye las 3 ramas secundarias
        void desRamificar();

        /**
         * Dibuja una rama en el origen de coordenadas cartesianas, con su base en el plano
         * z=0 orientada hacia los z positivos.
         */
        void dibujar();

    private:
        GLUquadricObj * qobj;
        Color color;
        Curva* modeladoHoja;
        Rama* ramaSecundaria1;
        Rama* ramaSecundaria2;
        Rama* ramaSecundaria3;
        Hoja* hoja1;
        Hoja* hoja2;
        Hoja* hoja3;

        //Calcula un numero aletorio de orientacion entre [-45,45] **/
        float calcularOrientacionHoja();
};

#endif // RAMA_H
