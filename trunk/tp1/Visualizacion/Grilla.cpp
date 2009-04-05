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

Rectangulo* Grilla::obtenerCelda(float x, float y){
    Rectangulo* rectangulo = NULL;
    map<Coordenadas*,Rectangulo*>::iterator it=this->mapa.begin();
    while ((it != this->mapa.end()) && (!rectangulo)){
        if (((Rectangulo*)it->second)->contiene(x,y))
            rectangulo = (Rectangulo*)it->second;
        it++;
    }
    return rectangulo;
}
