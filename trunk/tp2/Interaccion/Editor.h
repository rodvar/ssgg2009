#ifndef EDITOR_H
#define EDITOR_H

#include "../Geometria/Rectangulo.h"
#include <list>
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

        void agregarPunto(Coordenadas coordenada) { this->puntosEdicion.push_back(coordenada); }
        list<Coordenadas> getPuntosEdicion() { return this->puntosEdicion; }
        void limpiar() { this->puntosEdicion.clear(); }

    protected:
        Rectangulo marco;
        list<Coordenadas> puntosEdicion;

};

#endif // EDITOR_H
