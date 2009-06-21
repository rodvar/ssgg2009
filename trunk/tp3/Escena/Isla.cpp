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
            glTranslatef(NULO,NULO, z);
            glRotatef(this->angulo, NULO, NULO, UNITARIO);
            glScalef((this->altura-z)/this->altura,(this->altura-z)/this->altura,UNITARIO);
            // IMPORTANTE: puntosDesde y puntosHasta tienen q tener la misma cantidad de puntos!
			pintor.pintarGajo(puntosDesde,puntosHasta);
        glPopMatrix();
    }
}

std::vector<Coordenadas> Isla::generarCurvaNivel0(){
    CalculadorBspline bspline(26);
    std::vector<Coordenadas> puntos;
	puntos.push_back(Coordenadas(0,9));
    puntos.push_back(Coordenadas(5,10));
    puntos.push_back(Coordenadas(6,9));
    puntos.push_back(Coordenadas(5,5));
    puntos.push_back(Coordenadas(10,6));
    puntos.push_back(Coordenadas(11,4));
    puntos.push_back(Coordenadas(8,0));
    puntos.push_back(Coordenadas(8,-4));
    puntos.push_back(Coordenadas(12,-5));
    puntos.push_back(Coordenadas(9,-7));
    puntos.push_back(Coordenadas(6,-5));
    puntos.push_back(Coordenadas(4,-6));
    puntos.push_back(Coordenadas(0,-9));
    puntos.push_back(Coordenadas(-5,-9));
    puntos.push_back(Coordenadas(-6,-5));
    puntos.push_back(Coordenadas(-9,-5));
    puntos.push_back(Coordenadas(-11,-5));
    puntos.push_back(Coordenadas(-9,-3));
    puntos.push_back(Coordenadas(-9,3));
    puntos.push_back(Coordenadas(-7,4));
    puntos.push_back(Coordenadas(-8,6));
    puntos.push_back(Coordenadas(-7,8));
    puntos.push_back(Coordenadas(-6,10));
    puntos.push_back(Coordenadas(0,9));
    puntos.push_back(Coordenadas(5,10));
    puntos.push_back(Coordenadas(6,9));
//    puntos.push_back(Coordenadas(5,5));
//    puntos.push_back(Coordenadas(10,6));
    bspline.setControlPoints(puntos);
    return bspline.calcularPuntos();
}

std::vector<Coordenadas> Isla::generarCurvaNivel1(){
    CalculadorBspline bspline(26);
    std::vector<Coordenadas> puntos;
    puntos.push_back(Coordenadas(0,7));
    puntos.push_back(Coordenadas(3,8));
    puntos.push_back(Coordenadas(4,7));
    puntos.push_back(Coordenadas(3,3));
    puntos.push_back(Coordenadas(8,4));
    puntos.push_back(Coordenadas(9,2));
    puntos.push_back(Coordenadas(6,0));
    puntos.push_back(Coordenadas(6,-2));
    puntos.push_back(Coordenadas(10,-3));
    puntos.push_back(Coordenadas(7,-5));
    puntos.push_back(Coordenadas(4,-3));
    puntos.push_back(Coordenadas(2,-4));
    puntos.push_back(Coordenadas(0,-7));
    puntos.push_back(Coordenadas(-3,-7));
    puntos.push_back(Coordenadas(-4,-3));
    puntos.push_back(Coordenadas(-7,-3));
    puntos.push_back(Coordenadas(-9,-3));
    puntos.push_back(Coordenadas(-7,-1));
    puntos.push_back(Coordenadas(-7,1));
    puntos.push_back(Coordenadas(-5,2));
    puntos.push_back(Coordenadas(-6,4));
    puntos.push_back(Coordenadas(-5,6));
    puntos.push_back(Coordenadas(-4,8));
    puntos.push_back(Coordenadas(0,7));
    puntos.push_back(Coordenadas(3,8));
    puntos.push_back(Coordenadas(4,7));
//    puntos.push_back(Coordenadas(3,3));
//    puntos.push_back(Coordenadas(8,4));
    bspline.setControlPoints(puntos);
    return bspline.calcularPuntos();
}
