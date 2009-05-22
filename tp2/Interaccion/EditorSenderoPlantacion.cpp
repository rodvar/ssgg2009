#include "EditorSenderoPlantacion.h"
#include "../Geometria/Circunferencia.h"
#include "../Geometria/Segmento.h"
#include "../Geometria/Coordenadas.h"
#include <list.h>

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

void EditorSenderoPlantacion::dibujarPuntoControl(Coordenadas* c) {
	Circunferencia* circ = new Circunferencia(0.01,c->copia());
	Color color(1,1,1);
	circ->setColorBorde(color);
	circ->dibujar();
	delete circ;
}

void EditorSenderoPlantacion::dibujarLineasControl() {

	bool isFirstPoint = true;
	Segmento* segmento;
    Coordenadas* c;
    list<Coordenadas*>::iterator it = this->puntosEdicion.begin();
    Coordenadas* mapeoFrom;
    Coordenadas* mapeoTo;

	float lastX;
	float lastY;
    while (it != this->puntosEdicion.end()){
        c = (Coordenadas*)*it;

  		if(!isFirstPoint) {
  	  		mapeoFrom=this->mapeo(lastX,lastY);
  			mapeoTo = this->mapeo(c->getX(),c->getY());
  			this->dibujarPuntoControl(mapeoTo);

  			segmento = new Segmento(mapeoFrom,mapeoTo);
  			Color color(1,1,1);
  			segmento->setColorBorde(color);
  			segmento->dibujarPunteado();
  			delete segmento;

  			lastX=c->getX();
  	  		lastY=c->getY();
  		} else {
  			isFirstPoint=false;
  	  		lastX=c->getX();
  	  		lastY=c->getY();
  	  		this->dibujarPuntoControl(this->mapeo(lastX,lastY));
  		}

        it++;
    }

}

void EditorSenderoPlantacion::dibujar(){
    if(this->puntosEdicion.size()>3) {
		Curva curva(this->puntosEdicion);
		curva.dibujarBSplines();
    }
	this->dibujarLineasControl();
}
