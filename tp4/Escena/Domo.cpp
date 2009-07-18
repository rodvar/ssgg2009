#include "Domo.h"

#define BASE  0.485f
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
	glColor4f(135.0f/256.0f, 206.0f/256.0f, 255.0f/256.0f, 0.0f);
	glPushMatrix();
		glPushMatrix();
			glBegin(GL_QUADS);
				c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(1)
				glTexCoord2f(PASO*3,TECHO);
				glVertex3f(NULO,NULO,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(2)
				glTexCoord2f(PASO*2,TECHO);
				glVertex3f(lado,NULO,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,-UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(3)
				glTexCoord2f(PASO*2,PISO);
				glVertex3f(lado,lado,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,-UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(4)
				glTexCoord2f(PASO*3,PISO);
				glVertex3f(NULO,lado,NULO);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glRotated(90,NULO,UNITARIO,NULO);
			glBegin(GL_QUADS);
				c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(1)
				glTexCoord2f(PISO,TECHO);
				glVertex3f(NULO,NULO,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,UNITARIO,NULO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(5)
				glTexCoord2f(PISO,BASE);
				glVertex3f(lado,NULO,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,-UNITARIO,NULO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(6)
				glTexCoord2f(PASO,BASE);
				glVertex3f(lado,lado,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,-UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(4)
				glTexCoord2f(PASO,TECHO);
				glVertex3f(NULO,lado,NULO);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glRotated(90,NULO,UNITARIO,NULO);
			glTranslated(NULO,NULO,this->lado);
			glBegin(GL_QUADS);
				c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(2)
				glTexCoord2f(PASO*2,TECHO);
				glVertex3f(NULO,NULO,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,UNITARIO,NULO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(7)
				glTexCoord2f(PASO*2,BASE);
				glVertex3f(lado,NULO,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,-UNITARIO,NULO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(8)
				glTexCoord2f(PASO,BASE);
				glVertex3f(lado,lado,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,-UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(3)
				glTexCoord2f(PASO,TECHO);
				glVertex3f(NULO,lado,NULO);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glRotated(90,UNITARIO,NULO,NULO);
			glTranslated(NULO,-this->lado,NULO);
			glBegin(GL_QUADS);
				c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,UNITARIO,NULO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(5)
				glTexCoord2f(PASO*5,BASE);
				glVertex3f(NULO,NULO,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,UNITARIO,NULO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(7)
				glTexCoord2f(PASO*4,BASE);
				glVertex3f(lado,NULO,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(2)
				glTexCoord2f(PASO*4,TECHO);
				glVertex3f(lado,lado,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(1)
				glTexCoord2f(PASO*5,TECHO);
				glVertex3f(NULO,lado,NULO);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glRotated(90,UNITARIO,NULO,NULO);
			glTranslated(NULO,-this->lado,-this->lado);
			glBegin(GL_QUADS);
				c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,-UNITARIO,NULO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(6)
				glTexCoord2f(PASO*5,BASE);
				glVertex3f(NULO,NULO,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,-UNITARIO,NULO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(8)
				glTexCoord2f(PASO*6,BASE);
				glVertex3f(lado,NULO,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,-UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(3)
				glTexCoord2f(PASO*6,TECHO);
				glVertex3f(lado,lado,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,-UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(4)
				glTexCoord2f(PASO*5,TECHO);
				glVertex3f(NULO,lado,NULO);
			glEnd();
		glPopMatrix();
	glPopMatrix();

}
