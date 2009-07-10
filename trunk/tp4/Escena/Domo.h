#ifndef DOMO_H_
#define DOMO_H_

#include "../Visualizacion/Dibujable.h"
#include "../Visualizacion/OpenGLHelper.h"

class Domo : Dibujable {

public:
	Domo(const float lado);
	virtual ~Domo();

	/* Dibuja el domo que tiene forma de Cubo */
	void dibujar();
private:
	float lado;

	void dibujarCuadrado(const float lado);

};

#endif /* DOMO_H_ */
