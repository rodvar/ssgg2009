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
      case 'g':
          Pantalla::getInstancia()->setGrillaVisible(!Pantalla::getInstancia()->grillaVisible());
          break;
      case 'a':
          Pantalla::getInstancia()->setEjesVisibles(!Pantalla::getInstancia()->ejesVisibles());
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
    /*if (IU::getInstancia()->getEditorHoja()->getMarco()->contiene(x,y)){
        cout << "CLICK EN EDITOR DE HOJA!" << endl;
    }
    if (IU::getInstancia()->getEditorSenderoPlantacion()->getMarco()->contiene(x,y)){
        cout << "CLICK EN EDITOR DE SENDERO!" << endl;
    }*/
}

void IU::dibujarFiguraBSplines() {
	Curva curva(this->editorSendero->getPuntosEdicion());
	curva.dibujar();
}
void IU::OnIdle(){
    float rotacion = Pantalla::getInstancia()->getRotacionEsfera();
    rotacion += 0.1;
	if(rotacion > 360.0) rotacion = 0.0;
	Pantalla::getInstancia()->setRotacionEsfera(rotacion);
    glutPostRedisplay();
}
