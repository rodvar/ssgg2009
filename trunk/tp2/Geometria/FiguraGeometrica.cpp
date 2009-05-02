#include "FiguraGeometrica.h"

FiguraGeometrica::FiguraGeometrica()
{
    this->borde = new Color(0,0,0);
    this->relleno = NULL;
}

FiguraGeometrica::~FiguraGeometrica()
{
    delete this->borde;
    if (this->relleno)
        delete this->relleno;
}

void FiguraGeometrica::setColorBorde(Color* color){
    delete this->borde;
    this->borde = color;
}

void FiguraGeometrica::setColorRelleno(Color* color){
    if (this->relleno)
        delete this->relleno;
    this->relleno = color;
}

void FiguraGeometrica::setColorRelleno(float r, float g, float b){
    if (this->relleno)
        delete this->relleno;
    this->relleno = new Color(r,g,b);
}
