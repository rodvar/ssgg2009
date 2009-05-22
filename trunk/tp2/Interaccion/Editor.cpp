#include "Editor.h"

Editor::Editor(float ancho, float alto)
{
    this->marco.setBase(ancho*PJE_DIMENSIONES);
    this->marco.setAltura(alto*PJE_DIMENSIONES);
}

Editor::~Editor()
{
    //dtor
}

void Editor::limpiar() {
    list<Coordenadas*>::iterator it = this->puntosEdicion.begin();
    while (it != this->puntosEdicion.end()){
        delete *it;
        it++;
    }
    this->puntosEdicion.clear();
}

Coordenadas* Editor::mapeo(int x, int y) {
	Coordenadas* returnCoords = NULL;
	Coordenadas* verticeSO = this->marco.getVerticeSO();
	Coordenadas* verticeNO = this->marco.getVerticeNO();
	float xRelative =  (x-verticeSO->getX())/this->marco.getBase();
    float yRelative =  (y-verticeNO->getY())/this->marco.getAltura();
    returnCoords = new Coordenadas(xRelative,1-yRelative);

	delete verticeSO;
	delete verticeNO;
	return returnCoords;
}
