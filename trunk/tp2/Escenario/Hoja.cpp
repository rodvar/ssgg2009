#include "Hoja.h"
#include "../Geometria/Rectangulo.h" // prueba

Hoja::Hoja(Curva* modelado, float orientacion)
{
    this->modelado = modelado;
    this->color.setVerde(1);
    this->orientacion = orientacion;
}

Hoja::Hoja()
{
    this->modelado = NULL;
    this->color.setVerde(1);
}

Hoja::~Hoja()
{
    /*if (this->modelado)
        delete this->modelado;*/
}

void Hoja::dibujar(){
    Rectangulo* rectangulo = new Rectangulo(2,2,new Coordenadas());
    rectangulo->setColorBorde(this->color);
    rectangulo->setColorRelleno(this->color);
    rectangulo->dibujar();
    delete rectangulo;
}


