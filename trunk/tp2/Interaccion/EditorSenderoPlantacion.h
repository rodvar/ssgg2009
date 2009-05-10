#ifndef EDITORSENDEROPLANTACION_H
#define EDITORSENDEROPLANTACION_H

#include "Editor.h"

/**
 * Editor del sendero de plantacion del arbol
 */
class EditorSenderoPlantacion : public Editor
{
    public:
        EditorSenderoPlantacion(float ancho, float alto);
        virtual ~EditorSenderoPlantacion();

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

#endif // EDITORSENDEROPLANTACION_H
