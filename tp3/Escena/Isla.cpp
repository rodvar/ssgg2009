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
    CalculadorBspline bspline(24);
    std::vector<Coordenadas> puntos;
    Coordenadas c1(0,9);   puntos.push_back(c1);
    Coordenadas c2(5,10);  puntos.push_back(c2);
    Coordenadas c3(6,9); puntos.push_back(c3);
    Coordenadas c4(5,5);  puntos.push_back(c4);
    Coordenadas c5(10,6);   puntos.push_back(c5);
    Coordenadas c6(11,4);  puntos.push_back(c6);
    Coordenadas c7(8,0); puntos.push_back(c7);
    Coordenadas c8(8,-4);  puntos.push_back(c8);
    Coordenadas c9(12,-5);   puntos.push_back(c9);
    Coordenadas c10(9,-7);  puntos.push_back(c10);
    Coordenadas c11(6,-5); puntos.push_back(c11);
    Coordenadas c12(4,-6);  puntos.push_back(c12);
    Coordenadas c13(0,-9);   puntos.push_back(c13);
    Coordenadas c14(-5,-9);  puntos.push_back(c14);
    Coordenadas c15(-6,-5); puntos.push_back(c15);
    Coordenadas c16(-9,5);  puntos.push_back(c16);
    Coordenadas c17(-11,-5);   puntos.push_back(c17);
    Coordenadas c18(-9,-3);  puntos.push_back(c18);
    Coordenadas c19(-9,3); puntos.push_back(c19);
    Coordenadas c20(-7,4);  puntos.push_back(c20);
    Coordenadas c21(-8,6);   puntos.push_back(c21);
    Coordenadas c22(-7,8);  puntos.push_back(c22);
    Coordenadas c23(-6,10); puntos.push_back(c23);
    Coordenadas c24(0,9);  puntos.push_back(c24);
    bspline.setControlPoints(puntos);
    return bspline.calcularPuntos();
}

std::vector<Coordenadas> Isla::generarCurvaNivel1(){
    CalculadorBspline bspline(24);
    std::vector<Coordenadas> puntos;
    Coordenadas c1(0,7);   puntos.push_back(c1);
    Coordenadas c2(3,8);  puntos.push_back(c2);
    Coordenadas c3(4,7); puntos.push_back(c3);
    Coordenadas c4(3,3);  puntos.push_back(c4);
    Coordenadas c5(8,4);   puntos.push_back(c5);
    Coordenadas c6(9,2);  puntos.push_back(c6);
    Coordenadas c7(6,0); puntos.push_back(c7);
    Coordenadas c8(6,-2);  puntos.push_back(c8);
    Coordenadas c9(10,-3);   puntos.push_back(c9);
    Coordenadas c10(7,-5);  puntos.push_back(c10);
    Coordenadas c11(4,-3); puntos.push_back(c11);
    Coordenadas c12(2,-4);  puntos.push_back(c12);
    Coordenadas c13(0,-7);   puntos.push_back(c13);
    Coordenadas c14(-3,-7);  puntos.push_back(c14);
    Coordenadas c15(-4,-3); puntos.push_back(c15);
    Coordenadas c16(-7,3);  puntos.push_back(c16);
    Coordenadas c17(-9,-3);   puntos.push_back(c17);
    Coordenadas c18(-7,-1);  puntos.push_back(c18);
    Coordenadas c19(-7,1); puntos.push_back(c19);
    Coordenadas c20(-5,2);  puntos.push_back(c20);
    Coordenadas c21(-6,4);   puntos.push_back(c21);
    Coordenadas c22(-5,6);  puntos.push_back(c22);
    Coordenadas c23(-4,8); puntos.push_back(c23);
    Coordenadas c24(0,7);  puntos.push_back(c24);
    bspline.setControlPoints(puntos);
    return bspline.calcularPuntos();
}
