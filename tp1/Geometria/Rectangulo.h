#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "FiguraGeometrica.h"

/**
 * Clase que representa un rectángulo
 */
class Rectangulo : public FiguraGeometrica
{
    public:
        /**
         * Constructor
         * @param centro Es la posicion del centro del rectangulo en la pantalla.
         * @param base La base del rectangulo
         * @param altura La altura del rectangulo
         */
        Rectangulo(float base, float altura, Coordenadas* centro);
        Rectangulo();

        virtual ~Rectangulo();
        float getBase() { return base; }
        float getAltura() { return altura; }
        bool esRellenoParcial(){ return this->rellenoParcialInferior; }
        Coordenadas getCentro() { return *this->centro; }

        /* Devuelve las coordenadas del vertice NorOeste del rectangulo*/
        Coordenadas* getVerticeNO();
        /* Devuelve las coordenadas del vertice NorEste del rectangulo*/
        Coordenadas* getVerticeNE();
        /* Devuelve las coordenadas del vertice SurOeste del rectangulo*/
        Coordenadas* getVerticeSO();
        /* Devuelve las coordenadas del vertice SurEste del rectangulo*/
        Coordenadas* getVerticeSE();

        /** Setea al rectangulo como de relleno parcial        */
        void setRellenoParcial();
        /** Setea al rectangulo como de relleno total        */
        void setRellenoTotal();

        /**
         * Dibuja el rectangulo en la pantalla actual
         */
        void dibujar();

        /**
         * Dibuja el rectangulo en la pantalla actual
         */
        void dibujarPunteado();

        /**
         * Rellena el rectangulo del color de relleno seteado
         */
        void rellenar();

        /**
         * Devuelve true si la figura contiene al punto (x,y)
         */
        bool contiene(int x, int y);

    protected:
        bool rellenoParcialInferior; // indica si solo se pinta el triangulo inf der
        float base;
        float altura;
        Coordenadas* centro;
};

#endif // RECTANGULO_H
