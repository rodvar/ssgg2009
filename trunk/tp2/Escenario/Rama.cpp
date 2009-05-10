#include "Rama.h"

Rama::Rama(Hoja hoja, const short int orientacion)
{
    for (int i = 0; i < HOJAS_DEFECTO; i++)
        this->hojas[i] = hoja;
    this->color.setRojo(0.6f);
    this->color.setVerde(0.25f);
    this->qobj = gluNewQuadric(); // crea un objeto cuadrático
    this->setOrientacionHojas(orientacion);
}

Rama::~Rama()
{
    gluDeleteQuadric(qobj);
}

void Rama::setOrientacionHojas(const short int orientacion){
    ((orientacion >= -45) && (orientacion <= 45))? this->orientacionHojas = orientacion
        : this->orientacionHojas = 0;
}

void Rama::dibujar(){
    // Cilindro unitario
    glColor3f(this->color.getRojo(), this->color.getVerde(), this->color.getAzul());
    gluQuadricDrawStyle(this->qobj, GLU_FILL); //estilo relleno
    gluCylinder(qobj, 1, 1, 1, 100, 100);

    // TODO: Dibujar Hojas

}
