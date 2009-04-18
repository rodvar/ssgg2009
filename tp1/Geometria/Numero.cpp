#include "Numero.h"
#include <stdlib.h>
#include <sstream>

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
    Coordenadas coordenadas(this->coordenadas->getX(),this->coordenadas->getY());
	Segmento* linea1 = NULL;
	Segmento* linea2 = NULL;
	Segmento* linea3 = NULL;
	Segmento* linea4 = NULL;
	Segmento* linea5 = NULL;
	Segmento* linea6 = NULL;
	Segmento* linea7 = NULL;
	Segmento* negativo = new Segmento(new Coordenadas(
			this->coordenadas->getX()-5,this->coordenadas->getY()+5),
			new Coordenadas(this->coordenadas->getX()-10,this->coordenadas->getY()+5));

	// Numeros negativos
	if(this->numero < 0) {
		negativo->dibujar();
	}

	std::string cadena = this->convertirReal(this->numero);

	for(unsigned int i=0;i<cadena.size();i++) {
		linea1 = new Segmento(new Coordenadas(
				coordenadas.getX()+0,coordenadas.getY()+10),
				new Coordenadas(coordenadas.getX()+5,coordenadas.getY()+10));
		linea2 = new Segmento(new Coordenadas(
				coordenadas.getX()+0,coordenadas.getY()+10),
				new Coordenadas(coordenadas.getX()+0,coordenadas.getY()+5));
		linea3 = new Segmento(new Coordenadas(
				coordenadas.getX()+5,coordenadas.getY()+10),
				new Coordenadas(coordenadas.getX()+5,coordenadas.getY()+5));
		linea4 = new Segmento(new Coordenadas(
				coordenadas.getX()+0,coordenadas.getY()+5),
				new Coordenadas(coordenadas.getX()+5,coordenadas.getY()+5));
		linea5 = new Segmento(new Coordenadas(
				coordenadas.getX()+0,coordenadas.getY()+5),
				new Coordenadas(coordenadas.getX()+0,coordenadas.getY()+0));
		linea6 = new Segmento(new Coordenadas(
				coordenadas.getX()+5,coordenadas.getY()+5),
				new Coordenadas(coordenadas.getX()+5,coordenadas.getY()+0));
		linea7 = new Segmento(new Coordenadas(
				coordenadas.getX()+0,coordenadas.getY()+0),
				new Coordenadas(coordenadas.getX()+5,coordenadas.getY()+0));

		switch (cadena[i]) {
			case '0':
				linea1->dibujar();
				linea2->dibujar();
				linea3->dibujar();
				linea5->dibujar();
				linea6->dibujar();
				linea7->dibujar();
				break;
			case '1':
				linea6->dibujar();
				linea3->dibujar();
				break;
			case '2':
				linea1->dibujar();
				linea2->dibujar();
				linea4->dibujar();
				linea6->dibujar();
				linea7->dibujar();
				break;
			case '3':
				linea1->dibujar();
				linea3->dibujar();
				linea4->dibujar();
				linea6->dibujar();
				linea7->dibujar();
				break;
			case '4':
				linea3->dibujar();
				linea4->dibujar();
				linea5->dibujar();
				linea6->dibujar();
				break;
			case '5':
				linea1->dibujar();
				linea3->dibujar();
				linea4->dibujar();
				linea5->dibujar();
				linea7->dibujar();
				break;
			case '6':
				linea1->dibujar();
				linea2->dibujar();
				linea3->dibujar();
				linea4->dibujar();
				linea5->dibujar();
				linea7->dibujar();
				break;
			case '7':
				linea3->dibujar();
				linea6->dibujar();
				linea7->dibujar();
				break;
			case '8':
				linea1->dibujar();
				linea2->dibujar();
				linea3->dibujar();
				linea4->dibujar();
				linea5->dibujar();
				linea6->dibujar();
				linea7->dibujar();
				break;
			case '9':
				linea3->dibujar();
				linea4->dibujar();
				linea5->dibujar();
				linea6->dibujar();
				linea7->dibujar();
				break;
			default: break;

		}

		coordenadas.setX(coordenadas.getX()+7);
		delete linea1;
        delete linea2;
        delete linea3;
        delete linea4;
        delete linea5;
        delete linea6;
        delete linea7;
	}
	delete negativo;
}

void Numero::dibujarPunteado() {
	return dibujar();
}

void Numero::rellenar() {
}

bool Numero::contiene(int x, int y){
	return false;
}

std::string Numero::convertirReal(float value) {
    std::ostringstream o;
    if (!(o << value))
        return "";
    return o.str();
}
