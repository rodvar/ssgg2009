#include <math.h>
#include "Visualizacion/IU.h"
#include "Visualizacion/Pantalla.h"

// Variables que controlan la ubicaci�n de la c�mara en la Escena 3D
float eye[3] = {15.0, 15.0, 5.0};
float at[3]  = { 0.0,  0.0, 0.0};
float up[3]  = { 0.0,  0.0, 1.0};

// Variables asociadas a �nica fuente de luz de la escena
float light_color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
float light_position[3] = {10.0f, 10.0f, 8.0f};
float light_ambient[4] = {0.05f, 0.05f, 0.05f, 1.0f};

// Color de la esfera en movimiento dentro de la escena
float color_esfera[4] = {0.5f, 0.5f, 0.2f, 1.0f};

// Variable asociada al movimiento de rotaci�n de la esfera alrededor del eje Z
float rotate_sphere = 0;

// Handle para el control de las Display Lists
GLuint dl_handle;
#define DL_AXIS (dl_handle+0)
#define DL_GRID (dl_handle+1)
#define DL_AXIS2D_TOP (dl_handle+2)
#define DL_AXIS2D_HEIGHT (dl_handle+3)

void OnIdle (void)
{
	rotate_sphere += 0.1;
	if(rotate_sphere > 360.0) rotate_sphere = 0.0;
    glutPostRedisplay();
}

void init(void)
{
	dl_handle = glGenLists(3);

	glClearColor (0.02, 0.02, 0.04, 0.0);
    glShadeModel (GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

	// Generaci�n de las Display Lists
	glNewList(DL_AXIS, GL_COMPILE);
		Pantalla::getInstancia()->dibujarEjes();
	glEndList();
	glNewList(DL_GRID, GL_COMPILE);
		Pantalla::getInstancia()->dibujarGrilla2D();
	glEndList();
	glNewList(DL_AXIS2D_TOP, GL_COMPILE);
		Pantalla::getInstancia()->dibujarEjesVista2DSuperior();
	glEndList();
	glNewList(DL_AXIS2D_HEIGHT, GL_COMPILE);
		Pantalla::getInstancia()->dibujarEjesVista2DInferior();
	glEndList();
}



void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	///////////////////////////////////////////////////
	// Escena 3D
	Pantalla::getInstancia()->setAmbiente3D();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (eye[0], eye[1], eye[2], at[0], at[1], at[2], up[0], up[1], up[2]);

	if (Pantalla::getInstancia()->ejesVisibles())
		 glCallList(DL_AXIS);

	if (Pantalla::getInstancia()->grillaVisible())
		 glCallList(DL_GRID);
	//
	///////////////////////////////////////////////////


	///////////////////////////////////////////////////
	// Panel 2D para la vista superior
	Pantalla::getInstancia()->setAmbiente2DSuperior();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (0, 0, 0.5, 0, 0, 0, 0, 1, 0);
	glCallList(DL_AXIS2D_TOP);
	//
	///////////////////////////////////////////////////


	///////////////////////////////////////////////////
	// Panel 2D para la vista del perfil de altura
	Pantalla::getInstancia()->dibujarEjesVista2DInferior();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (0, 0, 0.5, 0, 0, 0, 0, 1, 0);
	glCallList(DL_AXIS2D_HEIGHT);
	//
	///////////////////////////////////////////////////

	glutSwapBuffers();
}

void reshape (int w, int h)
{
   	Pantalla::getInstancia()->setAncho(w);
   	Pantalla::getInstancia()->setAlto(h);
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (1024, 768);
   glutInitWindowPosition (0, 0);

   glutCreateWindow (argv[0]);
   glutFullScreen();
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(IU::keyboard);
   glutMouseFunc(IU::mouse);
   glutIdleFunc(OnIdle);
   glutMainLoop();
   return 0;
}
