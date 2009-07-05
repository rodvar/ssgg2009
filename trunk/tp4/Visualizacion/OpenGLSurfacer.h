#ifndef OPENGLSURFACER_H
#define OPENGLSURFACER_H

#include <GL/glut.h>

/**
 * Esta clase actua como "wrapper" de toda la funcionalidad de materiales de la libreria
 * gráfica. Además brinda funcionalidades de configuracion base para el sistema.
 */
class OpenGLSurfacer
{
    public:
        /* Valores posibles: [0,128] ; asociado al cosN(alfa)*/
        static void setFactorFocalizacion(const float n) { OpenGLSurfacer::n=n; }

        /**
         * Configura el pipeline grafico con los valores por defecto de materiales
         */
        static void setPorDefecto();

        /**
         * Configura el material como translucido, util para dibujar vidio por ej
         */
        static void setTranslucido();



    private:
        static GLint n;
};

#endif // OPENGLSURFACER_H
