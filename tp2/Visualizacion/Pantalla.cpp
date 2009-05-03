#include "Pantalla.h"

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
	glViewport (this->superior.getCentro().getX(), this->superior.getCentro().getY(), (GLsizei) this->superior.getBase(), (GLsizei) this->superior.getAltura());
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
	gluOrtho2D(-0.10, 1.05, -0.10, 1.05);
}

void Pantalla::setAmbiente2DInferior()
{
	glViewport (this->inferior.getCentro().getX(), this->inferior.getCentro().getY(), (GLsizei) this->inferior.getBase(), (GLsizei) this->inferior.getAltura());
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
	gluOrtho2D(-0.10, 1.05, -0.10, 1.05);
}


void Pantalla::configurarEscenario(){
    Coordenadas coordenadas(this->getAncho()*0.70f,this->getAlto()*0.70f);
    this->superior.setCentro(coordenadas);
    this->superior.setBase(this->getAncho()*0.30f);
    this->superior.setAltura(this->getAlto()*0.30f);
    coordenadas.setX(this->getAncho()*0.70f);
    coordenadas.setY(this->getAlto()*0.40f);
    this->inferior.setCentro(coordenadas);
    this->inferior.setBase(this->getAncho()*0.30f);
    this->inferior.setAltura(this->getAlto()*0.30f);
}
