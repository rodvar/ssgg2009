#ifndef EDITORSENDEROPLANTACION_H
#define EDITORSENDEROPLANTACION_H

#include "Editor.h"

#define PJE_ANCHO_S 0.68f
#define PJE_ALTO_S  0.40f

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

        /** Redimensiona editor **/
        void redimensionar(const float ancho, const float alto);

        /**
         * Dibuja todo lo relacionado al editor
         */
        void dibujar();

    protected:
    private:
    	void dibujarLineasControl();
    	void dibujarPuntoControl(Coordenadas* c);
};

#endif // EDITORSENDEROPLANTACION_H
