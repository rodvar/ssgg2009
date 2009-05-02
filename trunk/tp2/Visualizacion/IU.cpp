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
          glutPostRedisplay();
          break;

      case 'a':
          Pantalla::getInstancia()->setEjesVisibles(!Pantalla::getInstancia()->ejesVisibles());
          glutPostRedisplay();
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
    }
}
