#include "Numero.h"

Numero::Numero(Coordenadas* coordenadas, float numero) {
    this->color = new Color(0,0,0);
	this->coordenadas = coordenadas;
	this->numero = numero;
}

Numero::Numero(Coordenadas* coordenadas, int numero) {
    this->color = new Color(0,0,0);
	this->coordenadas = coordenadas;
	this->numero = (float)numero;
}

Numero::~Numero() {
	delete this->coordenadas;
	delete this->color;
}

void Numero::setSize(int size) {
	this->size = size;
}

void Numero::setColor(Color* color) {
    delete color;
	this->color=color;
}

void Numero::dibujar() {

	Segmento* linea1 = new Segmento(new Coordenadas(
			this->coordenadas->getX()+0,this->coordenadas->getY()+10),
			new Coordenadas(this->coordenadas->getX()+5,this->coordenadas->getY()+10));
	Segmento* linea2 = new Segmento(new Coordenadas(
			this->coordenadas->getX()+0,this->coordenadas->getY()+10),
			new Coordenadas(this->coordenadas->getX()+0,this->coordenadas->getY()+5));
	Segmento* linea3 = new Segmento(new Coordenadas(
			this->coordenadas->getX()+5,this->coordenadas->getY()+10),
			new Coordenadas(this->coordenadas->getX()+5,this->coordenadas->getY()+5));
	Segmento* linea4 = new Segmento(new Coordenadas(
			this->coordenadas->getX()+0,this->coordenadas->getY()+5),
			new Coordenadas(this->coordenadas->getX()+5,this->coordenadas->getY()+5));
	Segmento* linea5 = new Segmento(new Coordenadas(
			this->coordenadas->getX()+0,this->coordenadas->getY()+5),
			new Coordenadas(this->coordenadas->getX()+0,this->coordenadas->getY()+0));
	Segmento* linea6 = new Segmento(new Coordenadas(
			this->coordenadas->getX()+5,this->coordenadas->getY()+5),
			new Coordenadas(this->coordenadas->getX()+5,this->coordenadas->getY()+0));
	Segmento* linea7 = new Segmento(new Coordenadas(
			this->coordenadas->getX()+0,this->coordenadas->getY()+0),
			new Coordenadas(this->coordenadas->getX()+5,this->coordenadas->getY()+0));

	switch ((int)numero) {
	case 0:
		linea1->dibujar();
		linea2->dibujar();
		linea3->dibujar();
		linea5->dibujar();
		linea6->dibujar();
		linea7->dibujar();
		break;
	case 1:
		linea6->dibujar();
		linea3->dibujar();
		break;
	case 2:
		linea1->dibujar();
		linea2->dibujar();
		linea4->dibujar();
		linea6->dibujar();
		linea7->dibujar();
		break;
	case 3:
		linea1->dibujar();
		linea3->dibujar();
		linea4->dibujar();
		linea6->dibujar();
		linea7->dibujar();
		break;
	case 4:
		linea3->dibujar();
		linea4->dibujar();
		linea5->dibujar();
		linea6->dibujar();
		break;
	case 5:
		linea1->dibujar();
		linea3->dibujar();
		linea4->dibujar();
		linea5->dibujar();
		linea7->dibujar();
		break;
	case 6:
		linea1->dibujar();
		linea2->dibujar();
		linea3->dibujar();
		linea4->dibujar();
		linea5->dibujar();
		linea7->dibujar();
		break;
	case 7:
		linea3->dibujar();
		linea6->dibujar();
		linea7->dibujar();
		break;
	case 8:
		linea1->dibujar();
		linea2->dibujar();
		linea3->dibujar();
		linea4->dibujar();
		linea5->dibujar();
		linea6->dibujar();
		linea7->dibujar();
		break;
	case 9:
		linea3->dibujar();
		linea4->dibujar();
		linea5->dibujar();
		linea6->dibujar();
		linea7->dibujar();
		break;
	default: break;

	}

	delete linea1;
	delete linea2;
	delete linea3;
	delete linea4;
	delete linea5;
	delete linea6;
	delete linea7;
}

void Numero::rellenar() {
}

bool Numero::contiene(int x, int y){
	return false;
}
