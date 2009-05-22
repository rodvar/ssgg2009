#ifndef MOTOR_H
#define MOTOR_H

#include <stdlib.h>
#include <list>
#include "Visualizacion/Dibujable.h"

using namespace std;

/**
 * Motor del sistema. Realiza el procesamiento de datos y los despliega en la vista
 */
class Motor
{
    public:
        /**
         * Devuelve la instancia unica segun el patron de diseño Singleton
         */
        static Motor* getInstancia(){
            static Motor* motor = NULL;
            if (!motor)
                motor = new Motor();
            return motor;
        }

        /**
         *  Desabilita el motor limpiando los recursos que este estaba utilizando.
         *   El mismo queda inutilizable
         */
        inline static void limpiar(){
            delete (Motor::getInstancia());
        }

        /** Devuelve el nivel de recursividad al dibujar el arbol **/
        unsigned short int getNivelesArbol() { return this->nivelesArbol; }
        /** Devuelve el paso al dibujar cada tramo con BSpline **/
        unsigned short int getPasoTramoBSpline() { return this->pasoTramoBSpline; }
        /** Devuelve el paso al dibujar cada tramo con Bezier **/
        unsigned short int getPasoTramoBezier() { return this->pasoTramoBezier; }
        /** Devuelve la cantidad de arboles que hay q dibujar en el sendero de plantacion **/
        unsigned short int getArbolesTramoBSpline() { return this->arbolesTramoBSpline; }

        /**
         * Realiza los cambios pertinentes en los datos, y los pasa a la Pantalla
         */
        void actualizar();

        /** En base a los editores, dibuja la arboleda 3d, reemplazando el dibujo actual**/
        void simularArboleda();

        // Elimina todos los objetos para dibujar en la lista de datos
        void limpiarBufferDatos();

    protected:
    private:
        list<Dibujable*> datos;
        // Parametros de la aplicacion
        unsigned short int nivelesArbol; // Nivel de recursividad de dibujo del arbol
        unsigned short int pasoTramoBSpline; // cada cuanto tomo un punto del tramo
        unsigned short int pasoTramoBezier; // idem para Bezier
        unsigned short int arbolesTramoBSpline;// La cantidad de arboles por tramo


        // Constructor
        Motor (){
            this->nivelesArbol = 1;
            this->pasoTramoBSpline = 10;
            this->pasoTramoBezier = 10;
            this->arbolesTramoBSpline = 4;
            this->datos.clear();
        }

        //Destructor
        inline ~Motor ( ){
            list<Dibujable*>::iterator it=this->datos.begin() ;
            while(it != this->datos.end()){
                delete *it;
                it++;
            }
            this->datos.clear();
        }

};

#endif // MOTOR_H
