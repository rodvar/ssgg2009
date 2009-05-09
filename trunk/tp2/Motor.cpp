#include "Motor.h"
#include "Visualizacion/Pantalla.h"

void Motor::actualizar(){
    Pantalla::getInstancia()->actualizar(this->datos);
    glutPostRedisplay();
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
    //this->pantalla->regenerar(dobleColor);
}

float Motor::calcularIncertidumbrePje(float xReal, float distancia){
    float incertidumbre = distancia/xReal;
    return (float)((int)(incertidumbre * 100))/100 ;
}

bool Motor::enRango(int x, int y){
    return true;
}
