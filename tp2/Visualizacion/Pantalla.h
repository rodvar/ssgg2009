#ifndef PANTALLA_H
#define PANTALLA_H

#include <list>
#include "../Geometria/Rectangulo.h"
#include "Luz.h"
#include "Camara.h"

// Modos de sistema de dibujo
#define BEZIER 'B'
#define BSPLINE 'S'


using namespace std;

/**
 * Clase que representa la pantalla y su escenario o escena. Despliega los datos para
 * poder apreciarlos.
 */
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
        void setEjesVisibles(bool b) { this->view_axis = b; this->forzarRedibujo();}
        void setGrillaVisible(bool b) { this->view_grid = b; this->forzarRedibujo();}
        void setAncho(const float ancho) { this->window_size[0] = ancho;}
        void setAlto(const float alto) { this->window_size[1] = alto;}

        // Control de esfera rotante
        float getRotacionEsfera() { return this->rotate_sphere;}
        void setRotacionEsfera(float rot) { this->rotate_sphere = rot; }

        // modos de dibujo de curvas
        char getModo() { return this->modo; }
        void setModo(const char modo) { this->modo = modo; }

        /** Actualiza la pantalla con los datos suministrados **/
        void actualizar(list<Dibujable*> escena3d, list<Dibujable*> editorSup, list<Dibujable*> editorInf);

        /** Fuerza a redibujar la pantalla **/
        void forzarRedibujo();

        /** Redimensionar de pantalla **/
        static void redimensionar (int w, int h);

        /** Aumenta y disminuye el zoom de la camara de la pantalla en 1 unidad **/
        void aumentarZoom();
        void disminuirZoom();

        /** Calcula y ejecuta la rotacion de camara **/
        void calcularRotacionCamara(int x, int y);

    protected:
    private:
        Luz luz;
        Camara camara;
        // Handle para el control de las Display Lists
        GLuint dl_handle;
        GLfloat window_size[2];
        bool view_grid;
        bool view_axis;
        float rotacionX;
        float rotacionY;
        char modo; // Bezier o Bspline para e ldibujado de curvas

        // constructor
        Pantalla()
        {
            this->view_grid = true;
            this->view_axis = true;
            this->rotacionX = 0;
            this->rotacionY = 0;
            this->window_size[0]=1024;
            this->window_size[1]=768;
            this->configurarEscenario();
            // esto queda??
            this->color_esfera[0] = 0.5f;
            this->color_esfera[1] = 0.5f;
            this->color_esfera[2] = 0.2f;
            this->color_esfera[3] = 1.0f;
            this->rotate_sphere = 0;
            this->modo = BEZIER;
        }
        // destructor
        inline ~Pantalla()
        {
            //dtor
        }

        // Dibuja los ejes cartesianos
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

        /** TODO: hablar con nico, No se q onda esta esfera... */
        // Color de la esfera en movimiento dentro de la escena
        float color_esfera[4];
        // Variable asociada al movimiento de rotaci�n de la esfera alrededor del eje Z
        float rotate_sphere;

        // configura con los valores iniciales los rectangulos visibles en la pantalla
        void configurarEscenario();

        // Glut getters
        GLuint getDL_AXIS() { return this->dl_handle+0; }
        GLuint getDL_GRID() { return this->dl_handle+1; }
        GLuint getDL_AXIS2D_TOP() { return this->dl_handle+2; }
        GLuint getDL_AXIS2D_HEIGHT() { return this->dl_handle+3; }


};

#endif // PANTALLA_H
