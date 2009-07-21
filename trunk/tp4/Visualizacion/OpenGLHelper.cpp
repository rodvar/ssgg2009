#include "OpenGLHelper.h"
#include <iostream>

// Atributos
bool OpenGLHelper::aplicarTextura = false;

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

void OpenGLHelper::dibujarCuboide(const float ancho, const float alto, const float largo){
    glPushMatrix();// Techo
        glTranslatef(NULO,NULO,largo);
        OpenGLHelper::dibujarRectangulo(ancho,alto);
    glPopMatrix();
    glPushMatrix();// Piso
        glTranslatef(NULO,alto,NULO);
        glRotatef(180,1,0,0);
        OpenGLHelper::dibujarRectangulo(ancho,alto);
    glPopMatrix();
    glPushMatrix();// Costado ancho, alto
        glRotatef(90,1,0,0); // Lo paro contra el plano y = 0
        OpenGLHelper::dibujarRectangulo(ancho,largo);
    glPopMatrix();
    glPushMatrix();// Costado ancho, alto
        glTranslatef(0,alto,largo);
        glRotatef(-90,1,0,0); // Lo paro contra el plano y = 0
        OpenGLHelper::dibujarRectangulo(ancho,largo);
    glPopMatrix();
    glPushMatrix();// Costado alto, largo
        glRotatef(-90,0,1,0); // Lo paro contra el plano x = 0
        OpenGLHelper::dibujarRectangulo(largo,alto);
    glPopMatrix();
    glPushMatrix();// Costado alto, largo
        glTranslatef(ancho,0,largo);
        glRotatef(90,0,1,0); // Lo paro contra el plano x = 0
        OpenGLHelper::dibujarRectangulo(largo,alto);
    glPopMatrix();
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
    if (aplicarTextura)
        gluQuadricTexture(quadric, GL_TRUE);
    gluCylinder(quadric, radioBase, radioTapa, altura , precision, precision);
    gluDeleteQuadric(quadric);
}

void OpenGLHelper::dibujarAbanico(const float paso, const float radio){
    unsigned short int tamano = (int)(DOSPI/paso);
    Coordenadas puntos[tamano];
    Coordenadas norma;
    Matematica::discretizarCircunferencia(puntos, radio, paso, NULO);

    glBegin(GL_TRIANGLE_FAN);
        glNormal3f(NULO,NULO,-UNITARIO);
        glVertex3f(0.0f,0.0f,0.0f);
        glTexCoord2f(0.5f,0.0f);
        for (int j =0; j < tamano; j++){
            norma = puntos[j];
            Matematica::normalizar(norma);
            glNormal3f(norma.getX(),norma.getY(),norma.getZ());
            glTexCoord2f(j%2,1.0f);
            glVertex3f(puntos[j].getX(), puntos[j].getY(), 0.0f);
        }
        glVertex3f(puntos[0].getX(), puntos[0].getY(), 0.0f);
    glEnd();
}

void OpenGLHelper::dibujarSamba(const float precision, const float radio, const float altura){
    float deltaAlfa = 360.0f/precision;
    float radioExtendido = 1.1f*radio;
    Coordenadas proxPuntoCirc= Matematica::rotar(Coordenadas(radio,NULO,NULO),deltaAlfa);
    Coordenadas proxPuntoCircExt= Matematica::rotar(Coordenadas(radioExtendido,NULO,NULO),deltaAlfa);
    Coordenadas normal = Matematica::calcularNormal(Coordenadas(1,0,0),deltaAlfa);
    for (int i = 0; i < precision ; i++){
        glPushMatrix();
            glRotatef(i*deltaAlfa,0,0,1);
            glBegin(GL_QUADS);// Baranda
                glNormal3f(-1,0,0);
                glTexCoord2f(0,0);
                glVertex3f(radio,0.0f,0.0f);
                glTexCoord2f(0,1);
                glVertex3f(radio,0.0f,altura);
                glNormal3f(-normal.getX(),normal.getY(),normal.getZ()); // Asegura sup suave
                glTexCoord2f(1,1);
                glVertex3f(proxPuntoCirc.getX(),proxPuntoCirc.getY(),altura);
                glTexCoord2f(1,0);
                glVertex3f(proxPuntoCirc.getX(),proxPuntoCirc.getY(),NULO);
                //idem para la extension
                glNormal3f(1,0,0);
                glTexCoord2f(0,0);
                glVertex3f(radioExtendido,0.0f,0.0f);
                glTexCoord2f(0,1);
                glVertex3f(radioExtendido,0.0f,altura);
                glNormal3f(normal.getX(),normal.getY(),normal.getZ()); // Asegura sup suave
                glTexCoord2f(1,1);
                glVertex3f(proxPuntoCircExt.getX(),proxPuntoCircExt.getY(),altura);
                glTexCoord2f(1,0);
                glVertex3f(proxPuntoCircExt.getX(),proxPuntoCircExt.getY(),NULO);
                //Le pongo la tapa
                glNormal3f(-UNITARIO,NULO,NULO);
                glTexCoord2f(0,0);
                glVertex3f(radio,0.0f,altura);
                glNormal3f(-normal.getX(),normal.getY(),normal.getZ());
                glTexCoord2f(0,1);
                glVertex3f(proxPuntoCirc.getX(),proxPuntoCirc.getY(),altura);
                glNormal3f(normal.getX(),normal.getY(),normal.getZ());
                glTexCoord2f(1,1);
                glVertex3f(proxPuntoCircExt.getX(),proxPuntoCircExt.getY(),altura);
                glNormal3f(UNITARIO,NULO,NULO);
                glTexCoord2f(1,0);
                glVertex3f(radioExtendido,0.0f,altura);
            glEnd();
        glPopMatrix();
    }
    glPushMatrix();
        OpenGLHelper::dibujarAbanico(Matematica::anguloRadianes(deltaAlfa),radioExtendido);
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
