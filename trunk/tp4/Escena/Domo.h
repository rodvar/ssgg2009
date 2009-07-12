#ifndef DOMO_H_
#define DOMO_H_

#include "../Visualizacion/Dibujable.h"
#include "../Visualizacion/OpenGLHelper.h"
#include "../Geometria/Coordenadas.h"

class Domo : Dibujable {

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
