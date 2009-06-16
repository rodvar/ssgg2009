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
    CalculadorBspline bspline(10);
    std::vector<Coordenadas> puntos;
    //TODO Nico: cargar los puntos de control y fijarse porque no funciona calcularPuntos
    puntos = bspline.calcularPuntos();
    return puntos;
}

std::vector<Coordenadas> Isla::generarCurvaNivel1(){
    CalculadorBspline bspline(10);
    std::vector<Coordenadas> puntos;
    //TODO Nico: cargar los puntos de control y fijarse porque no funciona calcularPuntos
    puntos = bspline.calcularPuntos();
    return puntos;
}
