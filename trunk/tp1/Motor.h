#ifndef MOTOR_H
#define MOTOR_H

#include "Geometria/FiguraGeometrica.h"
#include "Visualizacion/Pantalla.h"
#include <list.h>

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

        /**
         * Realiza los cambios pertinentes en los datos, y los pasa a la Pantalla
         */
        void actualizar();

    protected:
    private:
        list<FiguraGeometrica*> datos;
        Pantalla* pantalla;

        // Constructor
        Motor (){
            this->pantalla = new Pantalla();
            this->datos.clear();
        }

        //Destructor
        inline ~Motor ( ){
            delete this->pantalla;
            list<FiguraGeometrica*>::iterator it=this->datos.begin() ;
            while(it != this->datos.end()){
                delete ((FiguraGeometrica*)*it);
                it++;
            }
            this->datos.clear();
        }
};

#endif // MOTOR_H
