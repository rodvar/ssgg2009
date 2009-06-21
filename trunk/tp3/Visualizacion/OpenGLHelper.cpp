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

void OpenGLHelper::dibujarRectangulo(const float base, const float altura){
    glBegin(GL_QUADS);
        glVertex3f(0.0f,0.0f,0.0f);
        glVertex3f(base,0.0f,0.0f);
        glVertex3f(base,altura,0.0f);
        glVertex3f(0.0f,altura,0.0f);
    glEnd();
}

void OpenGLHelper::dibujarCuadrado(const float lado){
    dibujarRectangulo(lado,lado);
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

void OpenGLHelper::dibujarCircunferencia(const float paso){
    float radio = 1.0f;
    float x,y;
    glBegin(GL_LINE_STRIP);
        for(float alfa = 0.0f; alfa < DOSPI; alfa += paso){
            x = radio * cos(alfa);
            y = radio * sin(alfa);
            glVertex3f(x,y,0.0f);
        }
    glEnd();
}

void OpenGLHelper::dibujarCirculo(const float paso){
    float radio = 1.0f;
    float x,y;
    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0.0f,0.0f,0.0f);
        for(float alfa = 0.0f; alfa < DOSPI; alfa += paso){
            x = radio * cos(alfa);
            y = radio * sin(alfa);
            glVertex3f(x,y,0.0f);
        }
        glVertex3f(radio,0.0f,0.0f);
    glEnd();
}

void OpenGLHelper::dibujarCilindro(const float precision){
    GLUquadricObj* quadric = gluNewQuadric();
    gluCylinder(quadric, UNITARIO, UNITARIO, UNITARIO , precision, precision);
    gluDeleteQuadric(quadric);
}

void OpenGLHelper::dibujarAbanico(const float paso){
    const float radio = UNITARIO;
    unsigned short int tamano = (int)(DOSPI/paso + 1);
    Coordenadas puntos[tamano];
    Matematica::discretizarCircunferencia(puntos, radio, paso, NULO);

    glBegin(GL_TRIANGLE_FAN);
        glVertex3f(0.0f,0.0f,0.0f);
        for (int j =0; j < tamano; j++)
            glVertex3f(puntos[j].getX(), puntos[j].getY(), 0.0f);
        glVertex3f(puntos[0].getX(), puntos[0].getY(), 0.0f);
    glEnd();
}

void OpenGLHelper::dibujarSamba(const float precision){
    float deltaAlfa = 360.0f/precision;
    float base = sin(DOSPI/precision);
    float radio = 1.0f;
    float altura = 1.0f;
    Coordenadas normal1 = Matematica::calcularNormal(Coordenadas(1,0,0),-deltaAlfa);
    Coordenadas normal2 = Matematica::calcularNormal(Coordenadas(1,0,0),deltaAlfa);

    for (int i = 0; i < precision ; i++){
        glPushMatrix();
            glRotatef(i*deltaAlfa,0,0,1);
            glBegin(GL_QUADS);// Baranda
                glNormal3f(normal1.getX(),normal1.getY(),normal1.getZ()); // Asegura sup suave
                glVertex3f(radio,-base/2,0.0f);
                glVertex3f(radio,-base/2,altura);
                glNormal3f(normal2.getX(),normal2.getY(),normal2.getZ()); // Asegura sup suave
                glVertex3f(radio,base/2,altura);
                glVertex3f(radio,base/2,0.0f);
            glEnd();
        glPopMatrix();
    }
    glPushMatrix();
        OpenGLHelper::dibujarAbanico(0.20f*radio);
    glPopMatrix();
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
	glColor3f(0.27, 0.44, 0.76);
	glBegin(GL_QUADS);
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

void OpenGLHelper::cambiarModoPoligonos(){
    static GLenum mode = GL_FILL;
    (mode == GL_FILL) ? mode = GL_LINE : mode = GL_FILL;
    glPolygonMode( GL_FRONT_AND_BACK, mode);
}

bool OpenGLHelper::mostrarError(){
    GLenum error = glGetError();
    if (error != GL_NO_ERROR)
        std::cout << gluErrorString(error) << std::endl;
    return (error != GL_NO_ERROR);
}
