#include "EditorHoja.h"

EditorHoja::EditorHoja(float ancho, float alto):Editor(ancho,alto)
{
    Coordenadas coordenadas(ancho*0.70f + this->marco.getBase()/2,alto*0.50f - this->marco.getAltura()/2);
    this->marco.setCentro(coordenadas);
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
