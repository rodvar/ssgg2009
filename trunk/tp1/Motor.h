#ifndef MOTOR_H
#define MOTOR_H

// Modos de sistema
#define BRESENHAM 'B'
#define DDA 'D'

#include "Geometria/Circunferencia.h"
#include "Geometria/Segmento.h"
#include "Geometria/Numero.h"
#include "Visualizacion/Pantalla.h"
#include <list>

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

        /**
         * Realiza la logica del algoritmo Breseham para mostrar en la pantalla que
         * pixeles se pintan al dibujar una Circunferencia cuyo radio es la distancia del
         * origen de la grilla a cRadio. Al final llama a actualizar
         * @param cRadio Coordenadas de uno de los puntos de la circunferencia
         */
        void simulacionBresenham(Coordenadas* cRadio);

        /**
         * Realiza la logica del algoritmo DDA para mostrar en la pantalla que pixeles
         * se pintan al dibujar un segmento cuyos limites son desde, hasta. Al finalizar
         * llama a actualizar
         * @param desde Coordenadas de inicio del segmento a trazar
         * @param hasta Coordenadas de fin del segmento a trazar
         */
        void simulacionDDA(Coordenadas* desde, Coordenadas* hasta);

    protected:
    private:
        list<FiguraGeometrica*> datos;
        Pantalla* pantalla;
        char modo; // 'B' para Bresenham, 'D' para DDA

        // Regenera la pantalla
        void regenerarPantalla();

        // Constructor
        Motor (){
            this->pantalla = new Pantalla();
            this->datos.clear();
            this->modo = 'D'; // Inicia en modo lineas (con DDA)
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

        // Elimina todos los objetos para dibujar en la lista de datos
        void limpiarBufferDatos();
};

#endif // MOTOR_H
