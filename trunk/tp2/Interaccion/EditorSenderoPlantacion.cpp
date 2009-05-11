#include "EditorSenderoPlantacion.h"

EditorSenderoPlantacion::EditorSenderoPlantacion(float ancho, float alto) : Editor (ancho,alto)
{
    Coordenadas coordenadas(ancho*0.70f + this->marco.getBase()/2,alto*0.20f - this->marco.getAltura()/2);
	this->marco.setCentro(coordenadas);
}

EditorSenderoPlantacion::~EditorSenderoPlantacion()
{
    //dtor
}


void EditorSenderoPlantacion::procesarSeleccion(Coordenadas coordenadas){
    //TODO: implementar
}


void EditorSenderoPlantacion::terminar(){
    //TODO: implementar
}
