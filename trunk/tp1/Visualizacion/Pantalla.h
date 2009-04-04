#ifndef PANTALLA_H
#define PANTALLA_H

#include "Grilla.h"
#include "../Geometria/FiguraGeometrica.h"
#include <list.h>

// Configuracion Grilla - Pantalla
#define FILAS 10
#define COLUMNAS 10
#define DX 80.0
#define DY 55.0
//

/**
 * Clase que representa la pantalla OpenGL.
 */
class Pantalla
{
    public:
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
