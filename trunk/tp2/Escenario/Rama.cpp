#include "Rama.h"

Rama::Rama(Hoja hoja)
{
    for (int i = 0; i < HOJAS_DEFECTO; i++)
        this->hojas[i] = hoja;
    this->color.setRojo(0.6);
    this->color.setVerde(0.25);
}

Rama::~Rama()
{
    this->color.setRojo(0.6);
    this->color.setVerde(0.25);
}

void Rama::dibujar(){
    // TODO: implementar
}
