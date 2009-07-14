#include "Domo.h"

Domo::Domo(const float lado, const float altura) {
	this->lado = lado;
	this->altura = altura;
}

Domo::~Domo() {}

void Domo::cargarImagen() {
	Image* image = ImageLoader::loadBMP(this->nombreArchivo.c_str());
	this->idTextura = ImageLoader::loadTexture(image);
}

void Domo::dibujar() {

	//Bottom
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glColor3f(1.0f, 0.2f, 0.2f);

	glBegin(GL_QUADS);
		glNormal3f(0.0, 1.0f, 0.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(-2.5f, -2.5f, 2.5f);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(2.5f, -2.5f, 2.5f);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(2.5f, -2.5f, -2.5f);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(-2.5f, -2.5f, -2.5f);
	glEnd();

	//Back
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_TRIANGLES);
		glNormal3f(0.0f, 0.0f, 1.0f);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(0.0f, 0.0f, 0.0f);
		glTexCoord2f(5.0f, 5.0f);
		glVertex3f(0.0f, 5.0f, 5.0f);
		glTexCoord2f(10.0f, 0.0f);
		glVertex3f(0.0f, 10.0f, 0.0f);
	glEnd();

	glColor3f(1.0f, 0.7f, 0.3f);
	glBegin(GL_QUADS);
		glNormal3f(1.0f, 0.0f, 0.0f);
		glVertex3f(-2.5f, -2.5f, 2.5f);
		glVertex3f(-2.5f, -2.5f, -2.5f);
		glVertex3f(-2.5f, 2.5f, -2.5f);
		glVertex3f(-2.5f, 2.5f, 2.5f);
	glEnd();


//	delete image;

//
//	glBindTexture(GL_TEXTURE_CUBE_MAP_POSITIVE_X, _textureId);
//	glBindTexture(GL_TEXTURE_CUBE_MAP_NEGATIVE_X, _textureId);
//	glBindTexture(GL_TEXTURE_CUBE_MAP_POSITIVE_Y, _textureId);
//	glBindTexture(GL_TEXTURE_CUBE_MAP_NEGATIVE_Y, _textureId);
//	glBindTexture(GL_TEXTURE_CUBE_MAP_POSITIVE_Z, _textureId);
//	glBindTexture(GL_TEXTURE_CUBE_MAP_NEGATIVE_Z, _textureId);
//
//	glEnable(GL_TEXTURE_CUBE_MAP);
//
//		glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP);
//		glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP);
//		glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_REFLECTION_MAP);
//
//		glEnable(GL_TEXTURE_GEN_S);
//		glEnable(GL_TEXTURE_GEN_T);
//		glEnable(GL_TEXTURE_GEN_R);
//
//			Coordenadas c;
//			glColor4f(135.0f/256.0f, 206.0f/256.0f, 255.0f/256.0f, 0.0f);
//			glPushMatrix();
//				glPushMatrix();
//					glBegin(GL_QUADS);
//						c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,UNITARIO,-UNITARIO));
//						glNormal3f(c.getX(),c.getY(),c.getZ()); //(1)
//						glVertex3f(NULO,NULO,NULO);
//						c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,UNITARIO,-UNITARIO));
//						glNormal3f(c.getX(),c.getY(),c.getZ()); //(2)
//						glVertex3f(lado,NULO,NULO);
//						c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,-UNITARIO,-UNITARIO));
//						glNormal3f(c.getX(),c.getY(),c.getZ()); //(3)
//						glVertex3f(lado,lado,NULO);
//						c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,-UNITARIO,-UNITARIO));
//						glNormal3f(c.getX(),c.getY(),c.getZ()); //(4)
//						glVertex3f(NULO,lado,NULO);
//					glEnd();
//				glPopMatrix();
//				glPushMatrix();
//					glRotated(90,NULO,UNITARIO,NULO);
//					glBegin(GL_QUADS);
//						c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,UNITARIO,-UNITARIO));
//						glNormal3f(c.getX(),c.getY(),c.getZ()); //(1)
//						glVertex3f(NULO,NULO,NULO);
//						c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,UNITARIO,NULO));
//						glNormal3f(c.getX(),c.getY(),c.getZ()); //(5)
//						glVertex3f(lado,NULO,NULO);
//						c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,-UNITARIO,NULO));
//						glNormal3f(c.getX(),c.getY(),c.getZ()); //(6)
//						glVertex3f(lado,lado,NULO);
//						c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,-UNITARIO,-UNITARIO));
//						glNormal3f(c.getX(),c.getY(),c.getZ()); //(4)
//						glVertex3f(NULO,lado,NULO);
//					glEnd();
//				glPopMatrix();
//				glPushMatrix();
//					glRotated(90,NULO,UNITARIO,NULO);
//					glTranslated(NULO,NULO,this->lado);
//					glBegin(GL_QUADS);
//						c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,UNITARIO,-UNITARIO));
//						glNormal3f(c.getX(),c.getY(),c.getZ()); //(2)
//						glVertex3f(NULO,NULO,NULO);
//						c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,UNITARIO,NULO));
//						glNormal3f(c.getX(),c.getY(),c.getZ()); //(7)
//						glVertex3f(lado,NULO,NULO);
//						c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,-UNITARIO,NULO));
//						glNormal3f(c.getX(),c.getY(),c.getZ()); //(8)
//						glVertex3f(lado,lado,NULO);
//						c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,-UNITARIO,-UNITARIO));
//						glNormal3f(c.getX(),c.getY(),c.getZ()); //(3)
//						glVertex3f(NULO,lado,NULO);
//					glEnd();
//				glPopMatrix();
//				glPushMatrix();
//					glRotated(90,UNITARIO,NULO,NULO);
//					glTranslated(NULO,-this->lado,NULO);
//					glBegin(GL_QUADS);
//						c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,UNITARIO,NULO));
//						glNormal3f(c.getX(),c.getY(),c.getZ()); //(5)
//						glVertex3f(NULO,NULO,NULO);
//						c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,UNITARIO,NULO));
//						glNormal3f(c.getX(),c.getY(),c.getZ()); //(7)
//						glVertex3f(lado,NULO,NULO);
//						c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,UNITARIO,-UNITARIO));
//						glNormal3f(c.getX(),c.getY(),c.getZ()); //(2)
//						glVertex3f(lado,lado,NULO);
//						c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,UNITARIO,-UNITARIO));
//						glNormal3f(c.getX(),c.getY(),c.getZ()); //(1)
//						glVertex3f(NULO,lado,NULO);
//					glEnd();
//				glPopMatrix();
//				glPushMatrix();
//					glRotated(90,UNITARIO,NULO,NULO);
//					glTranslated(NULO,-this->lado,-this->lado);
//					glBegin(GL_QUADS);
//						c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,-UNITARIO,NULO));
//						glNormal3f(c.getX(),c.getY(),c.getZ()); //(6)
//						glVertex3f(NULO,NULO,NULO);
//						c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,-UNITARIO,NULO));
//						glNormal3f(c.getX(),c.getY(),c.getZ()); //(8)
//						glVertex3f(lado,NULO,NULO);
//						c=Matematica::obtenerNormalizado(Coordenadas(-UNITARIO,-UNITARIO,-UNITARIO));
//						glNormal3f(c.getX(),c.getY(),c.getZ()); //(3)
//						glVertex3f(lado,lado,NULO);
//						c=Matematica::obtenerNormalizado(Coordenadas(UNITARIO,-UNITARIO,-UNITARIO));
//						glNormal3f(c.getX(),c.getY(),c.getZ()); //(4)
//						glVertex3f(NULO,lado,NULO);
//					glEnd();
//				glPopMatrix();
//			glPopMatrix();
//
//		glDisable(GL_TEXTURE_GEN_S);
//		glDisable(GL_TEXTURE_GEN_T);
//		glDisable(GL_TEXTURE_GEN_R);
//
//	glDisable(GL_TEXTURE_CUBE_MAP);
//	delete image;

}
