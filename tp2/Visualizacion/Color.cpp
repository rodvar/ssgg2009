#include "Color.h"

Color::Color(float r, float g, float b)
{
    this->rojo = r;
    this->verde = g;
    this->azul = b;
}

Color::Color()
{
    this->rojo = 0;
    this->verde = 0;
    this->azul = 0;
}

Color::~Color()
{
}
