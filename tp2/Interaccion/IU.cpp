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
        case 'm':// matriz
            Pantalla::getInstancia()->setGrillaVisible(!Pantalla::getInstancia()->grillaVisible());
            break;
        case 'e':// ejes
            Pantalla::getInstancia()->setEjesVisibles(!Pantalla::getInstancia()->ejesVisibles());
            break;
        case 'x':// limpiar editor hoja
            IU::getInstancia()->editorHoja->limpiar();
            break;
        case 'z':// limpiar editor sendero
            IU::getInstancia()->editorSendero->limpiar();
            break;
        case 'c':// limpiar todo
            IU::getInstancia()->editorHoja->limpiar();
            IU::getInstancia()->editorSendero->limpiar();
            Motor::getInstancia()->limpiarBufferDatos();
            break;
        case 'g':// go -> simulacion arboleda
            IU::getInstancia()->getEditorHoja()->terminar();
            IU::getInstancia()->getEditorSenderoPlantacion()->terminar();
            Motor::getInstancia()->simularArboleda();
//            IU::getInstancia()->getEditorHoja()->limpiar();
//            IU::getInstancia()->getEditorSenderoPlantacion()->limpiar();
            break;
        case '+':// +zoom
            Pantalla::getInstancia()->aumentarZoom();
            break;
        case '-':// -zomm
            Pantalla::getInstancia()->disminuirZoom();
            break;
        case 'n':// end para indicar el fin de la edicion de la hoja
            IU::getInstancia()->editorHoja->terminar();
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

void IU::OnIdle(){
    float rotacion = Pantalla::getInstancia()->getRotacionEsfera();
    rotacion += 0.1;
	if(rotacion > 360.0) rotacion = 0.0;
	Pantalla::getInstancia()->setRotacionEsfera(rotacion);
    glutPostRedisplay();
}
