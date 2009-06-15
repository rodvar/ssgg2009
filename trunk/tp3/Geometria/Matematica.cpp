#include "Matematica.h"

Matematica::Matematica()
{
    //ctor
}

Matematica::~Matematica()
{
    //dtor
}

Coordenadas Matematica::calcularNormal(float anguloAlfa, float anguloFi){
    anguloRadianes(anguloAlfa);
    anguloRadianes(anguloFi);
    Coordenadas normal(cos(anguloAlfa), sin(anguloAlfa), cos(anguloFi));
    normalizar(normal);
    return normal;
}

Coordenadas Matematica::calcularNormal(Coordenadas direccion, float deltaAlfaXY){
    Coordenadas dirRotada = rotar(direccion,deltaAlfaXY);
    Coordenadas resultante = dirRotada + direccion;
    normalizar(resultante);
    return resultante;
}

Coordenadas Matematica::rotar(Coordenadas direccion, float deltaAlfaXY){
    float deltaRad = Matematica::anguloRadianes(deltaAlfaXY);
    float radio = calcularNorma(direccion);
    Coordenadas dirRotada(radio*(float)cos(deltaRad),radio*(float)sin(deltaRad), radio*direccion.getZ());
    return dirRotada;
}

float Matematica::anguloRadianes(const float anguloGrados){
    return (anguloGrados/180.0f)*PI;
}

float Matematica::anguloGrados(const float anguloRadianes){
    return (anguloRadianes/PI)*180.0f;
}

float Matematica::calcularNorma(Coordenadas c){
    return sqrt(c.getX()*c.getX() + c.getY()*c.getY() + c.getZ()*c.getZ());
}

void Matematica::normalizar(Coordenadas& c){
    const float norma = calcularNorma(c);
    if (norma > 0.0f){
        c.setX(c.getX()/norma);
        c.setY(c.getY()/norma);
        c.setZ(c.getZ()/norma);
    }
}

void Matematica::discretizarCircunferencia(Coordenadas* vector, const float radio, const float paso, const float z){
    Coordenadas punto;
    unsigned short int i = 0;
    for(float alfa = 0.0f; alfa < DOSPI; alfa += paso){
        vector[i].setX((float)(radio * cos(alfa)));
        vector[i].setY((float)(radio * sin(alfa)));
        vector[i].setZ(z);
        i++;
    }
}

unsigned int Matematica::factorial(unsigned int n){
    if(n==0)
        return 1;
    else
        return n*factorial(n-1);
}

