#ifndef EDITORHOJA_H
#define EDITORHOJA_H

#include "Editor.h"

#define PJE_ANCHO_H 0.68f
#define PJE_ALTO_H  0.80f

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

        /**
         * Redimensiona el editor con los parametros pasados
         */
        void redimensionar(const float ancho, const float alto);

    protected:
    private:
};

#endif // EDITORHOJA_H
