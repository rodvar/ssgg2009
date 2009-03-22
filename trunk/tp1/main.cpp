///
/// Sistemas Gráficos - 6671
/// 1er cuatrimestre 2009
///
#include <stdlib.h>
#include "Geometria/Segmento.h"

#define ANCHO	800
#define ALTO	600

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

}

// Este metodo se llama constantemente en el loop de la ventana si no hay otro evento
void display(void)
{
    FiguraGeometrica* figura = new Segmento(new Coordenadas(),new Coordenadas(800,600));
    FiguraGeometrica* figura2 = new Segmento(new Coordenadas(0,600),new Coordenadas(800,0));
    FiguraGeometrica* figura3 = new Segmento(new Coordenadas(400,0),new Coordenadas(400,600));
    FiguraGeometrica* figura4 = new Segmento(new Coordenadas(800,300),new Coordenadas(0,300));

	///
	//glClear(GL_COLOR_BUFFER_BIT); // pinta todo de negro
   	glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
	///

    glColor3f(0.0,1.0,0.0);// Seteo el color en verde
	glBegin(GL_POINTS);

	figura->dibujar();
	figura2->dibujar();
	figura3->dibujar();
	figura4->dibujar();

	glEnd();

	delete figura;
	delete figura2;
	delete figura3;
	delete figura4;

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
	case 0x1b: // 'Escape'
		exit (1);
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
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutMainLoop();
   return 0;
}
