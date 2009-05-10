#include "Pantalla.h"
#include "../Interaccion/IU.h"
#include "../Escenario/Rama.h" // Para probar...


void Pantalla::actualizar(list<FiguraGeometrica*> figuras){
    float* ojoCamara = this->camara.getOjo();
    float* sobreCamara = this->camara.getSobre();
    float* arribaCamara = this->camara.getArriba();

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	////////////////// Escena 3D
	Pantalla::getInstancia()->setAmbiente3D();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (ojoCamara[0], ojoCamara[1], ojoCamara[2], sobreCamara[0],
        sobreCamara[1], sobreCamara[2], arribaCamara[0], arribaCamara[1], arribaCamara[2]);

	if (Pantalla::getInstancia()->ejesVisibles())
		 glCallList(this->getDL_AXIS());

	if (Pantalla::getInstancia()->grillaVisible())
		 glCallList(this->getDL_GRID());

    glDisable(GL_LIGHTING);
    // Todo: Aca dibujar lo que haya que actualizar
	Hoja* hoja = new Hoja();
	Rama* rama = new Rama(*hoja,45);
	rama->dibujar();
	delete hoja;
	delete rama;
	glEnable(GL_LIGHTING);
    ////////////////// Fin


	////////////////// Panel 2D para la vista superior
	Pantalla::getInstancia()->setAmbiente2DSuperior();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (0, 0, 0.5, 0, 0, 0, 0, 1, 0);
	glCallList(this->getDL_AXIS2D_TOP());
	glDisable(GL_LIGHTING);
	// TODO: Aca dibujar lo que haya q dibujar
	glEnable(GL_LIGHTING);
	////////////////// Fin

	////////////////// Panel 2D para la vista del perfil de altura
	Pantalla::getInstancia()->setAmbiente2DInferior();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (0, 0, 0.5, 0, 0, 0, 0, 1, 0);
	glCallList(this->getDL_AXIS2D_HEIGHT());
	glDisable(GL_LIGHTING);
	// TODO: Aca dibujar lo que haya q dibujar
	glEnable(GL_LIGHTING);
	////////////////// Fin

	glutSwapBuffers();
}

void Pantalla::forzarRedibujo(){
    glutPostRedisplay();
}

void Pantalla::redimensionar (int w, int h){
   	Pantalla::getInstancia()->setAncho(w);
   	Pantalla::getInstancia()->setAlto(h);
}

void Pantalla::dibujarEjes()
{
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
		// X
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(15.0, 0.0, 0.0);
		// Y
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 15.0, 0.0);
		// Z
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.0, 0.0, 0.0);
		glColor3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 15.0);
	glEnd();
	glEnable(GL_LIGHTING);
}

// Recuadro superior derecho
void Pantalla::dibujarEjesVista2DSuperior()
{
	glDisable(GL_LIGHTING);
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 1.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(1.0, 0.0, 0.0);
		glVertex3f(1.0, 1.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);
	glEnd();
	glEnable(GL_LIGHTING);
}

// Recuadro inf der
void Pantalla::dibujarEjesVista2DInferior()
{
	glDisable(GL_LIGHTING);
	glBegin(GL_LINE_LOOP);
		glColor3f(1.0, 0.5, 1.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(1.0, 0.0, 0.0);
		glVertex3f(1.0, 1.0, 0.0);
		glVertex3f(0.0, 1.0, 0.0);
	glEnd();
	glEnable(GL_LIGHTING);
}

/** Grilla 3d
 */
void Pantalla::dibujarGrilla2D()
{
	int i;
	glDisable(GL_LIGHTING);
	glColor3f(0.35, 0.1, 0.1);
	glBegin(GL_LINES);
	for(i=-20; i<21; i++)
	{
		glVertex3f(i, -20.0, 0.0);
		glVertex3f(i,  20.0, 0.0);
		glVertex3f(-20.0, i, 0.0);
		glVertex3f( 20.0, i, 0.0);
	}
	glEnd();
	glEnable(GL_LIGHTING);
}
void Pantalla::setAmbiente3D()
{
	glViewport (0, 0, (GLsizei) this->window_size[0], (GLsizei) this->window_size[1]);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    // Primer parametro para modificar zoom camara
    gluPerspective(60.0, (GLfloat) this->window_size[0]/(GLfloat) this->window_size[1], 0.10, 100.0);
}

void Pantalla::setAmbiente2DSuperior()
{
	Rectangulo* superior = IU::getInstancia()->getEditorSenderoPlantacion()->getMarco();
	glViewport (superior->getCentro().getX(), superior->getCentro().getY(), (GLsizei) superior->getBase(), (GLsizei) superior->getAltura());
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
	gluOrtho2D(-0.10, 1.05, -0.10, 1.05);

}

void Pantalla::setAmbiente2DInferior()
{
	Rectangulo* inferior = IU::getInstancia()->getEditorHoja()->getMarco();
	glViewport (inferior->getCentro().getX(), inferior->getCentro().getY(), (GLsizei)inferior->getBase(), (GLsizei) inferior->getAltura());
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
	gluOrtho2D(-0.10, 1.05, -0.10, 1.05);
}


void Pantalla::configurarEscenario(){
    this->dl_handle = glGenLists(3);
	glClearColor (0.02, 0.02, 0.04, 0.0);
    glShadeModel (GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, this->luz.getColor());
    glLightfv(GL_LIGHT0, GL_AMBIENT, this->luz.getAmbiente());
    glLightfv(GL_LIGHT0, GL_POSITION, this->luz.getPosicion());
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);

	// Generaci�n de las Display Lists
	glNewList(this->getDL_AXIS(), GL_COMPILE);
		this->dibujarEjes();
	glEndList();
	glNewList(this->getDL_GRID(), GL_COMPILE);
		this->dibujarGrilla2D();
	glEndList();
	glNewList(this->getDL_AXIS2D_TOP(), GL_COMPILE);
		this->dibujarEjesVista2DSuperior();
	glEndList();
	glNewList(this->getDL_AXIS2D_HEIGHT(), GL_COMPILE);
		this->dibujarEjesVista2DInferior();
	glEndList();
}
