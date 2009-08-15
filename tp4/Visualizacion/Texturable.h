#ifndef TEXTURABLE_H
#define TEXTURABLE_H

#include "Dibujable.h"
#include <string>

/**
 * Clase abstracta que agrega comportamiento a la interfaz dibujable, implementando lo
 * necesario para que al dibujo se le pueda agregar texturas.
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

        /** El parametro esta apagado por defecto. LLamar si se quiere alta calidad en el texturado
            a costa de performance**/
        void setAltaCalidad();

    protected:
        /** @brief Permite cambiar la textura para implementaciones internas que
         *         requieren varias texturas
         *  @post La textura ya queda cargada y lista para usarse
         */
        void cambiarTextura(std::string nombre);

        /**
         * @brief Devuelve true si el archivo se puede usar, false en caso contrario.
         *      Las clases hijas deberian preguntar esto antes de ejecutar comandos de
         *      Coordenadas de Texels
         */
        bool listoTexturar();

        unsigned int idTextura;
        // Nombre del archivo donde esta la textura a apĺicar
        std::string nombreArchivo; // Si es "" significa que no se seteo la textura
        bool imagenCargada;
        bool altaCalidad;
};

#endif // TEXTURABLE_H
