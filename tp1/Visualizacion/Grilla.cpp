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
        ((Rectangulo*)it->second)->dibujarPunteado();
        it++;
    }

    //Dibujo las guias de los puntos en el eje X
    int init = this->origen->getX() + this->unidadX/2;
    Segmento* segmento;
    for(int i=0;i<this->columnas;i++) {
		segmento = new Segmento(new Coordenadas(init,525),new Coordenadas(init,515));
		segmento->dibujar();
        delete segmento;
		init+=this->unidadX;
    }

    //Dibujo los numeros de los puntos en el eje X
    init = this->origen->getX() + this->unidadX/2 - 5;
    Numero* numero;
    for(int j=0;j<this->columnas;j++) {
		numero = new Numero(new Coordenadas(init,535),j);
		numero->dibujar();
        delete numero;
		init+= this->unidadX;
    }

    //Dibujo las guias de los puntos en el eje Y
    init = this->origen->getY() - this->unidadY/2;
    for(int i=0;i<this->filas;i++) {
		segmento = new Segmento(new Coordenadas(this->origen->getX() - 5,init),new Coordenadas(this->origen->getX() + 5,init));
		segmento->dibujar();
        delete segmento;
		init-=this->unidadY;
    }

    //Dibujo los numeros de los puntos en el eje X
    init = this->origen->getY() - this->unidadY/2 + 2;
    for(int j=0;j<this->columnas;j++) {
		numero = new Numero(new Coordenadas(),j);
		glPushMatrix();
		glTranslatef(this->origen->getX()-25,init,0);
        glRotatef(-90,0,0,1);
		numero->dibujar();
        glPopMatrix();
        delete numero;
		init-= this->unidadX;
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

Rectangulo* Grilla::obtenerCelda(Coordenadas posicion){
    return this->obtenerCelda(posicion.getX(), posicion.getY());
}

Coordenadas Grilla::obtenerPosicion(Rectangulo celda){
    Coordenadas posicion(-1,-1);
    Rectangulo rectangulo;
    map<Coordenadas*,Rectangulo*>::iterator it=this->mapa.begin();
    while ((it != this->mapa.end()) && (posicion.getX() ==-1)){
        rectangulo = ((Rectangulo)*it->second);
        if (rectangulo.getCentro() == celda.getCentro())
            posicion = (Coordenadas)*it->first;
        it++;
    }
    return posicion;
}

Coordenadas Grilla::posicionEnGrilla(int x, int y){
    Coordenadas posicion(-1,-1);
    Rectangulo* rectangulo = NULL;
    map<Coordenadas*,Rectangulo*>::iterator it=this->mapa.begin();
    while ((it != this->mapa.end()) && (posicion.getX() == -1)){
        rectangulo = (Rectangulo*)it->second;
        if (rectangulo->contiene(x,y))
            posicion = (Coordenadas)*it->first;
        it++;
    }
    return posicion;
}

int Grilla::posicionVirtual (const int x){
    return ((x - this->origen->getX())/this->unidadX);
}

Coordenadas* Grilla::getExtremoNE(){
    return (new Coordenadas(this->origen->getX() + this->columnas*this->unidadX,
        this->origen->getY() - this->filas*this->unidadY));
}

Coordenadas* Grilla::getExtremoSE(){
    return (new Coordenadas(this->origen->getX() + this->columnas*this->unidadX,
        this->origen->getY()));
}

float Grilla::distanciaOrigen(Coordenadas punto){
    return this->origen->distancia(punto);
}

void Grilla::regenerar(bool dobleColor){
    int x,y;
    map<Coordenadas*,Rectangulo*>::iterator it=this->mapa.begin();
    while (it != this->mapa.end()){
        if (dobleColor){
            x = ((Coordenadas*)it->first)->getX();
            y = ((Coordenadas*)it->first)->getY();
            if (x >= y){
                if (x == y)
                    ((Rectangulo*)it->second)->setRellenoParcial();
                ((Rectangulo*)it->second)->setColorRelleno(new Color(0.8,0.8,0.8));
            }
            else
                ((Rectangulo*)it->second)->setColorRelleno(new Color(1,1,1));
        }
        else
            ((Rectangulo*)it->second)->setColorRelleno(new Color(1,1,1));
        it++;
    }
}

bool Grilla::enRango(int x, int y){
    return ( (x >= this->origen->getX()) && (y <= this->origen->getY())
        && (x < (this->origen->getX() + this->columnas*this->unidadX))
        && (y > (this->origen->getY() - this->filas*this->unidadY)));
}
