#include "Hoja.h"

Hoja::Hoja(Curva* modelado)
{
    this->modelado = modelado;
    this->color.setVerde(1);
}

Hoja::Hoja()
{
    this->modelado = NULL;
    this->color.setVerde(1);
}

Hoja::~Hoja()
{
    if (this->modelado)
        delete this->modelado;
}

void Hoja::dibujar(){
    // TODO: Implementar
}


