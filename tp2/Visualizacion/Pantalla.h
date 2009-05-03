#ifndef PANTALLA_H
#define PANTALLA_H

#include <stdlib.h>
#include <GL/glut.h>
#include "../Geometria/Rectangulo.h"


class Pantalla
{
    public:
        /**
         * Devuelve la instancia unica segun el patron de diseño Singleton
         */
        static Pantalla* getInstancia(){
            static Pantalla* pantalla = NULL;
            if (!pantalla)
                pantalla = new Pantalla();
            return pantalla;
        }
        /**
         *  Desabilita el motor limpiando los recursos que este estaba utilizando.
         *   El mismo queda inutilizable
         */
        inline static void limpiar(){
            delete (Pantalla::getInstancia());
        }

        //getters
        bool ejesVisibles() {return this->view_axis;}
        bool grillaVisible() {return this->view_grid;}
        float getAncho() {return this->window_size[0];}
        float getAlto() {return this->window_size[1];}
        //setters
        void setEjesVisibles(bool b) { this->view_axis = b;}
        void setGrillaVisible(bool b) { this->view_grid = b;}
        void setAncho(const float ancho) { this->window_size[0] = ancho;}
        void setAlto(const float alto) { this->window_size[1] = alto;}

        /** Despliegue de datos en pantalla **/
        static void display();

        void dibujarEjes();

        // Recuadro superior derecho
        void dibujarEjesVista2DSuperior();

        // Recuadro inf der
        void dibujarEjesVista2DInferior();

        /** Dibuja una grilla en el plano z=0 **/
        void dibujarGrilla2D();

        /** Configura la matriz opengl en modo 3d (esto lo vamos a sacar de aca..) **/
        void setAmbiente3D();

        /** TODO: Describir esta funcionalidad **/
        void setAmbiente2DSuperior();

        /** TODO: Describir esta funcionalidad **/
        void setAmbiente2DInferior();

    protected:
    private:
        GLfloat window_size[2];
        bool view_grid;
        bool view_axis;
        Rectangulo superior;
        Rectangulo inferior;
        Rectangulo central;

        // configura con los valores iniciales los rectangulos visibles en la pantalla
        void configurarEscenario();

        // constructor
        Pantalla()
        {
            this->view_grid = true;
            this->view_axis = true;
            this->configurarEscenario();
        }
        // destructor
        inline ~Pantalla()
        {
            //dtor
        }
};

#endif // PANTALLA_H
