#include "Hoja.h"

Hoja::Hoja(Curva* modelado, float orientacion)
{
    this->modelado = modelado;
    this->color.setVerde(1);
    this->modelado->setColorBorde(this->color);
    this->modelado->setColorRelleno(this->color);
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
    // El metodo dibujarBezier esta dibujando cosas q son del editor!!!
    glColor3f(this->color.getRojo(), this->color.getVerde(), this->color.getAzul());
    this->modelado->dibujarBezier();
    this->modelado->rellenar();
}


