#ifndef HOJA_H
#define HOJA_H

#include "../Geometria/Curva.h"

/**
 * Clase que modela la hoja de un arbol
 */
class Hoja : public Dibujable
{
    public:
        /**   Constructor
         * @brief La hoja no se hace responsable por la eliminacion del modelado
         * @param modelado Es la curva que modela la hoja
         **/
        Hoja(Curva* modelado, float orientacion);
        Hoja();
        virtual ~Hoja();

        // Permite obtener su modelado para su modificacion
        Curva* getModelado() { return this->modelado; }
        float getOrientacion(){ return this->orientacion; }
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
        float orientacion;
};

#endif // HOJA_H
