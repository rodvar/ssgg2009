#include "Grilla.h"
#include "../Geometria/Segmento.h"


Grilla::Grilla(int filas, int columnas, float dx, float dy, Coordenadas* posicion)
{
    this->origen = posicion;
    this->filas = filas;
    this->columnas = columnas;
    this->unidadX = floor(dx);
    this->unidadY = floor(dy);
    int corrX = unidadX/2;
    int corrY = unidadY/2;
    bool cuadrada;
    Coordenadas* coordenadas;
    Coordenadas* centro;
    Rectangulo* rectangulo;
    (dx == dy) ? cuadrada = true : cuadrada = false;
    for (int i = 0; i < filas ; i++){
        for (int j = 0; j < columnas ; j++){
            coordenadas = new Coordenadas(i,j);
            centro = new Coordenadas((posicion->getX() + i*unidadX + corrX), (posicion->getY() - j*unidadY - corrY));
            cuadrada ? rectangulo = new Cuadrado(dx,centro) : rectangulo = new Rectangulo(dx,dy,centro);
            this->mapa.insert(pair<Coordenadas*,Rectangulo*>(coordenadas,rectangulo));
        }
    }
}

Grilla::~Grilla()
{
    delete this->origen;
    map<Coordenadas*,Rectangulo*>::iterator it=this->mapa.begin() ;
    while(it != this->mapa.end()){
        delete (it->first);
        delete (it->second);
        it++;
    }
    this->mapa.clear();
}

void Grilla::dibujar(){
    this->dibujarEjeX();
    this->dibujarEjeY();
    map<Coordenadas*,Rectangulo*>::iterator it=this->mapa.begin();
    while(it != this->mapa.end()){
        ((Rectangulo*)it->second)->dibujar();
        it++;
    }

    //Dibujo las guias de los puntos en el eje Y
    int initY = 85;
    Segmento* segmento;
    for(int i=0;i<=9;i++) {
		segmento = new Segmento(new Coordenadas(initY,525),new Coordenadas(initY,515));
		segmento->dibujar();
		initY+=50;
    }
	delete segmento;

    //Dibujo los numeros de los puntos en el eje Y
    initY = 80;
    Numero* numero;
    for(int j=0;j<=9;j++) {
		numero = new Numero(new Coordenadas(initY,535),j);
		numero->dibujar();
		initY+=50;
    }
	delete numero;

//    //Dibujo las guias de los puntos en el eje X
//    int initX = 90;
//    for(int i=0;i<9;i++) {
//		Segmento* segmento = new Segmento(new Coordenadas(initX,525),new Coordenadas(initX,515));
//		segmento->dibujar();
//		delete segmento;
//		initX+=60;
//    }
//
//    //Dibujo los numeros de los puntos en el eje X
//    initX = 85;
//    for(int j=0;j<9;j++) {
//		Numero* numero = new Numero(new Coordenadas(initX,535),j+1);
//		numero->dibujar();
//		delete numero;
//		initX+=60;
//    }
}

void Grilla::dibujarEjeY(){
    Coordenadas* desde = new Coordenadas(this->origen->getX(),0);
    Coordenadas* hasta = new Coordenadas(this->origen->getX(),this->origen->getY());
    Segmento* segmento = new Segmento(desde,hasta);
    segmento->dibujar();
    delete segmento;
}

void Grilla::dibujarEjeX(){
    Coordenadas* desde = new Coordenadas(this->origen->getX(),this->origen->getY());
    Coordenadas* hasta = new Coordenadas((ANCHO-1),this->origen->getY());
    Segmento* segmento = new Segmento(desde,hasta);
    segmento->dibujar();
    delete segmento;
}

Rectangulo* Grilla::obtenerCelda(int x, int y){
    Rectangulo* rectangulo = NULL;
    map<Coordenadas*,Rectangulo*>::iterator it=this->mapa.begin();
    while ((it != this->mapa.end()) && (!rectangulo)){
        Coordenadas* clave = (Coordenadas*)it->first;
        if ((x == clave->getX()) && (y == clave->getY()))
            rectangulo = (Rectangulo*)it->second;
        it++;
    }
    return rectangulo;
}

Rectangulo* Grilla::obtenerCelda(Coordenadas* posicion){
    return this->obtenerCelda(posicion->getX(), posicion->getY());
}

Coordenadas* Grilla::obtenerPosicion(Rectangulo* celda){
    Coordenadas* posicion = NULL;
    map<Coordenadas*,Rectangulo*>::iterator it=this->mapa.begin();
    while ((it != this->mapa.end()) && (!posicion)){
        if (((Rectangulo*)it->second) == celda)
            posicion = (Coordenadas*)it->first;
        it++;
    }
    return posicion;
}

Coordenadas* Grilla::posicionEnGrilla(int x, int y){
    Coordenadas* posicion = NULL;
    Rectangulo* rectangulo = NULL;
    map<Coordenadas*,Rectangulo*>::iterator it=this->mapa.begin();
    while ((it != this->mapa.end()) && (!posicion)){
        rectangulo = (Rectangulo*)it->second;
        if (rectangulo->contiene(x,y))
            posicion = (Coordenadas*)it->first;
        it++;
    }
    return posicion;
}

float Grilla::distanciaOrigen(Coordenadas* punto){
    return this->origen->distancia(punto);
}

bool Grilla::enRango(int x, int y){
    return ( (x >= this->origen->getX()) && (y <= this->origen->getY())
        && (x < (this->origen->getX() + this->columnas*this->unidadX))
        && (y > (this->origen->getY() - this->filas*this->unidadY)));
}
