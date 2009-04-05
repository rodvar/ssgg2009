///
/// Sistemas Gráficos - 6671
/// 1er cuatrimestre 2009
///
#include <stdlib.h>
#include "Motor.h"

char caption[]="Sistema Gráficos - 66.71 - 2009c1";


void reshape(int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   gluOrtho2D(0.0, (GLdouble)w, (GLdouble)h, 0.0);
}

// Aca se coloca todo lo q tenga q ver con la inicializacion del sistema
void init(void)
{
    Motor::getInstancia();
}

// Este metodo se llama constantemente en el loop de la ventana si no hay otro evento
void display(void)
{
    ///
	glClear(GL_COLOR_BUFFER_BIT); // pinta todo de negro
   	glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
	///
	glBegin(GL_POINTS);

        Motor::getInstancia()->actualizar();

	glEnd();
    ///
  	glutSwapBuffers();
	///
}

/* x, y coordenadas mouse cuando se presiona key. Resuelve los eventos de teclado
*/
void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
        case 0x1b: // 'Escape' = Cierra la aplicacion
            Motor::limpiar();
            exit (1);
            break;
        case 'c':
            Motor::getInstancia()->cambiarModo();
            glutPostRedisplay();
            break;
        default:
            break;
	}
}

/*
 * boton  GLUT_LEFT_BUTTON,  GLUT_MIDDLE_BUTTON, or  GLUT_RIGHT_BUTTON
 * estado GL_UP or GL_DOWN
*/
void mouse(int boton, int estado, int x, int y){
    switch (Motor::getInstancia()->getModo()){
        case BRESENHAM:
            // Modo p/ circunferencias
            break;
        case DDA:
            // Modo para lineas
            break;
        default:
            break;
    }
}


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (ANCHO, ALTO);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (caption);
   init ();
   glutKeyboardFunc(keyboard);
   glutMouseFunc(mouse);
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
