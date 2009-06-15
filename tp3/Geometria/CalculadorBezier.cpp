#include "CalculadorBezier.h"
#include "Matematica.h"
//#include <GL/glut.h>

/*----------------------------------------------------------------------------------*/
CalculadorBezier::CalculadorBezier(unsigned int numberOfCurvepuntos)
:CalculadorCurva(numberOfCurvepuntos)
{
}
/*----------------------------------------------------------------------------------*/
CalculadorBezier::~CalculadorBezier()
{
}
/*----------------------------------------------------------------------------------*/
std::vector<Coordenadas> CalculadorBezier::calcularPuntos()
{
	/* vector para almacenar el resultado, se le pasa a loadCurvepuntos por referencia
	 * para ir añadiendo los puntos calculados */
    std::vector<Coordenadas> curvepuntos;
    curvepuntos.clear() ;
    /* vector temporal de 4 puntos  de control utilizado para aplicar bezier en loadCurvepuntos */
    std::vector<Coordenadas> temp ;
    temp.resize(4) ;

    /* voy incrementando de a 3 puntos */
    for(unsigned int i=0 ; i<this->control_points.size()-1 ; i+=3) {
    	/* importante: el grado se calcula segun el size del vector temp (siempre es 4) */
    	/* verifico que existan los puntos por delante */
    	if( (i+3) < this->control_points.size() ) {
    		temp[0] = this->control_points[i] ;
    		temp[1] = this->control_points[i+1] ;
    		temp[2] = this->control_points[i+2] ;
    		temp[3] = this->control_points[i+3] ;
    		/* setearlo segun la cantidad de puntos */
    		this->loadCurvePoints(curvepuntos,temp) ;
    	}

    }

    return curvepuntos;
}
/*----------------------------------------------------------------------------------*/
void CalculadorBezier::setPuntosControl(const std::vector<Coordenadas> &control_puntos)
        throw(std::runtime_error) {
	if(control_puntos.size() < 4) {
		throw std::runtime_error("Error al asignar puntos de control a Bezier. El vector "
						"de puntos de control debe tener al menos 4 elementos.") ;
	}
	else {
		this->control_points = control_puntos ;
	}
}

/*----------------------------------------------------------------------------------*/
void CalculadorBezier::computeCoefficients(int n, int *c)
{
    for (int k = 0;  k <= n;  k++)
        /* Se calcula n!/(k!(n-k)!). */
        c[k] = Matematica::factorial(n)/(Matematica::factorial(k)*Matematica::factorial(n-k));
}
/*----------------------------------------------------------------------------------*/
void CalculadorBezier::computePoint(float u, Coordenadas *punto, int *c,
		std::vector<Coordenadas> temp)
{
    unsigned int k;
    int n = temp.size() - 1;
    float blend;

    punto->setX(0.0f);
    punto->setY(0.0f);
    punto->setZ(0.0f);

    /* sumatoria de bezier */
    for (k = 0; k < temp.size(); k++)
    {
        blend = c[k] * pow(u,k) * pow(1-u,n-k);
        punto->setX(punto->getX() + temp[k].getX() * blend);
        punto->setY(punto->getY() + temp[k].getY() * blend);
        punto->setZ(punto->getZ() + temp[k].getZ() * blend);
    }
}
/*----------------------------------------------------------------------------------*/
void CalculadorBezier::loadCurvePoints(std::vector<Coordenadas>& curveP,
		const std::vector<Coordenadas>& controlP) {

	Coordenadas curvepunto;
	float u;
	int *coef, k;

	/* Se reserva memoria para los coeficientes de las bases de Berstein. */
	coef = new int [controlP.size()];

	/* Se calculan los coeficientes de las bases de Berstein. */
	computeCoefficients (controlP.size()-1, coef);

	/* Se calculan algunos puntos de la curva. */
	for (k = 0;  k <= numberOfCurvePoints;  k++)
	{
		u = (float) k / (float) numberOfCurvePoints;
		computePoint (u, &curvepunto, coef,controlP);
		curveP.push_back(curvepunto); /* se van añadiendo los puntos a la curva resultante */
	}

	delete[] coef;

}
