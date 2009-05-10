#include "Motor.h"
#include "Visualizacion/Pantalla.h"
#include "Interaccion/IU.h"

void Motor::actualizar(){
    list<Dibujable*> escena3d;
    list<FiguraGeometrica*> sendero2d;
    list<FiguraGeometrica*> hoja2d;


    // TOOO: Aca realiza la simulacion si corresponde, y siempre pasar lo que se tenga q dibujar
    // al actualizador de Pantalla
    Pantalla::getInstancia()->actualizar(escena3d, sendero2d, hoja2d);
    list<Dibujable*>::iterator it3d = escena3d.begin();
    while (it3d != escena3d.end()){
        delete *it3d;
        it3d++;
    }
    list<FiguraGeometrica*>::iterator it2dS = sendero2d.begin();
    while (it2dS != sendero2d.end()){
        delete *it2dS;
        it2dS++;
    }
    list<FiguraGeometrica*>::iterator it2dI = hoja2d.begin();
    while (it2dI != hoja2d.end()){
        delete *it2dI;
        it2dI++;
    }


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
