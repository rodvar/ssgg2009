#include "Domo.h"

Domo::Domo(const float lado, const float altura) {
	this->lado = lado;
	this->altura = altura;
}

Domo::~Domo() {}

void Domo::dibujar() {
    // TODO: Agregar coordenadas de la textura glTexCoord2f(x,y) para cada vertice

	glBindTexture(GL_TEXTURE_2D, this->idTextura);
	//Bottom
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	Coordenadas c;
	glColor4f(135.0f/256.0f, 206.0f/256.0f, 255.0f/256.0f, 0.0f);
	glPushMatrix();
		glPushMatrix();
			glBegin(GL_QUADS); // Nico esto es el piso ?!?
				c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(1)
				glTexCoord2f(0.5,0.0);
				glVertex3f(NULO,NULO,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(2)
				glTexCoord2f(0.66,0.0);
				glVertex3f(lado,NULO,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,-UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(3)
				glTexCoord2f(0.66,1.0);
				glVertex3f(lado,lado,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,-UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(4)
				glTexCoord2f(0.5,1.0);
				glVertex3f(NULO,lado,NULO);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glRotated(90,NULO,UNITARIO,NULO);
			glBegin(GL_QUADS);
				c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(1)
				glTexCoord2f(0.0,0.5);
				glVertex3f(NULO,NULO,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,UNITARIO,NULO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(5)
				glTexCoord2f(0.16,0.5);
				glVertex3f(lado,NULO,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,-UNITARIO,NULO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(6)
				glTexCoord2f(0.16,1.0);
				glVertex3f(lado,lado,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,-UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(4)
				glTexCoord2f(0.0,1.0);
				glVertex3f(NULO,lado,NULO);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glRotated(90,NULO,UNITARIO,NULO);
			glTranslated(NULO,NULO,this->lado);
			glBegin(GL_QUADS);
				c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(2)
				glVertex3f(NULO,NULO,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,UNITARIO,NULO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(7)
				glVertex3f(lado,NULO,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,-UNITARIO,NULO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(8)
				glVertex3f(lado,lado,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,-UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(3)
				glVertex3f(NULO,lado,NULO);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glRotated(90,UNITARIO,NULO,NULO);
			glTranslated(NULO,-this->lado,NULO);
			glBegin(GL_QUADS);
				c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,UNITARIO,NULO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(5)
				glVertex3f(NULO,NULO,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,UNITARIO,NULO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(7)
				glVertex3f(lado,NULO,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(2)
				glVertex3f(lado,lado,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(1)
				glVertex3f(NULO,lado,NULO);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glRotated(90,UNITARIO,NULO,NULO);
			glTranslated(NULO,-this->lado,-this->lado);
			glBegin(GL_QUADS);
				c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,-UNITARIO,NULO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(6)
				glVertex3f(NULO,NULO,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,-UNITARIO,NULO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(8)
				glVertex3f(lado,NULO,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,-UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(3)
				glVertex3f(lado,lado,NULO);
				c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,-UNITARIO,-UNITARIO));
				glNormal3f(c.getX(),c.getY(),c.getZ()); //(4)
				glVertex3f(NULO,lado,NULO);
			glEnd();
		glPopMatrix();
	glPopMatrix();

}
