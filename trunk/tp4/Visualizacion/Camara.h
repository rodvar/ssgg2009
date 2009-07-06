#ifndef CAMARA_H
#define CAMARA_H

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
         * Configura la camara para tomar imagenes de acuerdo a los parametros actuales
         */
        void preparar();

    private:
        // Variables que controlan la ubicaci�n de la c�mara en la Escena 3D
        float eye[3];
        float at[3];
        float up[3];
        float zoom;
        float anguloXY;
        float anguloZ;
};

#endif // CAMARA_H
