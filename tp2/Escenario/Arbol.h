#ifndef ARBOL_H_INCLUDED
#define ARBOL_H_INCLUDED

#include "../Geometria/Curva.h"
#include "Rama.h"

class Arbol : public Dibujable{
    public:
        /**  Constructor: Construye una rama de orientacion aleatoria con hojas de orientacion aleatoria
         * @param modeladoHoja Es el modelo de hoja para las hojas de la rama
         * @param niveles Cantidad de ramas del arbol
         **/
        Arbol(Curva* modeladoHoja, const unsigned short int niveles, Coordenadas* p);

        virtual ~Arbol();

        /**
         * Dibuja el arbol en forma recursiva
         */
        void dibujar();

        /** Devuelve la ubicacion del arbol */
        Coordenadas* getPosicion() { return this->posicion; }

    private:
        int nivelIzq;
        int nivelCtr;
        int nivelDer;
        Rama* raiz;
        unsigned short int niveles;
        Coordenadas* posicion;

        // crea el arbol
        void crearArbol(Rama* raiz);

        //Dibuja el arbol el forma recursiva a partir de la raiz pasada por parametro
        void dibujarRecursivo(Rama* raiz, int tipo);

};

#endif // ARBOL_H_INCLUDED
