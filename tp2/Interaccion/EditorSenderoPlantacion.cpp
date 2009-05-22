#include "EditorSenderoPlantacion.h"

EditorSenderoPlantacion::EditorSenderoPlantacion(float ancho, float alto) : Editor (ancho,alto)
{
    Coordenadas coordenadas(ancho*PJE_ANCHO_S + this->marco.getBase()/2,alto*PJE_ALTO_S - this->marco.getAltura()/2);
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

void EditorSenderoPlantacion::redimensionar(const float ancho, const float alto){
    Coordenadas coordenadas(ancho*PJE_ANCHO_S + this->marco.getBase()/2,alto*PJE_ALTO_S - this->marco.getAltura()/2);
    this->marco.setCentro(coordenadas);
    this->marco.setBase(ancho*PJE_DIMENSIONES);
    this->marco.setAltura(alto*PJE_DIMENSIONES);
}

void EditorSenderoPlantacion::dibujar(){
    if(this->puntosEdicion.size()>3) {
		Curva curva(this->puntosEdicion);
		curva.dibujarBSplines();
    }
}
