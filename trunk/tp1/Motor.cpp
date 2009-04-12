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
//    Coordenadas* coordenadas;
    Rectangulo* celda;
    this->limpiarBufferDatos();

    this->datos.insert(this->datos.end(),segmento);

//    celda = grilla->obtenerCelda(desde->getX(), desde->getY());
//    celda->setColorRelleno(0,1,0);
//    celda->dibujar();
//    delete celda;

	int dx = hasta->getX()-desde->getX();
	int dy = hasta->getY()-desde->getY();
	int steps, k;
	float xIncrement, yIncrement, x=desde->getX(), y=desde->getY();
	if (abs(dx)>abs(dy)) {
		steps = abs(dx);
	} else {
		steps = abs(dy);
	}
	xIncrement = dx / (float)steps;
	yIncrement = dy / (float)steps;
	celda = grilla->obtenerCelda(grilla->posicionEnGrilla((int)(x+0.5), (int)(y+0.5)));
	celda->setColorRelleno(0,1,0);
	celda->dibujar();
//	delete celda;
	for(k=0;k<steps;k++) {
		x+=xIncrement;
		y+=yIncrement;
		celda = grilla->obtenerCelda(grilla->posicionEnGrilla((int)(x+0.5), (int)(y+0.5)));
		celda->setColorRelleno(0,1,0);
		celda->dibujar();
//		delete celda;
	}

//    celdaHasta = grilla->obtenerCelda(hasta->getX(), hasta->getY());
//    celdaHasta->setColorRelleno(0,1,0);
//    celdaHasta->dibujar();

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