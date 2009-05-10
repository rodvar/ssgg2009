#ifndef IU_H
#define IU_H

#include "../Motor.h"
#include "../Visualizacion/Pantalla.h"
#include "../Geometria/Coordenadas.h"
#include "../Geometria/Curva.h"
#include "../Geometria/Rectangulo.h"
#include "../Geometria/Circunferencia.h"
#include <list.h>

/**
    Interfaz de Usuario: Clase que contiene toda la funcionalidad brindada al usuario
    para hacer modificaciones durante la ejecucion del sistema
 */
class IU
{
    public:
        /**
         * Devuelve la instancia unica segun el patron de diseño Singleton
         */
        static IU* getInstancia(){
            static IU* iu = NULL;
            if (!iu)
                iu = new IU();
            return iu;
        }
        /**
         *  Desabilita el motor limpiando los recursos que este estaba utilizando.
         *   El mismo queda inutilizable
         */
        inline static void limpiar(){
            delete (IU::getInstancia());
        }

        /** Manejo de eventos de teclado **/
        static void keyboard (unsigned char key, int x, int y);
        /** Manejo de eventos de mouse **/
        static void mouse(int boton, int estado, int x, int y);
        /** OnIdle **/
        static void OnIdle();

        /** Dibuja la figura BSpline dentro del marco que le corresponde */
        void dibujarFiguraBSplines();

        list<Coordenadas> getPuntosControlBSplines() { return puntosControlBSplines; }

    protected:

    private:

    	list<Coordenadas> puntosControlBSplines;
        list<Coordenadas> puntosControlBezier;

        void addPuntoControlBSplines(Coordenadas coordenada);

        void addPuntoControlBezier(Coordenadas coordenada);

    	// Constructor
        IU(){
        }
        //Destructor
        inline ~IU ( ){
            //TODO
        }
};

#endif // IU_H
