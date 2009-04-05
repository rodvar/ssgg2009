#include "Motor.h"

void Motor::actualizar(){
    this->pantalla->actualizar(this->datos);
}

void Motor::cambiarModo(){
    if (this->modo == 'D')
        this->modo = 'B';
    else
        this->modo = 'D';
    delete this->pantalla;
    list<FiguraGeometrica*>::iterator it=this->datos.begin() ;
    while(it != this->datos.end()){
        delete ((FiguraGeometrica*)*it);
        it++;
    }
    this->datos.clear();
    this->pantalla = new Pantalla();
}

void Motor::simulacionBresenham(Coordenadas* cRadio){
    Circunferencia* circunferencia = new Circunferencia(
        this->pantalla->getGrilla()->distanciaOrigen(cRadio), this->pantalla->getGrilla()->getOrigen());

    delete circunferencia;
}

void Motor::simulacionDDA(Coordenadas* desde, Coordenadas* hasta){
    Segmento* segmento = new Segmento(desde, hasta);

    delete segmento;
}
