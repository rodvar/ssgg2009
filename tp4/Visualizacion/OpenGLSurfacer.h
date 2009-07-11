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
        /** Esto configura como se reparte el brillo en una superficie
         * @param n Valores posibles [0-128]
         */
        static void setFactorFocalizacion(const float n);

        /**
         * Configura el pipeline grafico con los valores por defecto de materiales
         */
        static void setPorDefecto();

        /**
         * Configura el material con un efecto de brillo como el de un metal
         */
        static void setMetal();

        /**
         * Configura el material como si fuera la luna (material emisivo y con defectos
         */
        static void setLuna();

        /**
         * Configura el material para que refleje / refracte la luz como agua salada
         */
        static void setAguaSalada();

        /**
         * Configura el material como translucido, util para dibujar vidio por ej
         */
        static void setTranslucido();
};

#endif // OPENGLSURFACER_H
