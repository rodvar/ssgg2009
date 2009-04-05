#include "Pantalla.h"

Pantalla::Pantalla()
{
    this->grilla = new Grilla(FILAS,COLUMNAS,DX,DY, new Coordenadas(ORIGEN_X,ORIGEN_Y));
}

Pantalla::~Pantalla()
{
    delete this->grilla;
}

void Pantalla::actualizar(list<FiguraGeometrica*> figuras){
    this->grilla->dibujar();
    list<FiguraGeometrica*>::iterator it=figuras.begin() ;
    while(it != figuras.end()){
        ((FiguraGeometrica*)*it)->dibujar();
        it++;
    }
}
