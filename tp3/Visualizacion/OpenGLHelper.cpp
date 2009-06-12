#include "OpenGLHelper.h"
#include <iostream>

OpenGLHelper::OpenGLHelper()
{
    //ctor
}

OpenGLHelper::~OpenGLHelper()
{
    //dtor
}


void OpenGLHelper::dibujarRecta(float longitud){
    glBegin(GL_LINES);
        glVertex3f(0.0f,0.0f,0.0f);
        glVertex3f(0.0f,0.0f,longitud);
    glEnd();
}

void OpenGLHelper::dibujarCurva(std::list<Coordenadas> discretizacion){
    std::list<Coordenadas>::iterator it = discretizacion.begin();
    glBegin(GL_LINE_STRIP);
        while (it != discretizacion.end()){
            ((Coordenadas)*it).dibujar();
            it++;
        }
    glEnd();
}

void OpenGLHelper::dibujarCircunferencia(const float radio, const float paso){
    float x,y;
    glBegin(GL_LINE_STRIP);
    for(float alfa = 0.0f; alfa < (2 * GL_PI); alfa += paso){
        x = radio * cos(alfa);
        y = radio * sin(alfa);
        glVertex3f(x,y,0.0f);
    }
    glEnd();
}

void OpenGLHelper::dibujarAbanico(const float radio, const float paso){
    unsigned short int tamano = (int)((2 * GL_PI)/paso + 1);
    Coordenadas puntos[tamano];
    discretizarCurva(puntos, radio, paso);

    glBegin(GL_LINE_STRIP);
        for (int j =0; j < tamano; j++){
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(puntos[j].getX(), puntos[j].getY(), 0.0f);

            glVertex3f(puntos[j].getX(), puntos[j].getY(), 0.0f);
            if (j < tamano-1)
                glVertex3f(puntos[j+1].getX(), puntos[j+1].getY(), 0.0f);
            else
                glVertex3f(puntos[0].getX(), puntos[0].getY(), 0.0f);
        }
    glEnd();
}

void OpenGLHelper::dibujarBarandal(const float radio, const float paso, const float alto){
    // TODO: ESTO VA EN EL FARO!!! Atomizar operacion basica para lograrlo
    unsigned short int tamano = (int)((2 * GL_PI)/paso + 1);
    Coordenadas puntos[tamano];
    discretizarCurva(puntos, radio, paso);

    glBegin(GL_LINE_STRIP);
        for (int j =0; j < tamano; j++){
            glVertex3f(0.0f, 0.0f, 0.0f);
            glVertex3f(puntos[j].getX(), puntos[j].getY(), 0.0f);

            glVertex3f(puntos[j].getX(), puntos[j].getY(), 0.0f);
            if (j < tamano-1)
                glVertex3f(puntos[j+1].getX(), puntos[j+1].getY(), 0.0f);
            else
                glVertex3f(puntos[0].getX(), puntos[0].getY(), 0.0f);
        }
    glEnd();
}

void OpenGLHelper::dibujarEjes()
{
	glDisable(GL_LIGHTING);
	glBegin(GL_LINES);
		// X
		glColor3f(1.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		//glColor3f(0.0, 0.0, 0.0);
		glVertex3f(15.0, 0.0, 0.0);
		// Y
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(0.0, 0.0, 0.0);
		//glColor3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 15.0, 0.0);
		// Z
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.0, 0.0, 0.0);
		//glColor3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 15.0);
	glEnd();
	glEnable(GL_LIGHTING);
}

void OpenGLHelper::dibujarGrillaXY()
{
	int i;
	glDisable(GL_LIGHTING);
	glColor3f(0.15, 0.1, 0.1);
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

bool OpenGLHelper::mostrarError(){
    GLenum error = glGetError();
    if (error != GL_NO_ERROR)
        std::cout << gluErrorString(error) << std::endl;
    return (error != GL_NO_ERROR);
}

// private
void OpenGLHelper::discretizarCurva(Coordenadas* vector, const float radio, const float paso){
    Coordenadas punto;
    unsigned short int i = 0;
    for(float alfa = 0.0f; alfa < (2 * GL_PI); alfa += paso){
        punto.setX((float)(radio * cos(alfa)));
        punto.setY((float)(radio * sin(alfa)));
        vector[i++] = punto;
    }
}
