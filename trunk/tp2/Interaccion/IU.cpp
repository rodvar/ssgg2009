#include "IU.h"

void IU::keyboard (unsigned char key, int x, int y){
    switch (key) {
      case 0x1b: // ESC
         Motor::limpiar();
         Pantalla::limpiar();
         IU::limpiar();
         exit (0);
         break;
      case 'g':
          Pantalla::getInstancia()->setGrillaVisible(!Pantalla::getInstancia()->grillaVisible());
          break;
      case 'a':
          Pantalla::getInstancia()->setEjesVisibles(!Pantalla::getInstancia()->ejesVisibles());
          break;
     default:
         break;
    }
}

/*
 * boton  GLUT_LEFT_BUTTON,  GLUT_MIDDLE_BUTTON, or  GLUT_RIGHT_BUTTON
 * estado GLUT_UP or GLUT_DOWN
*/
void IU::mouse(int boton, int estado, int x, int y){
    if (Motor::getInstancia()->enRango(x,y)){
    	if(boton==GLUT_LEFT_BUTTON && estado==GLUT_UP) {
//    		Rectangulo limitesBSpline = Pantalla::getInstancia()->getAmbiente2DSuperior();
//    		if(x>limitesBSpline.getVerticeSO()->getX() &&
//    		   x<limitesBSpline.getVerticeSE()->getX() &&
//    		   y>limitesBSpline.getVerticeSE()->getY() &&
//    		   y<limitesBSpline.getVerticeNE()->getY()) {
			if(x>0 &&
			   x<100 &&
			   y>0 &&
			   y<100) {
    			Coordenadas c;
    			c.setX(x);
    			c.setY(y);
    			c.setZ(0);
    			IU::getInstancia()->addPuntoControlBSplines(c);
    			Circunferencia circ(2,new Coordenadas(x,y));
    			circ.setColorRelleno(new Color(1,1,1));
    			circ.dibujar();
    		}
    	}
//    	if(boton==GLUT_RIGHT_BUTTON && estado==GLUT_UP) {
//    		if(IU::getInstancia()->getPuntosControlBSplines().size()>1) {
//    			IU::getInstancia()->dibujarFiguraBSplines();
//    		}
//    	}
    }
}

void IU::addPuntoControlBSplines(Coordenadas coordenada) {
	puntosControlBSplines.push_back(coordenada);
}

void IU::addPuntoControlBezier(Coordenadas coordenada) {
	puntosControlBezier.push_back(coordenada);
}

void IU::dibujarFiguraBSplines() {
	Curva curva(puntosControlBSplines);
	curva.dibujar();
}
void IU::OnIdle(){
    float rotacion = Pantalla::getInstancia()->getRotacionEsfera();
    rotacion += 0.1;
	if(rotacion > 360.0) rotacion = 0.0;
	Pantalla::getInstancia()->setRotacionEsfera(rotacion);
    glutPostRedisplay();
}
