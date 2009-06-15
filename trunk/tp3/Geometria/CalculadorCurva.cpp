#include "CalculadorCurva.h"
/*----------------------------------------------------------------------------------*/
CalculadorCurva::CalculadorCurva(int numberOfCurvePoints)
:numberOfCurvePoints(numberOfCurvePoints)
{
}
/*----------------------------------------------------------------------------------*/
CalculadorCurva::CalculadorCurva(int numberOfCurvePoints,
		std::vector<Coordenadas>& pC)
:numberOfCurvePoints(numberOfCurvePoints),control_points(pC)
{

}
/*----------------------------------------------------------------------------------*/
CalculadorCurva::~CalculadorCurva()
{
}
/*----------------------------------------------------------------------------------*/
void CalculadorCurva::setNumberOfCurvePoints(int numberOfCurvePoints)
{
    this->numberOfCurvePoints = numberOfCurvePoints;
}
/*----------------------------------------------------------------------------------*/
int CalculadorCurva::getNumberOfCurvePoints() const
{
    return this->numberOfCurvePoints;
}
/*----------------------------------------------------------------------------------*/
void CalculadorCurva::setControlPoints(std::vector<Coordenadas> control_points)
{
    this->control_points = control_points;
}
/*----------------------------------------------------------------------------------*/
std::vector<Coordenadas> CalculadorCurva::getControlPoints() const
{
    return this->control_points;
}
