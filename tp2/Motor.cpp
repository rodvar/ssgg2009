#include "Motor.h"
#include "Visualizacion/Pantalla.h"
#include "Interaccion/IU.h"
#include "Escenario/Rama.h"

void Motor::actualizar(){
    list<Coordenadas*> puntosControlSendero = IU::getInstancia()->getEditorSenderoPlantacion()->getPuntosEdicion();
    list<Coordenadas*> puntosControlHoja = IU::getInstancia()->getEditorHoja()->getPuntosEdicion();
    list<Dibujable*> sendero2d;
    list<Dibujable*> hoja2d;

    sendero2d.insert(sendero2d.begin(),puntosControlSendero.begin(),puntosControlSendero.end());
    hoja2d.insert(hoja2d.begin(),puntosControlHoja.begin(),puntosControlHoja.end());

    Pantalla::getInstancia()->actualizar(this->datos, sendero2d, hoja2d);
    //this->limpiarBufferDatos();
}

void Motor::simularArboleda(){
    this->limpiarBufferDatos();
    Curva* curva = new Curva(IU::getInstancia()->getEditorHoja()->getPuntosEdicion());
    // TOOO: Aca realiza la simulacion si corresponde
    Rama* rama = new Rama(curva, 0, 0);
    this->datos.push_back(rama);
}

void Motor::limpiarBufferDatos(){
    list<Dibujable*>::iterator it=this->datos.begin() ;
    while(it != this->datos.end()){
        delete *it;
        it++;
    }
    this->datos.clear();
}
