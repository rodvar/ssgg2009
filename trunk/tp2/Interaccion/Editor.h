#ifndef EDITOR_H
#define EDITOR_H

#include "../Geometria/Rectangulo.h"

/**
 * Clase base para un editor.
 */
class Editor
{
    public:
        Editor();
        virtual ~Editor();

        /**
         * Metodo abstracto procesarSeleccion
         * Realiza el procesamiento correspondiente a la naturaleza del editor
         * a partir de un punto dado por el usuario
         * @param coordenadas Las coordenadas del punto seleccionado
         */
        virtual void procesarSeleccion(Coordenadas coordenadas) = 0;

    protected:
    private:
        Rectangulo marco;

};

#endif // EDITOR_H
