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

bool Motor::enRango(int x, int y){
    return true;
}
