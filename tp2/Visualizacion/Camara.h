#ifndef CAMARA_H
#define CAMARA_H

#define MAX_ZOOM 65365.0

/**
 * Clase que representa la camara que "filma" o "ve" una escena
 */
class Camara
{
    public:
        Camara();
        virtual ~Camara();

        //getters
        float* getOjo() { return this->eye; }
        float* getSobre() { return this->at; }
        float* getArriba() { return this->up; }
        float getZoom() { return this->zoom; }
        //setters
        void setZoom(float zoom) { this->zoom = zoom; }
        //setters : permite variar la posicion de la camara en los parametros x,y
        void setPosicion(float x, float y){ this->eye[0] = x; this->eye[1] = y; }

    protected:
    private:
        // Variables que controlan la ubicaci�n de la c�mara en la Escena 3D
        float eye[3];
        float at[3];
        float up[3];
        float zoom;

};

#endif // CAMARA_H
