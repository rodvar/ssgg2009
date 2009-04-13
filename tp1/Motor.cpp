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
    Grilla* grilla = this->pantalla->getGrilla();
    Rectangulo* sup;
    Rectangulo* inf;
    int x,y,e;
    Circunferencia* circunferencia = new Circunferencia(
        grilla->distanciaOrigen(cRadio), grilla->getOrigen());
    this->limpiarBufferDatos();
    this->datos.insert(this->datos.end(),circunferencia);

    Coordenadas* inicial = grilla->posicionEnGrilla(circunferencia->getRadio(),grilla->getOrigen()->getY());
    x = inicial->getX();
    y = inicial->getY();
    e = 0;
    while (y <= x){
        sup = grilla->obtenerCelda(x,y);
        if (sup){
            sup->setColorRelleno(0,1,0);
            sup->rellenar();
        }
        inf = grilla->obtenerCelda(y,x);
        if (inf){
            inf->setColorRelleno(0,1,0);
            inf->rellenar();
        }
        e = e + 2*y + 1;
        y++;
        if ( 2*e > ( 2*x - 1)) {
            x--;
            e = e - 2*x + 1;
        }
    }
    this->actualizar();
}

void Motor::simulacionDDA(Coordenadas* desde, Coordenadas* hasta){
    Grilla* grilla = this->pantalla->getGrilla();
    Segmento* segmento = new Segmento(desde, hasta);
//    Coordenadas* coordenadas;
    Rectangulo* celda;
    this->limpiarBufferDatos();

    this->datos.insert(this->datos.end(),segmento);

    /* -- Simulacion del DDALine --> */
    Coordenadas* posicionDesde = grilla->posicionEnGrilla(desde->getX(), desde->getY());
    Coordenadas* posicionHasta = grilla->posicionEnGrilla(hasta->getX(), hasta->getY());
    int dx = hasta->getX()-desde->getX();
	int dy = hasta->getY()-desde->getY();
	int steps, k;
	float xIncrement, yIncrement, x=desde->getX(), y=desde->getY();
	if (abs(dx)>abs(dy)) {
		steps = abs(posicionHasta->getX()-posicionDesde->getX());
	} else {
		steps = abs(posicionHasta->getY()-posicionDesde->getY());
	}
	xIncrement = dx / (float)steps;
	yIncrement = dy / (float)steps;
	celda = grilla->obtenerCelda(grilla->posicionEnGrilla((int)(x+0.5), (int)(y+0.5)));
	celda->setColorRelleno(0,1,0);
	celda->dibujar();
	for(k=0;k<steps;k++) {
		x+=xIncrement;
		y+=yIncrement;
		celda = grilla->obtenerCelda(grilla->posicionEnGrilla((int)(x+0.5), (int)(y+0.5)));
		celda->setColorRelleno(0,1,0);
		celda->dibujar();
	}
    /* <-- Simulacion del DDALine -- */

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
