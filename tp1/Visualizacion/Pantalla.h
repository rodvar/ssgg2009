#ifndef PANTALLA_H
#define PANTALLA_H

#include "Grilla.h"
#include "../Geometria/FiguraGeometrica.h"
#include <list.h>

// Configuracion Grilla - Pantalla
#define FILAS 10
#define COLUMNAS 10
#define DX 60.0
#define DY 41.625
//

/**
 * Clase que representa la pantalla OpenGL.
 */
class Pantalla
{
    public:
        /**
         * La Pantalla queda contruida con su grilla centrada en el display
         */
        Pantalla();
        virtual ~Pantalla();

        /**
         * Dibuja todos los elementos que participan de la escena actual
         */
        void actualizar(list<FiguraGeometrica*> figuras);

    protected:
    private:
        Grilla* grilla;
};

#endif // PANTALLA_H
