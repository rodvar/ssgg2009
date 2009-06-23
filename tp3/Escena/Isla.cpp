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

//		glTranslatef(NULO,NULO, z);
//		glRotatef(this->angulo, NULO, NULO, UNITARIO);
//		glScalef((this->altura-z)/this->altura,(this->altura-z)/this->altura,UNITARIO);
void Isla::dibujar(){
//    float precisionZ = 10.0f;
//    float deltaZ = this->altura/ precisionZ;
    PintorCurva pintor;
    std::vector<Coordenadas> puntosDesde = this->generarCurvaNivel0();
    std::vector<Coordenadas> puntosHasta = puntosDesde;

    glPushMatrix();
    glColor3f(0.8,0.72,0.62);
    for(float z = NULO; z <= 5; z++){
    	float angulo = rand()%8;
		for(unsigned int i=0;i<puntosDesde.size();i++) {
			puntosDesde[i].setX(puntosHasta[i].getX());
			puntosDesde[i].setY(puntosHasta[i].getY());
			puntosDesde[i].setZ(puntosHasta[i].getZ());
			escalarPunto(puntosHasta[i]);
			rotarPunto(puntosHasta[i], angulo);
			puntosHasta[i].setZ(puntosHasta[i].getZ()+z/10);
		}
		pintor.pintarGajo(puntosDesde,puntosHasta);
    }
    glBegin(GL_TRIANGLE_FAN);
		for(unsigned int i=0;i<puntosHasta.size();i++) {
			glVertex3f(puntosHasta[i].getX(),puntosHasta[i].getY(),puntosHasta[i].getZ());
		}
    glEnd();
    glPopMatrix();
}

void Isla::escalarPunto(Coordenadas& punto) {
	punto.setX(punto.getX()*0.95);
	punto.setY(punto.getY()*0.90);
}

void Isla::rotarPunto(Coordenadas& punto, float angulo) {
	float rad = Matematica::anguloRadianes(angulo);
	punto.setX(cos(rad)*punto.getX()-sin(rad)*punto.getY());
	punto.setY(sin(rad)*punto.getX()+cos(rad)*punto.getY());
}

std::vector<Coordenadas> Isla::generarCurvaNivel0(){
    CalculadorBspline bspline(26);
    std::vector<Coordenadas> puntos;
	puntos.push_back(Coordenadas(0.0f,8.0f,0.0f));
    puntos.push_back(Coordenadas(4.0f,9.0f,0.0f));
    puntos.push_back(Coordenadas(5.0f,8.0f,0.0f));
    puntos.push_back(Coordenadas(3.0f,4.0f,0.0f));
    puntos.push_back(Coordenadas(5.0f,5.0f,0.0f));
    puntos.push_back(Coordenadas(6.0f,3.0f,0.0f));
    puntos.push_back(Coordenadas(5.0f,0.0f,0.0f));
    puntos.push_back(Coordenadas(4.0f,-3.0f,0.0f));
    puntos.push_back(Coordenadas(7.0f,-4.0f,0.0f));
    puntos.push_back(Coordenadas(6.0f,-6.0f,0.0f));
    puntos.push_back(Coordenadas(5.0f,-8.0f,0.0f));
    puntos.push_back(Coordenadas(3.0f,-7.0f,0.0f));
    puntos.push_back(Coordenadas(0.0f,-8.0f,0.0f));
    puntos.push_back(Coordenadas(-4.0f,-8.0f,0.0f));
    puntos.push_back(Coordenadas(-5.0f,-4.0f,0.0f));
    puntos.push_back(Coordenadas(-5.0f,-4.0f,0.0f));
    puntos.push_back(Coordenadas(-6.0f,-4.0f,0.0f));
    puntos.push_back(Coordenadas(-4.0f,-2.0f,0.0f));
    puntos.push_back(Coordenadas(-5.0f,2.0f,0.0f));
    puntos.push_back(Coordenadas(-4.0f,3.0f,0.0f));
    puntos.push_back(Coordenadas(-6.0f,5.0f,0.0f));
    puntos.push_back(Coordenadas(-6.0f,7.0f,0.0f));
    puntos.push_back(Coordenadas(-5.0f,9.0f,0.0f));
    puntos.push_back(Coordenadas(0.0f,8.0f,0.0f));
    puntos.push_back(Coordenadas(4.0f,9.0f,0.0f));
    puntos.push_back(Coordenadas(5.0f,8.0f,0.0f));
    bspline.setControlPoints(puntos);
    return bspline.calcularPuntos();
}

//std::vector<Coordenadas> Isla::generarCurvaNivel1(){
//    CalculadorBspline bspline(26);
//    std::vector<Coordenadas> puntos;
//    puntos.push_back(Coordenadas(0.0f,7.0f,0.15f));
//    puntos.push_back(Coordenadas(3.0f,8.0f,0.15f));
//    puntos.push_back(Coordenadas(4.0f,7.0f,0.15f));
//    puntos.push_back(Coordenadas(3.0f,3.0f,0.15f));
//    puntos.push_back(Coordenadas(8.0f,4.0f,0.15f));
//    puntos.push_back(Coordenadas(9.0f,2.0f,0.15f));
//    puntos.push_back(Coordenadas(6.0f,0.0f,0.15f));
//    puntos.push_back(Coordenadas(6.0f,-2.0f,0.15f));
//    puntos.push_back(Coordenadas(10.0f,-3.0f,0.15f));
//    puntos.push_back(Coordenadas(7.0f,-5.0f,0.15f));
//    puntos.push_back(Coordenadas(4.0f,-3.0f,0.15f));
//    puntos.push_back(Coordenadas(2.0f,-4.0f,0.15f));
//    puntos.push_back(Coordenadas(0.0f,-7.0f,0.15f));
//    puntos.push_back(Coordenadas(-3.0f,-7.0f,0.15f));
//    puntos.push_back(Coordenadas(-4.0f,-3.0f,0.15f));
//    puntos.push_back(Coordenadas(-7.0f,-3.0f,0.15f));
//    puntos.push_back(Coordenadas(-9.0f,-3.0f,0.15f));
//    puntos.push_back(Coordenadas(-7.0f,-1.0f,0.15f));
//    puntos.push_back(Coordenadas(-7.0f,1.0f,0.15f));
//    puntos.push_back(Coordenadas(-5.0f,2.0f,0.15f));
//    puntos.push_back(Coordenadas(-6.0f,4.0f,0.15f));
//    puntos.push_back(Coordenadas(-5.0f,6.0f,0.15f));
//    puntos.push_back(Coordenadas(-4.0f,8.0f,0.15f));
//    puntos.push_back(Coordenadas(0.0f,7.0f,0.15f));
//    puntos.push_back(Coordenadas(3.0f,8.0f,0.15f));
//    puntos.push_back(Coordenadas(4.0f,7.0f,0.15f));
//    bspline.setControlPoints(puntos);
//    return bspline.calcularPuntos();
//}
