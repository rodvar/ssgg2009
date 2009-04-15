#ifndef LETRA_H
#define LETRA_H

#include "FiguraGeometrica.h"


class Letra : public FiguraGeometrica
{
    public:
        Letra(Coordenadas* centro, char letra);

        Color* getColor() { return this->borde; }
        void setColor(Color* color);
        void dibujar();
        void dibujarPunteado();
        void rellenar();
        bool contiene(int x, int y);

        virtual ~Letra();
    protected:
    private:
        char letra;
        Coordenadas* centro;
};

#endif // LETRA_H
