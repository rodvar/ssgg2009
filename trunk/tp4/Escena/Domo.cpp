#include "Domo.h"

#define BASE  0.55f
#define PASO  (float)1/6
#define TECHO 1.00f
#define PISO  0.00f

Domo::Domo(const float lado, const float altura) {
	this->lado = lado;
	this->altura = altura;
}

Domo::~Domo() {}

void Domo::dibujar() {
    Coordenadas c;
	glColor4f(1, 1, 1, 1);
    glPushMatrix();
        glBegin(GL_QUADS);//techo
            c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,UNITARIO,-UNITARIO));
            glNormal3f(c.getX(),c.getY(),c.getZ()); //(1)
            glTexCoord2f(PASO*2,TECHO);
            glVertex3f(NULO,NULO,NULO);
            c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,UNITARIO,-UNITARIO));
            glNormal3f(c.getX(),c.getY(),c.getZ()); //(2)
            glTexCoord2f(PASO*2,PISO);
            glVertex3f(lado,NULO,NULO);
            c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,-UNITARIO,-UNITARIO));
            glNormal3f(c.getX(),c.getY(),c.getZ()); //(3)
            glTexCoord2f(PASO*3,PISO);
            glVertex3f(lado,lado,NULO);
            c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,-UNITARIO,-UNITARIO));
            glNormal3f(c.getX(),c.getY(),c.getZ()); //(4)
            glTexCoord2f(PASO*3,TECHO);
            glVertex3f(NULO,lado,NULO);
        glEnd();
    glPopMatrix();
    glPushMatrix();
        glRotated(90,NULO,UNITARIO,NULO);
        glBegin(GL_QUADS);// x = 0
            c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,UNITARIO,UNITARIO));
            glNormal3f(c.getX(),c.getY(),c.getZ()); //(1)
            glTexCoord2f(PISO,TECHO);
            glVertex3f(NULO,NULO,NULO);
            c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,UNITARIO,UNITARIO));
            glNormal3f(c.getX(),c.getY(),c.getZ()); //(5)
            glTexCoord2f(PISO,BASE);
            glVertex3f(altura,NULO,NULO);
            c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,-UNITARIO,UNITARIO));
            glNormal3f(c.getX(),c.getY(),c.getZ()); //(6)
            glTexCoord2f(PASO,BASE);
            glVertex3f(altura,lado,NULO);
            c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,-UNITARIO,UNITARIO));
            glNormal3f(c.getX(),c.getY(),c.getZ()); //(4)
            glTexCoord2f(PASO,TECHO);
            glVertex3f(NULO,lado,NULO);
        glEnd();
    glPopMatrix();
    glPushMatrix();// x = lado
        glTranslated(this->lado,NULO,-this->altura);
        glRotated(-90,NULO,UNITARIO,NULO);
        glBegin(GL_QUADS);
            c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,UNITARIO,UNITARIO));
            glNormal3f(c.getX(),c.getY(),c.getZ()); //(2)
            glTexCoord2f(PASO*2,BASE);
            glVertex3f(NULO,NULO,NULO);
            c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,UNITARIO,UNITARIO));
            glNormal3f(c.getX(),c.getY(),c.getZ()); //(7)
            glTexCoord2f(PASO*2,TECHO);
            glVertex3f(altura,NULO,NULO);
            c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,-UNITARIO,UNITARIO));
            glNormal3f(c.getX(),c.getY(),c.getZ()); //(8)
            glTexCoord2f(PASO,TECHO);
            glVertex3f(altura,lado,NULO);
            c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,-UNITARIO,UNITARIO));
            glNormal3f(c.getX(),c.getY(),c.getZ()); //(3)
            glTexCoord2f(PASO,BASE);
            glVertex3f(NULO,lado,NULO);
        glEnd();
    glPopMatrix();
    glPushMatrix(); // y = 0
        glRotated(-90,UNITARIO,NULO,NULO);
        glBegin(GL_QUADS);
            c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,UNITARIO,UNITARIO));
            glNormal3f(c.getX(),c.getY(),c.getZ()); //(5)
            glTexCoord2f(PASO*5,TECHO);
            glVertex3f(NULO,NULO,NULO);
            c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,UNITARIO,UNITARIO));
            glNormal3f(c.getX(),c.getY(),c.getZ()); //(7)
            glTexCoord2f(PASO*4,TECHO);
            glVertex3f(lado,NULO,NULO);
            c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,-UNITARIO,UNITARIO));
            glNormal3f(c.getX(),c.getY(),c.getZ()); //(2)
            glTexCoord2f(PASO*4,BASE);
            glVertex3f(lado,altura,NULO);
            c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,-UNITARIO,UNITARIO));
            glNormal3f(c.getX(),c.getY(),c.getZ()); //(1)
            glTexCoord2f(PASO*5,BASE);
            glVertex3f(NULO,altura,NULO);
        glEnd();
    glPopMatrix();
    glPushMatrix();// y = lado
        glTranslated(0,this->lado,-this->altura);
        glRotated(90,UNITARIO,NULO,NULO);
        glBegin(GL_QUADS);
            c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,UNITARIO,UNITARIO));
            glNormal3f(c.getX(),c.getY(),c.getZ()); //(6)
            glTexCoord2f(PASO*5,BASE);
            glVertex3f(NULO,NULO,NULO);
            c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,UNITARIO,UNITARIO));
            glNormal3f(c.getX(),c.getY(),c.getZ()); //(8)
            glTexCoord2f(PASO*6,BASE);
            glVertex3f(lado,NULO,NULO);
            c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,-UNITARIO,UNITARIO));
            glNormal3f(c.getX(),c.getY(),c.getZ()); //(3)
            glTexCoord2f(PASO*6,TECHO);
            glVertex3f(lado,altura,NULO);
            c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,-UNITARIO,UNITARIO));
            glNormal3f(c.getX(),c.getY(),c.getZ()); //(4)
            glTexCoord2f(PASO*5,TECHO);
            glVertex3f(NULO,altura,NULO);
        glEnd();
    glPopMatrix();
}
