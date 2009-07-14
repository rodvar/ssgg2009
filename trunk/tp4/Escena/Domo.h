#ifndef DOMO_H_
#define DOMO_H_

#ifdef __APPLE__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "../Visualizacion/Texturable.h"
#include "../Visualizacion/OpenGLHelper.h"
#include "../Geometria/Coordenadas.h"
#include "../Visualizacion/ImageLoader.h"

/**
 * Clase que permite dibujar un Domo texturado, a partir de un Cubo
 */

class Domo : public Texturable {

public:
	Domo(const float lado, const float altura);
	virtual ~Domo();

	/* Dibuja el domo que tiene forma de Cubo */
	void dibujar();

private:
	float lado;
	float altura;

};

#endif /* DOMO_H_ */
