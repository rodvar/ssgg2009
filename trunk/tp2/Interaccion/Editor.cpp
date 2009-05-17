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
	Coordenadas* verticeSE = this->marco.getVerticeSE();
	Coordenadas* verticeSO = this->marco.getVerticeSO();
	Coordenadas* verticeNO = this->marco.getVerticeNO();

	if(x>=verticeSO->getX() && x<=verticeSE->getX() && y<=verticeSO->getY() && y>=verticeNO->getY()) {
		float deltaXAbsolut = verticeSE->getX() - verticeSO->getX();
		float factorXAbsolut =  (x-verticeSO->getX())/deltaXAbsolut;

		float deltaXRelative = 1;
		float xRelative = deltaXRelative*factorXAbsolut;

		float deltaYAbsolut = verticeSO->getY() - verticeNO->getY();
		float factorYAbsolut =  (y-verticeNO->getY())/deltaYAbsolut;

		float deltaYRelative = 1;
		float yRelative = deltaYRelative*factorYAbsolut;

		returnCoords = new Coordenadas(xRelative,1-yRelative);
	}

	delete verticeSE;
	delete verticeSO;
	delete verticeNO;

	return returnCoords;
}
