#ifndef EDITORHOJA_H
#define EDITORHOJA_H

#include "Editor.h"

/**
 * Editor de las forma de las hojas del arbol
 */
class EditorHoja : public Editor
{
    public:
        EditorHoja(float ancho, float alto);
        virtual ~EditorHoja();

        /**
         * TODO :explicar
         * @param coordenadas Las coordenadas del punto seleccionado
         */
        void procesarSeleccion(Coordenadas coordenadas);

        /**
         * TODO :explicar
         */
        void terminar();

    protected:
    private:
};

#endif // EDITORHOJA_H
