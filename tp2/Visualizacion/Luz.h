#ifndef LUZ_H
#define LUZ_H

/**
 * Clase que representa una Luz o foco de iluminacion.
 */
class Luz
{
    public:
        Luz();
        virtual ~Luz();

        //getters
        float* getColor() { return this->light_color; }
        float* getPosicion() { return this->light_position; }
        float* getAmbiente() { return this->light_ambient; }
        //setters

    protected:
    private:
        // Variables asociadas a �nica fuente de luz de la escena
        float light_color[4];
        float light_position[3];
        float light_ambient[4];
};

#endif // LUZ_H
