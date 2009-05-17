#include "EditorHoja.h"

EditorHoja::EditorHoja(float ancho, float alto):Editor(ancho,alto)
{
    Coordenadas* coordenadas = new Coordenadas(ancho*PJE_ANCHO_H + this->marco.getBase()/2,alto*PJE_ALTO_H - this->marco.getAltura()/2);
    this->marco.setCentro(*coordenadas);
    delete coordenadas;
}

EditorHoja::~EditorHoja()
{
    //dtor
}

void EditorHoja::procesarSeleccion(Coordenadas coordenadas){
    //TODO: Implementame!
}

void EditorHoja::terminar(){
    //TODO: Implementame!
}

void EditorHoja::redimensionar(const float ancho, const float alto){
    Coordenadas coordenadas(ancho*PJE_ANCHO_H + this->marco.getBase()/2,alto*PJE_ALTO_H - this->marco.getAltura()/2);
    this->marco.setCentro(coordenadas);
    this->marco.setBase(ancho*PJE_DIMENSIONES);
    this->marco.setAltura(alto*PJE_DIMENSIONES);
}
