#ifndef EDITOR_H
#define EDITOR_H

#include "../Geometria/Rectangulo.h"
#include <list>

#define PJE_DIMENSIONES 0.30f

using namespace std;

/**
 * Clase base para un editor.
 */
class Editor
{
    public:
        Editor(float ancho, float alto);
        virtual ~Editor();

        /** Devuelve el marco del rectangulo **/
        Rectangulo* getMarco() { return &this->marco; }

        /**
         * Metodo abstracto procesarSeleccion
         * Realiza el procesamiento correspondiente a la naturaleza del editor
         * a partir de un punto dado por el usuario
         * @param coordenadas Las coordenadas del punto seleccionado
         */
        virtual void procesarSeleccion(Coordenadas coordenadas) = 0;

        /**
         * Metodo abstracto terminar
         * Realiza el procesamiento correspondiente a la finalizacion de la edicion
         */
        virtual void terminar() = 0;

        /**
         * Redimensiona el editor con los parametros pasados
         */
        virtual void redimensionar(const float ancho, const float alto) = 0;

        void agregarPunto(Coordenadas coordenada) { this->puntosEdicion.push_back(coordenada.copia()); }
        list<Coordenadas*> getPuntosEdicion() { return this->puntosEdicion; }

        /** Limpia la lista eliminando sus puntos **/
        void limpiar();

        /** Realiza el mapeo de las coordenadas absolutas x,y al editor.
         *  Si pertenecen al mismo, devuelve la transformacion de las coordenadas, sino devuelve NULL**/
        Coordenadas* mapeo(int x, int y);


    protected:
        Rectangulo marco;
        list<Coordenadas*> puntosEdicion;

};

#endif // EDITOR_H
