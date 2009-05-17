#include "Motor.h"
#include "Visualizacion/Pantalla.h"
#include "Interaccion/IU.h"

void Motor::actualizar(){
    list<Coordenadas*> listaCoordSendero = IU::getInstancia()->getEditorSenderoPlantacion()->getPuntosEdicion();
    list<Coordenadas*> listaCoordHoja = IU::getInstancia()->getEditorHoja()->getPuntosEdicion();
    list<Dibujable*> sendero2d;
    list<Dibujable*> hoja2d;

    sendero2d.insert(sendero2d.begin(),listaCoordSendero.begin(),listaCoordSendero.end());
    hoja2d.insert(hoja2d.begin(),listaCoordHoja.begin(),listaCoordHoja.end());

    // TOOO: Aca realiza la simulacion si corresponde, y siempre pasar lo que se tenga q dibujar
    // al actualizador de Pantalla

    Pantalla::getInstancia()->actualizar(datos, sendero2d, hoja2d);
    this->limpiarBufferDatos();
}

void Motor::limpiarBufferDatos(){
    list<Dibujable*>::iterator it=this->datos.begin() ;
    while(it != this->datos.end()){
        delete *it;
        it++;
    }
    this->datos.clear();
}

bool Motor::enRango(int x, int y){
    return true;
}
