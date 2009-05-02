#ifndef PANTALLA_H
#define PANTALLA_H

#include <stdlib.h>


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
        //setters
        void setEjesVisibles(bool b) { this->view_axis = b;}
        void setGrillaVisible(bool b) { this->view_grid = b;}

        /** Despliegue de datos en pantalla **/
        static void display();

    protected:
    private:
        bool view_grid;
        bool view_axis;

        // constructor
        Pantalla()
        {
            this->view_grid = true;
            this->view_axis = true;
        }
        // destructor
        inline ~Pantalla()
        {
            //dtor
        }
};

#endif // PANTALLA_H
