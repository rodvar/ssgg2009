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
    this->limpiarBufferDatos();
    this->regenerarPantalla();
}

void Motor::simulacionBresenham(Coordenadas* cRadio){
    Grilla* grilla = this->pantalla->getGrilla();
    Rectangulo* sup;
    Rectangulo* inf;
    int x,y,e;
    float incerteza,xReal;

    this->regenerarPantalla();
    this->limpiarBufferDatos();

    //Triangulo* triangulo = new Triangulo(grilla->getOrigen()->copia(), grilla->getExtremoNE(), grilla->getExtremoSE() );
    Circunferencia* circunferencia = new Circunferencia(grilla->distanciaOrigen(*cRadio), grilla->getOrigen().copia());
    Circunferencia* punto = new Circunferencia(5,cRadio);
    Segmento* divisor = new Segmento(grilla->getOrigen().copia(), grilla->getExtremoNE());
    Letra* letra = new Letra(new Coordenadas(600,10),'E');
    circunferencia->setColorBorde(new Color(1,0,0));
    divisor->setColorBorde(new Color(0,0,1));
    punto->setColorBorde(new Color(1,0,0));
    punto->setColorRelleno(new Color(1,0,0));
    //triangulo->setColorRelleno(new Color(0.5,0.5,0.5));
    //this->datos.insert(this->datos.end(),triangulo);
    this->datos.insert(this->datos.end(),divisor);
    this->datos.insert(this->datos.end(),circunferencia);
    this->datos.insert(this->datos.end(),punto);
    this->datos.insert(this->datos.end(),letra);

    x = grilla->getOrigen().getX() + floor(circunferencia->getRadio());
    y = grilla->getOrigen().getY();
    Coordenadas inicial = grilla->posicionEnGrilla(x,y);

    if (inicial.getX() == -1){
        x = grilla->posicionVirtual(x);
        y = 0;
    }else {
        x = inicial.getX();
        y = inicial.getY();
    }
    e = 0;
    while (y <= x){
        if (y != x){
            sup = grilla->obtenerCelda(y,x);
            if (sup){
                sup->setColorRelleno(0,1,0);
                sup->rellenar();
            }
        }
        Numero* numero;
        inf = grilla->obtenerCelda(x,y);
        if (inf){
            inf->setColorRelleno(0,1,0);
            inf->rellenar();
            xReal = circunferencia->calcularX(inf->getCentro().getY(),true);
            incerteza = this->calcularIncertidumbrePje(xReal, circunferencia->distanciaX(inf->getCentro()));
            numero = new Numero(new Coordenadas(600,inf->getCentro().getY()),incerteza);
            this->datos.insert(this->datos.end(),numero);
            //Numero numero(new Coordenadas(600,inf->getCentro().getY()),incerteza);
            //numero.dibujar();
            // TODO : dibujar los numeros donde corresponda
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
    Circunferencia* puntoD = new Circunferencia(5,desde->copia());
    Circunferencia* puntoH = new Circunferencia(5,hasta->copia());
    segmento->setColorBorde(new Color(1,0,0));
    puntoD->setColorBorde(new Color(1,0,0));
    puntoD->setColorRelleno(new Color(1,0,0));
    puntoH->setColorBorde(new Color(1,0,0));
    puntoH->setColorRelleno(new Color(1,0,0));
    Rectangulo* celda;
    this->regenerarPantalla();
    this->limpiarBufferDatos();


    this->datos.insert(this->datos.end(),segmento);
    this->datos.insert(this->datos.end(),puntoD);
    this->datos.insert(this->datos.end(),puntoH);

    /* -- Simulacion del DDALine --> */
    Coordenadas posicionDesde = grilla->posicionEnGrilla(desde->getX(), desde->getY());
    Coordenadas posicionHasta = grilla->posicionEnGrilla(hasta->getX(), hasta->getY());
    int dx = hasta->getX()-desde->getX();
	int dy = hasta->getY()-desde->getY();
	int steps, k;
	float xIncrement, yIncrement, x=desde->getX(), y=desde->getY();
	if (abs(dx)>abs(dy)) {
		steps = abs(posicionHasta.getX()-posicionDesde.getX());
	} else {
		steps = abs(posicionHasta.getY()-posicionDesde.getY());
	}
	xIncrement = dx / (float)steps;
	yIncrement = dy / (float)steps;
	celda = grilla->obtenerCelda(grilla->posicionEnGrilla((int)(x+0.5), (int)(y+0.5)));
	if (celda){
	    celda->setColorRelleno(0,0.5,1);
        celda->dibujar();
	}
	for(k=0;k<steps;k++) {
		x+=xIncrement;
		y+=yIncrement;
		celda = grilla->obtenerCelda(grilla->posicionEnGrilla((int)(x+0.5), (int)(y+0.5)));
		if(celda){
            celda->setColorRelleno(0,0.5,1);
            celda->dibujar();
		}
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

void Motor::regenerarPantalla(){
    this->pantalla->regenerar();
}

float Motor::calcularIncertidumbrePje(float xReal, float distancia){
    float incertidumbre = distancia/xReal;
    return (float)((int)(incertidumbre * 100))/100 ;
}
