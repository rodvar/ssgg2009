#ifndef MOTOR_H
#define MOTOR_H

// Modos de sistema
#define BRESENHAM 'B'
#define DDA 'D'

#include "Geometria/Circunferencia.h"
#include "Geometria/Segmento.h"
#include "Geometria/Triangulo.h"
#include "Geometria/Numero.h"
#include "Geometria/Letra.h"
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

        char getModo() { return this->modo; }

        /** Realiza el switch entre los 2 modos posibles **/
        void cambiarModo();

        /**
         * Realiza los cambios pertinentes en los datos, y los pasa a la Pantalla
         */
        void actualizar();

        /**
         * @return TRUE si esta en rango de trabajo, false en caso contrario
         */
        bool enRango(int x, int y);

    protected:
    private:
        list<FiguraGeometrica*> datos;
        char modo; // 'B' para Bresenham, 'D' para DDA

        // Constructor
        Motor (){
            this->datos.clear();
            this->modo = 'D'; // Inicia en modo lineas (con DDA)
        }

        //Destructor
        inline ~Motor ( ){
            list<FiguraGeometrica*>::iterator it=this->datos.begin() ;
            while(it != this->datos.end()){
                delete ((FiguraGeometrica*)*it);
                it++;
            }
            this->datos.clear();
        }

        //
        void regenerarPantalla();

        // Elimina todos los objetos para dibujar en la lista de datos
        void limpiarBufferDatos();

        /**
         * Devuelve un valor de error porcentual con 2 decimales
         * @param xReal El valor x real de la circunferencia
         * @param distancia El error absoluto con respecto a la circunferencia
         */
        float calcularIncertidumbrePje(float xReal, float distancia);
};

#endif // MOTOR_H
