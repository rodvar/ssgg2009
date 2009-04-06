#include "Motor.h"

void Motor::actualizar(){
    this->pantalla->actualizar(this->datos);
    glutPostRedisplay();
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
    this->limpiarBufferDatos();
    this->datos.insert(this->datos.end(),circunferencia);
    this->actualizar();
}

void Motor::simulacionDDA(Coordenadas* desde, Coordenadas* hasta){
    Grilla* grilla = this->pantalla->getGrilla();
    Segmento* segmento = new Segmento(desde, hasta);
    //Coordenadas* posicion;
    Rectangulo* celdaDesde;
    Rectangulo* celdaHasta;
    this->limpiarBufferDatos();
    this->datos.insert(this->datos.end(),segmento);

    celdaDesde = grilla->obtenerCelda(desde->getX(), desde->getY());
    celdaHasta = grilla->obtenerCelda(hasta->getX(), hasta->getY());

    celdaDesde->setColorRelleno(0,1,0);
    celdaDesde->dibujar();
    celdaHasta->setColorRelleno(0,1,0);
    celdaDesde->dibujar();

    this->actualizar();
}

bool Motor::enRango(int x, int y){
    return this->pantalla->getGrilla()->enRango(x,y);
}

void Motor::limpiarBufferDatos(){
    list<FiguraGeometrica*>::iterator it=this->datos.begin() ;
    while(it != this->datos.end()){
        delete ((FiguraGeometrica*)*it);
        it++;
    }
    this->datos.clear();
}
