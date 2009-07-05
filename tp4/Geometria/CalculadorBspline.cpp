#include "CalculadorBspline.h"
/*----------------------------------------------------------------------------------*/
CalculadorBspline::CalculadorBspline(unsigned int nroCurvePoints):CalculadorCurva(nroCurvePoints)
{

}
/*----------------------------------------------------------------------------------*/
CalculadorBspline::CalculadorBspline(unsigned int nroCurvePoints,
	std::vector<Coordenadas>& pC) throw(std::runtime_error)
:CalculadorCurva(nroCurvePoints,pC)
{
	if(pC.size() < 4) {
		throw std::runtime_error("Error al construir BSpline. El vector de puntos de "
				"control debe tener al menos 4 elementos.") ;
	}
	else {
		this->loadCurvePointsVector() ;
	}
}
/*----------------------------------------------------------------------------------*/
CalculadorBspline::~CalculadorBspline()
{

}
/*----------------------------------------------------------------------------------*/
void CalculadorBspline::setControlPoints(const std::vector<Coordenadas> &control_points)
throw(std::runtime_error){
	if(control_points.size() < 4) {
		throw std::runtime_error("Error al asignar puntos de control a BSpline. El vector "
				"de puntos de control debe tener al menos 4 elementos.") ;
	}
	else {
		this->control_points = control_points ;
		this->loadCurvePointsVector() ;
	}
}
/*----------------------------------------------------------------------------------*/
std::vector<Coordenadas> CalculadorBspline::calcularPuntos() {

	return curvePoints ;
}
/*----------------------------------------------------------------------------------*/
void CalculadorBspline::loadCurvePointsVector() {
	/* reseteo los vectores de puntos de curva y árboles */
	curvePoints.clear() ;

	/* Defino array de cuatro puntos para ir cargando los temporales desde el vector
	 * de puntos de control, e incrementándolos.*/
	std::vector<Coordenadas> temporal ;
	temporal.resize(4) ;

	/* voy cargando de a cuatro puntos en el vector temporal, desde el vector
	 * de puntos de control, y hago el cálculo con esos cuatro */
	for(unsigned int cpindex=0 ; cpindex<(control_points.size()-3) ; ++cpindex  ){
		temporal[0] = control_points[cpindex] ;
		temporal[1] = control_points[cpindex+1] ;
		temporal[2] = control_points[cpindex+2] ;
		temporal[3] = control_points[cpindex+3] ;
		this->loadSegmentPoints(temporal,true) ; /* cargo puntos curva */
	}

}
/*----------------------------------------------------------------------------------*/
void CalculadorBspline::loadSegmentPoints(std::vector<Coordenadas>& temp,
		bool curve) {

	/* utilizo el parámetro de la cantidad de puntos(temporal) para mover el "u" */
	for(int i=0 ; i<numberOfCurvePoints ; ++i) {

		/* obtengo el "u" segun el valor de i */
		double u = (double)i / (numberOfCurvePoints-1) ;
		/* obtengo el valor invertido de "u" */
		double ut = 1 - u ;

		/* calculo las bases */
		double N0 = (ut*ut*ut) / 6.0 ;
		double N1 = (3*u*u*u - 6*u*u + 4) / 6.0 ;
		double N2 = (-3*u*u*u + 3*u*u + 3*u + 1) / 6.0 ;
		double N3 = (u*u*u) / 6.0 ;

		Coordenadas punto ;
		/* hago la sumatoria */
		punto.setX(N0 * temp[0].getX() + N1 * temp[1].getX()
								+ N2 * temp[2].getX() + N3 * temp[3].getX() );
		punto.setY(N0 * temp[0].getY() + N1 * temp[1].getY()
								+ N2 * temp[2].getY() + N3 * temp[3].getY() );
		punto.setZ(N0 * temp[0].getZ() + N1 * temp[1].getZ()
										+ N2 * temp[2].getZ() + N3 * temp[3].getZ() );

		curvePoints.push_back(punto) ;

	}

}
/*----------------------------------------------------------------------------------*/
