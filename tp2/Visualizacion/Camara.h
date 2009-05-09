#ifndef CAMARA_H
#define CAMARA_H

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
        //setters

    protected:
    private:
        // Variables que controlan la ubicaci�n de la c�mara en la Escena 3D
        float eye[3];
        float at[3];
        float up[3];

};

#endif // CAMARA_H
