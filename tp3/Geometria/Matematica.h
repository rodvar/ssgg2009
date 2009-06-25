#ifndef MATEMATICA_H
#define MATEMATICA_H

#include "Coordenadas.h"

#define PI  3.14159265359f
#define DOSPI 6.283185307f
#define MEDIOPI 1.570796327f
#define NULO 0.0f
#define UNITARIO 1.0f

/**
 * Encapsula funciones matemáticas para el calculo vectorial, y trigonométrico
 */
class Matematica
{
    public:
        Matematica();
        ~Matematica();

        /**
         * @brief Escala el punto segun los factores ex, ey y ez
         */
        static void escalarPunto(Coordenadas &punto, float ex, float ey, float ez);

        /**
         * @return La normal saliente la esfera unitaria en las coordenadas dadas
         * @param anguloAlfa Es el angulo direccional en el plano xy medido desde eje x en grados
         * @param anguloFi Es el angulo direccional en el plano xz medido desde eje z en grados
         */
        static Coordenadas calcularNormal(float anguloAlfa, float anguloFi);

        /**
         * @brief Rota la direccion en deltaAlfaXY grados, luego calcula la suma vectorial y
         *        devuelve esta normalizada. Muy util para dibujar superficies de revolucion suaves
         * @see Matematica::calcularNormal
         * @param direccion El vector de direccion
         * @param deltaAlfaXY La variacion de angulo grados
         */
        static Coordenadas calcularNormal(Coordenadas direccion, float deltaAlfaXY);

        /**
         * @brief Aproxima la normal como la perpendicular al segmento que forman ambos puntos
         *        tomada desde el punto medio de ambos
         */
        static Coordenadas calcularNormal(Coordenadas a, Coordenadas b);

        /**
         * @return El resultado de A x B
         */
        static Coordenadas productoVectorial(Coordenadas a, Coordenadas b);

        /**
         * Carga el vector c con los puntos resultantes de la discretizacion de una curva
         * de radio, usando paso para la misma
         * @param z La altura de la circunferencia
         */
        static void discretizarCircunferencia(Coordenadas* vector, const float radio, const float paso, const float z);

         /**
         * @return Un nuevo vector igual a direccion pero rotado en deltaAlfaXY grados
         * @param direccion El vector de direccion
         * @param deltaAlfaXY La variacion de angulo en grados
         */
        static Coordenadas rotar(Coordenadas direccion, float deltaAlfaXY);

        /**
         * @return el punto rotado por coordenadas esfericas SIN normalizar
         */
        static Coordenadas rotar(Coordenadas direccion, float alfa,float fi);

        /**
         * @brief Calcula la norma tomando las coordenadas pasadas como una direccion
         */
        static float calcularNorma(Coordenadas direccion);

        /** Pasar angulo medido en grados a radianes y vicersa **/
        static float anguloRadianes(const float anguloGrados);
        static float anguloGrados(const float anguloRadianes);
        /** Normaliza las coordenadas pasadas por parametro **/
        static void normalizar(Coordenadas& coordenadas);

        /**
         * @brief Calcula el factorial de un numero entero.
         * @param n Numero al cual se le quiere calcular el factorial.
         * @return Factorial del numero especificado.
         */
        static unsigned int factorial(unsigned int n);
    private:
};

#endif // MATEMATICA_H
