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
    float precisionZ = 10.0f;
    float deltaZ = this->altura/ precisionZ;
    PintorCurva pintor;
    std::vector<Coordenadas> puntosDesde = this->generarCurvaNivel0();
    std::vector<Coordenadas> puntosHasta = this->generarCurvaNivel1();
    for(float z = NULO; z <= this->altura; z+=deltaZ){
        glPushMatrix();
//		glTranslatef(NULO,NULO, z);
//		glRotatef(this->angulo, NULO, NULO, UNITARIO);
//		glScalef((this->altura-z)/this->altura,(this->altura-z)/this->altura,UNITARIO);
		for(unsigned int i=0;i<puntosDesde.size();i++) {
			puntosDesde[i].setX(puntosHasta[i].getX());
			puntosDesde[i].setY(puntosHasta[i].getY());
			puntosDesde[i].setZ(puntosHasta[i].getZ());
			puntosHasta[i].setX(puntosHasta[i].getX()*0.95);
			puntosHasta[i].setY(puntosHasta[i].getY()*0.95);
			puntosHasta[i].setZ(puntosHasta[i].getZ()+deltaZ);
		}
		pintor.pintarGajo(puntosDesde,puntosHasta);
	    glPopMatrix();
    }
}

std::vector<Coordenadas> Isla::generarCurvaNivel0(){
    CalculadorBspline bspline(26);
    std::vector<Coordenadas> puntos;
	puntos.push_back(Coordenadas(0.0f,9.0f,0.0f));
    puntos.push_back(Coordenadas(5.0f,10.0f,0.0f));
    puntos.push_back(Coordenadas(6.0f,9.0f,0.0f));
    puntos.push_back(Coordenadas(5.0f,5.0f,0.0f));
    puntos.push_back(Coordenadas(10.0f,6.0f,0.0f));
    puntos.push_back(Coordenadas(11.0f,4.0f,0.0f));
    puntos.push_back(Coordenadas(8.0f,0.0f,0.0f));
    puntos.push_back(Coordenadas(8.0f,-4.0f,0.0f));
    puntos.push_back(Coordenadas(12.0f,-5.0f,0.0f));
    puntos.push_back(Coordenadas(9.0f,-7.0f,0.0f));
    puntos.push_back(Coordenadas(6.0f,-5.0f,0.0f));
    puntos.push_back(Coordenadas(4.0f,-6.0f,0.0f));
    puntos.push_back(Coordenadas(0.0f,-9.0f,0.0f));
    puntos.push_back(Coordenadas(-5.0f,-9.0f,0.0f));
    puntos.push_back(Coordenadas(-6.0f,-5.0f,0.0f));
    puntos.push_back(Coordenadas(-9.0f,-5.0f,0.0f));
    puntos.push_back(Coordenadas(-11.0f,-5.0f,0.0f));
    puntos.push_back(Coordenadas(-9.0f,-3.0f,0.0f));
    puntos.push_back(Coordenadas(-9.0f,3.0f,0.0f));
    puntos.push_back(Coordenadas(-7.0f,4.0f,0.0f));
    puntos.push_back(Coordenadas(-8.0f,6.0f,0.0f));
    puntos.push_back(Coordenadas(-7.0f,8.0f,0.0f));
    puntos.push_back(Coordenadas(-6.0f,10.0f,0.0f));
    puntos.push_back(Coordenadas(0.0f,9.0f,0.0f));
    puntos.push_back(Coordenadas(5.0f,10.0f,0.0f));
    puntos.push_back(Coordenadas(6.0f,9.0f,0.0f));
    bspline.setControlPoints(puntos);
    return bspline.calcularPuntos();
}

std::vector<Coordenadas> Isla::generarCurvaNivel1(){
    CalculadorBspline bspline(26);
    std::vector<Coordenadas> puntos;
    puntos.push_back(Coordenadas(0.0f,7.0f,0.15f));
    puntos.push_back(Coordenadas(3.0f,8.0f,0.15f));
    puntos.push_back(Coordenadas(4.0f,7.0f,0.15f));
    puntos.push_back(Coordenadas(3.0f,3.0f,0.15f));
    puntos.push_back(Coordenadas(8.0f,4.0f,0.15f));
    puntos.push_back(Coordenadas(9.0f,2.0f,0.15f));
    puntos.push_back(Coordenadas(6.0f,0.0f,0.15f));
    puntos.push_back(Coordenadas(6.0f,-2.0f,0.15f));
    puntos.push_back(Coordenadas(10.0f,-3.0f,0.15f));
    puntos.push_back(Coordenadas(7.0f,-5.0f,0.15f));
    puntos.push_back(Coordenadas(4.0f,-3.0f,0.15f));
    puntos.push_back(Coordenadas(2.0f,-4.0f,0.15f));
    puntos.push_back(Coordenadas(0.0f,-7.0f,0.15f));
    puntos.push_back(Coordenadas(-3.0f,-7.0f,0.15f));
    puntos.push_back(Coordenadas(-4.0f,-3.0f,0.15f));
    puntos.push_back(Coordenadas(-7.0f,-3.0f,0.15f));
    puntos.push_back(Coordenadas(-9.0f,-3.0f,0.15f));
    puntos.push_back(Coordenadas(-7.0f,-1.0f,0.15f));
    puntos.push_back(Coordenadas(-7.0f,1.0f,0.15f));
    puntos.push_back(Coordenadas(-5.0f,2.0f,0.15f));
    puntos.push_back(Coordenadas(-6.0f,4.0f,0.15f));
    puntos.push_back(Coordenadas(-5.0f,6.0f,0.15f));
    puntos.push_back(Coordenadas(-4.0f,8.0f,0.15f));
    puntos.push_back(Coordenadas(0.0f,7.0f,0.15f));
    puntos.push_back(Coordenadas(3.0f,8.0f,0.15f));
    puntos.push_back(Coordenadas(4.0f,7.0f,0.15f));
    bspline.setControlPoints(puntos);
    return bspline.calcularPuntos();
}
