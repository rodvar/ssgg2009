#include "IU.h"
#include "../Geometria/Curva.h"

void IU::keyboard (unsigned char key, int x, int y){
    switch (key) {
        case 0x1b: // ESC
            Motor::limpiar();
            Pantalla::limpiar();
            IU::limpiar();
            exit (0);
            break;
        case 'm':
            Pantalla::getInstancia()->setGrillaVisible(!Pantalla::getInstancia()->grillaVisible());
            break;
        case 'e':
            Pantalla::getInstancia()->setEjesVisibles(!Pantalla::getInstancia()->ejesVisibles());
            break;
        case 'x':
            IU::getInstancia()->editorHoja->limpiar();
            break;
        case 'z':
            IU::getInstancia()->editorSendero->limpiar();
            break;
        case 'g':
            Motor::getInstancia()->simularArboleda();
            IU::getInstancia()->getEditorHoja()->terminar();
            IU::getInstancia()->getEditorSenderoPlantacion()->terminar();
            break;
        case '+':
            Pantalla::getInstancia()->aumentarZoom();
            break;
        case '-':
            Pantalla::getInstancia()->disminuirZoom();
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
	if(boton==GLUT_LEFT_BUTTON && estado==GLUT_DOWN) {
		if(IU::getInstancia()->getEditorHoja()->getMarco()->contiene(x,y)) {
			Coordenadas c;
			c.setX(x);
			c.setY(y);
			c.setZ(0);
			IU::getInstancia()->getEditorHoja()->agregarPunto(c);
		} else if(IU::getInstancia()->getEditorSenderoPlantacion()->getMarco()->contiene(x,y)) {
			Coordenadas c;
			c.setX(x);
			c.setY(y);
			c.setZ(0);
			IU::getInstancia()->getEditorSenderoPlantacion()->agregarPunto(c);
		}
    }

}

void IU::mousePressed(int x,int y){
    if (!(IU::getInstancia()->getEditorHoja()->getMarco()->contiene(x,y)) &&
        !(IU::getInstancia()->getEditorSenderoPlantacion()->getMarco()->contiene(x,y)))
        Pantalla::getInstancia()->calcularRotacionCamara(x,y);
}

void IU::dibujarFiguraBezier() {
	if(this->editorHoja->getPuntosEdicion().size()>3) {
		Curva curva(this->editorHoja->getPuntosEdicion());
		curva.dibujarBezier();
	}
}

void IU::dibujarFiguraBSplines() {
	if(this->editorSendero->getPuntosEdicion().size()>3) {
		Curva curva(this->editorSendero->getPuntosEdicion());
		curva.dibujarBSplines();
	}
}

void IU::OnIdle(){
    float rotacion = Pantalla::getInstancia()->getRotacionEsfera();
    rotacion += 0.1;
	if(rotacion > 360.0) rotacion = 0.0;
	Pantalla::getInstancia()->setRotacionEsfera(rotacion);
    glutPostRedisplay();
}
