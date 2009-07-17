#include "Isla.h"
#include "../Visualizacion/OpenGLHelper.h"
#include "../Visualizacion/PintorCurva.h"
#include "../Geometria/CalculadorBspline.h"


Isla::Isla(const float altura)
{
    this->altura = altura;
    this->angulo = 15;//grados
}

Isla::~Isla()
{
    //dtor
}

void Isla::dibujar(){
    PintorCurva pintor;
    std::vector<Coordenadas> puntosDesde = this->generarCurvaNivel0();
    std::vector<Coordenadas> puntosHasta = puntosDesde;
    int pasoZ = 6;
    float angulo;

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    glPushMatrix();
    glColor3f(0.8,0.72,0.62);
    for(float z = NULO; z <= this->altura; z+=this->altura/pasoZ){
    	angulo = 1.0f+z;
		for(unsigned int i=0;i<puntosDesde.size();i++) {
			puntosDesde[i].setX(puntosHasta[i].getX());
			puntosDesde[i].setY(puntosHasta[i].getY());
			puntosDesde[i].setZ(puntosHasta[i].getZ());
			Matematica::escalarPunto(puntosHasta[i],0.95,0.90,UNITARIO);
			rotarPunto(puntosHasta[i], angulo);
			puntosHasta[i].setZ(puntosHasta[i].getZ()+z);
		}
		pintor.pintarGajo(puntosDesde,puntosHasta,Coordenadas());
    }
    pintor.pintarSuperficie(puntosHasta,Coordenadas());
    glPopMatrix();
}

void Isla::rotarPunto(Coordenadas& punto, float angulo) {
	float rad = Matematica::anguloRadianes(angulo);
	punto.setX(cos(rad)*punto.getX()-sin(rad)*punto.getY());
	punto.setY(sin(rad)*punto.getX()+cos(rad)*punto.getY());
}

std::vector<Coordenadas> Isla::generarCurvaNivel0(){
    CalculadorBspline bspline(4);
    std::vector<Coordenadas> puntos;
	puntos.push_back(Coordenadas(0.0f,8.0f,0.0f));
    puntos.push_back(Coordenadas(4.0f,ISLA_MAX_Y,0.0f));
    puntos.push_back(Coordenadas(5.0f,6.0f,0.0f));
    puntos.push_back(Coordenadas(9.0f,5.0f,0.0f));
    puntos.push_back(Coordenadas(11.0f,1.0f,0.0f));
    puntos.push_back(Coordenadas(ISLA_MAX_X,-2.0f,0.0f));
    puntos.push_back(Coordenadas(12.0f,-4.0f,0.0f));
    puntos.push_back(Coordenadas(12.0f,-7.0f,0.0f));
    puntos.push_back(Coordenadas(7.0f,-8.0f,0.0f));
    puntos.push_back(Coordenadas(4.0f,-10.0f,0.0f));
    puntos.push_back(Coordenadas(1.0f,-8.0f,0.0f));
    puntos.push_back(Coordenadas(-2.0f,ISLA_MIN_Y,0.0f));
    puntos.push_back(Coordenadas(-4.0f,-6.0f,0.0f));
    puntos.push_back(Coordenadas(-8.0f,-6.0f,0.0f));
    puntos.push_back(Coordenadas(-7.0f,-3.0f,0.0f));
    puntos.push_back(Coordenadas(ISLA_MIN_X,-1.0f,0.0f));
    puntos.push_back(Coordenadas(-7.0f,2.0f,0.0f));
    puntos.push_back(Coordenadas(ISLA_MIN_X,4.0f,0.0f));
    puntos.push_back(Coordenadas(-5.0f,7.0f,0.0f));
    puntos.push_back(Coordenadas(0.0f,8.0f,0.0f));
    puntos.push_back(Coordenadas(4.0f,ISLA_MAX_Y,0.0f));
    puntos.push_back(Coordenadas(5.0f,6.0f,0.0f));
    bspline.setControlPoints(puntos);
    return bspline.calcularPuntos();
}
