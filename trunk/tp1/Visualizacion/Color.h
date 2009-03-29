#ifndef COLOR_H
#define COLOR_H

/**
 * Clase que representa un color a partir de su intensidad de los colores primaios
 * RGB (rojo verde azul)
 */
class Color
{
    public:
        /**
         * Constructor
         * @param r Es el porcentaje de rojo del color.
         * @param r Es el porcentaje de rojo del color.
         * @param r Es el porcentaje de rojo del color.
         * @note Todos los valores estan comoprendidos entre [0.0,1.0]
         */
        Color(float r,float g, float v);

        virtual ~Color();
        float getRojo() { return rojo; }
        float getVerde() { return verde; }
        float getAzul() { return azul; }
    protected:
    private:
        float rojo;
        float verde;
        float azul;
};

#endif // COLOR_H
