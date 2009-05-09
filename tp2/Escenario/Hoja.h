#ifndef HOJA_H
#define HOJA_H

#include "../Geometria/Curva.h"

/**
 * Clase que modela la hoja de un arbol
 */
class Hoja
{
    public:
        /**   Constructor
         * @param modelado Es la curva que modela la hoja
         **/
        Hoja(Curva* modelado);
        Hoja();
        virtual ~Hoja();

        // Permite obtener su modelado para su modificacion
        Curva* getModelado() { return this->modelado; }
        void setModelado(Curva* modelado) { this->modelado = modelado; }

        /**
         * Dibuja una hoja en el origen de coordenadas cartesianas, con su base en el plano
         * z=0
         */
        void dibujar();

    protected:
    private:
        Curva* modelado;
        Color color;
};

#endif // HOJA_H
