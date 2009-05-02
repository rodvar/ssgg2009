#include "Motor.h"

void Motor::actualizar(){
    //this->pantalla->actualizar(this->datos);
    glutPostRedisplay();
}

void Motor::cambiarModo(){
    if (this->modo == 'D')
        this->modo = 'B';
    else
        this->modo = 'D';
    this->limpiarBufferDatos();
    //this->regenerarPantalla();
}

bool Motor::enRango(int x, int y){
    //return this->pantalla->getGrilla()->enRango(x,y);
    return false;
}

void Motor::limpiarBufferDatos(){
    list<FiguraGeometrica*>::iterator it=this->datos.begin() ;
    while(it != this->datos.end()){
        delete ((FiguraGeometrica*)*it);
        it++;
    }
    this->datos.clear();
}

void Motor::regenerarPantalla(){
    bool dobleColor = false;
    if (this->modo == BRESENHAM)
        dobleColor = true;
    //this->pantalla->regenerar(dobleColor);
}

float Motor::calcularIncertidumbrePje(float xReal, float distancia){
    float incertidumbre = distancia/xReal;
    return (float)((int)(incertidumbre * 100))/100 ;
}
