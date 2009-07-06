#include "PintorCurva.h"
#include "../Geometria/Matematica.h"

PintorCurva::PintorCurva()
{
}

PintorCurva::~PintorCurva()
{
}

void PintorCurva::pintar(std::vector<Coordenadas> &curvePoints)
{
    /* Se unen los puntos calculados con segmentos de recta. */
    glBegin(GL_LINE_STRIP);
        for(unsigned int i=0; i<curvePoints.size(); i++)
            glVertex3f(curvePoints[i].getX(), curvePoints[i].getY(), curvePoints[i].getZ());
    glEnd();
}

void PintorCurva::pintarSuperficie(std::vector<Coordenadas> &puntos, Coordenadas referencia){
	Coordenadas normal;
	glBegin(GL_TRIANGLE_FAN);
		normal = Matematica::calcularNormalReferencia(puntos[0],referencia);//Matematica::calcularNormal(puntosA[i], puntosB[i]);//Matematica::calcularNormal(suma,-angulo);
		glNormal3f(normal.getX(),normal.getY(),normal.getZ());
        glVertex3f(NULO,NULO,puntos[0].getZ());
		for(unsigned int i=0;i<puntos.size();i++) {
			normal = Matematica::calcularNormalReferencia(puntos[i],referencia);//Matematica::calcularNormal(puntosA[i], puntosB[i]);//Matematica::calcularNormal(suma,-angulo);
			glNormal3f(normal.getX(),normal.getY(),normal.getZ());
			glVertex3f(puntos[i].getX(),puntos[i].getY(),puntos[i].getZ());
		}
    glEnd();
}

void PintorCurva::pintarGajo(std::vector<Coordenadas> &puntosA, std::vector<Coordenadas> &puntosB, Coordenadas referencia){
    Coordenadas normal;
    Coordenadas suma;
    double angulo;
    if (puntosA.size() == puntosB.size()){
        glBegin(GL_QUAD_STRIP);
		for(unsigned int i=0; i<puntosA.size(); i++){
			suma = puntosA[i] + puntosB[i];
			angulo = puntosA[i].angulo(puntosB[i]);

			normal = Matematica::calcularNormalReferencia(puntosA[i],referencia);//Matematica::calcularNormal(puntosA[i], puntosB[i]);//Matematica::calcularNormal(suma,-angulo);
			glNormal3f(normal.getX(),normal.getY(),normal.getZ());
			glVertex3f(puntosA[i].getX(), puntosA[i].getY(), puntosA[i].getZ());
			normal = Matematica::calcularNormalReferencia(puntosB[i],referencia);//Matematica::calcularNormal(puntosA[i], puntosB[i]);//Matematica::calcularNormal(suma,-angulo);
			glNormal3f(normal.getX(),normal.getY(),normal.getZ());
			glVertex3f(puntosB[i].getX(), puntosB[i].getY(), puntosB[i].getZ());
		}
        glEnd();
    }
}

void PintorCurva::pintarPuntosControl(std::vector<Coordenadas>& cPoints, double radius, bool bezierCP)
{
	/* Se unen los puntos de control mediante una linea punteada */
	glLineStipple(2,0xAAAA) ;
	glEnable(GL_LINE_STIPPLE) ;
		glBegin(GL_LINE_STRIP) ;
			for(unsigned int i=0 ; i<cPoints.size() ; ++i) {
			    glVertex3f(cPoints[i].getX(), cPoints[i].getY(), cPoints[i].getZ());
			}
		glEnd() ;
	glDisable(GL_LINE_STIPPLE) ;

	/* se muestran los puntos de control mediante círculos */
	for(unsigned int i=0 ; i<cPoints.size() ; ++i) {
		this->dibujarCirculoRelleno(cPoints[i].getX(),cPoints[i].getY(),radius) ;
	}
}

void PintorCurva::dibujarCirculoRelleno(double x,double y,double radius)
{
	const double degInRadian = 57.29577957795135 ;

	glEnable(GL_BLEND);
	double y1=y;
	double x1=x;
	glBegin(GL_TRIANGLES);
	for(int i=0;i<=360;i++)
	{
		double angle=(float)(((double)i)/degInRadian);
		double x2=x+(radius*(float)sin((double)angle));
		double y2=y+(radius*(float)cos((double)angle));
		glVertex2d(x,y);
		glVertex2d(x1,y1);
		glVertex2d(x2,y2);
		y1=y2;
		x1=x2;
	}
	glEnd();
	glDisable(GL_BLEND);
}
