#ifndef CAMARA_H
#define CAMARA_H

#define MIN_ZOOM 70.0f
#define MAX_ZOOM 01.0f
#define ZOOM_STD 45.0f

/**
 * Representa la camara con la que se enfoca la escena.
 */
class Camara
{
    public:
        /*Constructor. Deja la camara lista para tomar imagenes en modo standart*/
        Camara();

        /*getters*/
        const float* getOjo(){ return this->eye;} // Posicion del ojo de la camara
        const float* getArriba(){ return this->up;} // Hacia donde es el arriba de la camara?
        const float* getVer(){ return this->at;} // Posicion de lo que mira
        const float getZoom(){ return this->zoom;}
        const float getAnguloXY(){ return this->anguloXY;} // Rotacion XY
        const float getAnguloZ(){ return this->anguloZ;} // Rotacion Z

        /*setters*/
        void incrementarRotacionXY(const float incremento);
        void incrementarRotacionZ(const float incremento);
        void incrementarZoom(const float incremento);
        void incrementarZVer(const float incremento);

        /**
         * @brief Configura la camara para tomar imagenes de acuerdo a los parametros actuales
         */
        void preparar();

        /**
         * @brief Cambia entre las 4 vistas posibles:
            0- VistaAerea
            1- BalconFaro
            2- BaseIsla
            3- AguaLejos
         */
        void switchVista();

    private:
        /* Setters para las 4 configuraciones de vista*/
        void setVistaStd();
        void setVistaBalconFaro();
        void setVistaBaseIsla();
        void setVistaAguaLejos();
        // Resetea valores de movimiento de la camara
        void reset();

    private:
        // Variables que controlan la ubicaci�n de la c�mara en la Escena 3D
        bool rotacionDesdeOjo; // True si rota alrededor del ojo, false para rotar respecto "at"
        float eye[3];
        float at[3];
        float up[3];
        float ejeRotacionXY[3];
        float ejeRotacionZ[3];
        float zoom;
        float anguloXY;
        float anguloZ;
        float rangoZ[2];
};

#endif // CAMARA_H
