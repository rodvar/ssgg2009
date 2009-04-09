#ifndef NUMERO_H_
#define NUMERO_H_

#include "FiguraGeometrica.h"
#include "Coordenadas.h"
#include "Segmento.h"

class Numero : public FiguraGeometrica {

private:
	Coordenadas* coordenadas;
	float numero;
	int size;
	int r;
	int g;
	int b;

public:
	Numero(Coordenadas* coordenadas, float numero);

	void setSize(int size);
	void setColor(int r, int g, int b);
	void dibujar();
    void rellenar();
    bool contiene(int x, int y);


	virtual ~Numero();
};

#endif /* NUMERO_H_ */
