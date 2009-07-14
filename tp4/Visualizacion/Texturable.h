#ifndef TEXTURABLE_H
#define TEXTURABLE_H

#include "Dibujable.h"
#include <string>

/**
 * Clase abstracta que marca que define el comportamiento de objetos que a los cuales
 * se les pueden aplicar texturas en su dibujado
 */
class Texturable : public Dibujable
{
    public:
        // Constructor / Destructor
        Texturable();
        virtual ~Texturable();

        /** Set de textura **/
        void setTextura(std::string nombre);

        /**
         * @brief Prepara todo lo necesario para que se pueda dibujar el objeto con su
         *        Textura aplicada. Luego llama a this->dibujar() el cual debera indicar
         *        el mapeo de la textura con coordenadas de Texels
         */
        void dibujarTexturado();

        /**
         * @brief Levanta la imagen del archivo y la carga al buffer del pipeline grafico
         *        llamando por ej en ope glTexImage2D(...)
         *        Se decide utilizar solo formato BMP de 256x256 (si se cambia debe ser desde aqui
         */
        void cargarImagen();

        /** Dibujar el elemento dibujable **/
        virtual void dibujar() = 0;

    protected:
        /**
         * @brief Devuelve true si el archivo se puede usar, false en caso contrario.
         *      Las clases hijas deberian preguntar esto antes de ejecutar comandos de
         *      Coordenadas de Texels
         */
        bool listoTexturar();
        unsigned int idTextura;
        // Nombre del archivo donde esta la textura a apĺicar
        std::string nombreArchivo; // Si es "" significa que no se seteo la textura
};

#endif // TEXTURABLE_H
