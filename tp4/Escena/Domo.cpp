#include "Domo.h"

Domo::Domo(const float lado) {
	this->lado = lado;
}

Domo::~Domo() {}

void Domo::dibujar() {
	glPushMatrix();
		glPushMatrix();
			glBegin(GL_QUADS);
				glNormal3f(UNITARIO,UNITARIO,-UNITARIO); //(1)
				glVertex3f(NULO,NULO,NULO);
				glNormal3f(-UNITARIO,UNITARIO,-UNITARIO); //(2)
				glVertex3f(lado,NULO,NULO);
				glNormal3f(-UNITARIO,-UNITARIO,-UNITARIO); //(3)
				glVertex3f(lado,lado,NULO);
				glNormal3f(UNITARIO,-UNITARIO,-UNITARIO); //(4)
				glVertex3f(NULO,lado,NULO);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glRotated(90,NULO,UNITARIO,NULO);
			glBegin(GL_QUADS);
				glNormal3f(UNITARIO,UNITARIO,-UNITARIO); //(1)
				glVertex3f(NULO,NULO,NULO);
				glNormal3f(UNITARIO,UNITARIO,NULO); //(5)
				glVertex3f(lado,NULO,NULO);
				glNormal3f(UNITARIO,-UNITARIO,NULO); //(6)
				glVertex3f(lado,lado,NULO);
				glNormal3f(UNITARIO,-UNITARIO,-UNITARIO); //(4)
				glVertex3f(NULO,lado,NULO);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glRotated(90,NULO,UNITARIO,NULO);
			glTranslated(NULO,NULO,this->lado);
			glBegin(GL_QUADS);
				glNormal3f(-UNITARIO,UNITARIO,-UNITARIO); //(2)
				glVertex3f(NULO,NULO,NULO);
				glNormal3f(-UNITARIO,UNITARIO,NULO); //(7)
				glVertex3f(lado,NULO,NULO);
				glNormal3f(-UNITARIO,-UNITARIO,NULO); //(8)
				glVertex3f(lado,lado,NULO);
				glNormal3f(-UNITARIO,-UNITARIO,-UNITARIO); //(3)
				glVertex3f(NULO,lado,NULO);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glRotated(90,UNITARIO,NULO,NULO);
			glTranslated(NULO,-this->lado,NULO);
			glBegin(GL_QUADS);
				glNormal3f(UNITARIO,UNITARIO,NULO); //(5)
				glVertex3f(NULO,NULO,NULO);
				glNormal3f(-UNITARIO,UNITARIO,NULO); //(7)
				glVertex3f(lado,NULO,NULO);
				glNormal3f(-UNITARIO,UNITARIO,-UNITARIO); //(2)
				glVertex3f(lado,lado,NULO);
				glNormal3f(UNITARIO,UNITARIO,-UNITARIO); //(1)
				glVertex3f(NULO,lado,NULO);
			glEnd();
		glPopMatrix();
		glPushMatrix();
			glRotated(90,UNITARIO,NULO,NULO);
			glTranslated(NULO,-this->lado,-this->lado);
			glBegin(GL_QUADS);
				glNormal3f(UNITARIO,-UNITARIO,NULO); //(6)
				glVertex3f(NULO,NULO,NULO);
				glNormal3f(-UNITARIO,-UNITARIO,NULO); //(8)
				glVertex3f(lado,NULO,NULO);
				glNormal3f(-UNITARIO,-UNITARIO,-UNITARIO); //(3)
				glVertex3f(lado,lado,NULO);
				glNormal3f(UNITARIO,-UNITARIO,-UNITARIO); //(4)
				glVertex3f(NULO,lado,NULO);
			glEnd();
		glPopMatrix();
	glPopMatrix();
}
