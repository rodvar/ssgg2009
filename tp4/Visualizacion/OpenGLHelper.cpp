#include "OpenGLHelper.h"
#include <iostream>

void OpenGLHelper::dibujarRecta(float longitud){
    glBegin(GL_LINES);
        glNormal3f(NULO,NULO,UNITARIO);
        glVertex3f(0.0f,0.0f,0.0f);
        glVertex3f(0.0f,0.0f,longitud);
    glEnd();
}

void OpenGLHelper::dibujarRectangulo(const float base, const float altura){
    glBegin(GL_QUADS);
        glNormal3f(NULO,NULO,UNITARIO);
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

void OpenGLHelper::dibujarCircunferencia(const float paso,const float radio){
    float x,y;
    glBegin(GL_LINE_STRIP);
        glNormal3f(NULO,NULO,UNITARIO);
        for(float alfa = 0.0f; alfa < DOSPI; alfa += paso){
            x = radio * cos(alfa);
            y = radio * sin(alfa);
            glVertex3f(x,y,0.0f);
        }
    glEnd();
}

void OpenGLHelper::dibujarCirculo(const float paso, const float radio){
    float x,y;
    glBegin(GL_TRIANGLE_FAN);
        glNormal3f(NULO,NULO,UNITARIO);
        glVertex3f(0.0f,0.0f,0.0f);
        for(float alfa = 0.0f; alfa < DOSPI; alfa += paso){
            x = radio * cos(alfa);
            y = radio * sin(alfa);
            glVertex3f(x,y,0.0f);
        }
        glVertex3f(radio,0.0f,0.0f);
    glEnd();
}

void OpenGLHelper::dibujarCilindro(const float precision,const float radioBase,
                                    const float radioTapa, const float altura){
    GLUquadricObj* quadric = gluNewQuadric();
    gluCylinder(quadric, radioBase, radioTapa, altura , precision, precision);
    gluDeleteQuadric(quadric);
}

void OpenGLHelper::dibujarAbanico(const float paso, const float radio){
    unsigned short int tamano = (int)(DOSPI/paso + 1);
    Coordenadas puntos[tamano];
    Coordenadas norma;
    Matematica::discretizarCircunferencia(puntos, radio, paso, NULO);

    glBegin(GL_TRIANGLE_FAN);
        glNormal3f(NULO,NULO,-UNITARIO);
        glVertex3f(0.0f,0.0f,0.0f);
        for (int j =0; j < tamano; j++){
            norma = puntos[j];
            Matematica::normalizar(norma);
            glNormal3f(norma.getX(),norma.getY(),norma.getZ());
            glVertex3f(puntos[j].getX(), puntos[j].getY(), 0.0f);
        }
        glVertex3f(puntos[0].getX(), puntos[0].getY(), 0.0f);
    glEnd();
}

void OpenGLHelper::dibujarSamba(const float precision, const float radio, const float altura){
    float deltaAlfa = 360.0f/precision;
    float base = sin(DOSPI/precision);
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
        OpenGLHelper::dibujarAbanico(0.25*radio,radio);
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
	glColor3f(0.27, 0.44, 0.76);
	glBegin(GL_QUADS);
        glNormal3f(NULO,NULO,UNITARIO);
        for(int i=-200; i<=200; i++){
            for(int j=-200; j<=200; j++){
                glVertex3i(j, i ,0.0f);
                glVertex3i(j+1 , i ,0.0f);
                glVertex3i(j+1 , i+1 ,0.0f);
                glVertex3i(j , i+1,0.0f);
            }
        }
	glEnd();
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
