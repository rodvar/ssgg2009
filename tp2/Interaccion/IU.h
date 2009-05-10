#ifndef IU_H
#define IU_H

#include "../Motor.h"
#include "../Visualizacion/Pantalla.h"
#include "../Interaccion/EditorHoja.h"
#include "../Interaccion/EditorSenderoPlantacion.h"

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

        Editor* getEditorSenderoPlantacion() { return this->editorSendero; }
        Editor* getEditorHoja() { return this->editorHoja; }

        /** Manejo de eventos de teclado **/
        static void keyboard (unsigned char key, int x, int y);
        /** Manejo de eventos de mouse **/
        static void mouse(int boton, int estado, int x, int y);
        /** OnIdle **/
        static void OnIdle();

        /** Dibuja la figura BSpline dentro del marco que le corresponde */
        void dibujarFiguraBSplines();

    protected:

    private:
        EditorHoja* editorHoja;
        EditorSenderoPlantacion* editorSendero;

        void addPuntoControlBSplines(Coordenadas coordenada);

        void addPuntoControlBezier(Coordenadas coordenada);

    	// Constructor
        IU(){
            float ancho = Pantalla::getInstancia()->getAncho();
            float alto = Pantalla::getInstancia()->getAlto();
            this->editorHoja = new EditorHoja(ancho,alto);
            this->editorSendero = new EditorSenderoPlantacion(ancho,alto);
        }
        //Destructor
        inline ~IU ( ){
            delete this->editorHoja;
            delete this->editorSendero;
        }
};

#endif // IU_H
