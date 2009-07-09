#include "Matematica.h"

void Matematica::escalarPunto(Coordenadas &punto, float ex, float ey, float ez){
    punto.setX(ex*punto.getX());
    punto.setY(ey*punto.getY());
    punto.setZ(ez*punto.getZ());
}

Coordenadas Matematica::calcularNormalMedia(Coordenadas dir1, Coordenadas dir2){
    Coordenadas retorno = dir1+dir2;
    retorno.setX(retorno.getX()/2);
    retorno.setY(retorno.getY()/2);
    retorno.setZ(retorno.getZ()/2);
    normalizar(retorno);
    return retorno;
}

Coordenadas Matematica::calcularNormal(float anguloAlfa, float anguloFi){
    float alfa = anguloRadianes(anguloAlfa);
    float fi = anguloRadianes(anguloFi);
    Coordenadas normal(cos(alfa), sin(alfa), cos(fi));
    normalizar(normal);
    return normal;
}

Coordenadas Matematica::calcularNormal(Coordenadas direccion, float deltaAlfaXY){
    Coordenadas dirRotada = rotar(direccion,deltaAlfaXY);
    Coordenadas resultante = dirRotada + direccion;
    normalizar(resultante);
    return resultante;
}

Coordenadas Matematica::calcularNormal(Coordenadas a, Coordenadas b){
    Coordenadas n = productoVectorial(a,b);
    Coordenadas c = b - a;
    c = productoVectorial(c,n);
    normalizar(c);
    return c;
}

Coordenadas Matematica::calcularNormalReferencia(Coordenadas a, Coordenadas referencia){
    Coordenadas normal = a - referencia;
    normalizar(normal);
    return normal;
}

Coordenadas Matematica::productoVectorial(Coordenadas a, Coordenadas b){
    float x = a.getY() * b.getZ() - a.getZ() * b.getY();
    float y = a.getZ() * b.getX() - a.getX() * b.getZ();
    float z = a.getX() * b.getY() - a.getY() * b.getX();
    return Coordenadas(x,y,z);
}

Coordenadas Matematica::rotar(Coordenadas direccion, float deltaAlfaXY){
    float deltaRad = Matematica::anguloRadianes(deltaAlfaXY);
    float radio = calcularNorma(direccion);
    return Coordenadas(radio*(float)cos(deltaRad),radio*(float)sin(deltaRad), radio*direccion.getZ());
}

Coordenadas Matematica::rotar(Coordenadas direccion, float alfa,float fi){
    float radio = calcularNorma(direccion);
    alfa = anguloRadianes(alfa);
    fi = anguloRadianes(fi);
    return Coordenadas(radio*cos(alfa)*sin(fi), radio*sin(alfa)*sin(fi), radio*cos(fi));
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

