#include "Dibujable.h"

Dibujable::Dibujable()
{
    this->esRellenable = false;
}

Dibujable::~Dibujable()
{
}

void Dibujable::setColorBorde(Color color){
    this->borde.setAzul(color.getAzul());
    this->borde.setVerde(color.getVerde());
    this->borde.setRojo(color.getRojo());
}

void Dibujable::setColorRelleno(Color color){
    this->esRellenable = true;
    this->relleno = color;
}

void Dibujable::setColorRelleno(float r, float g, float b){
    this->esRellenable = true;
    this->relleno.setAzul(b);
    this->relleno.setRojo(r);
    this->relleno.setVerde(g);
}
