#include "EditorHoja.h"

EditorHoja::EditorHoja(float ancho, float alto):Editor(ancho,alto)
{
    Coordenadas coordenadas(ancho*0.70f,alto*0.40f);
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
