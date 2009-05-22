#include "Motor.h"
#include "Visualizacion/Pantalla.h"
#include "Interaccion/IU.h"
#include "Escenario/Arbol.h"

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

    /* TODO: Aca agregar al buffer
       1- El sendero de plantacion (curva)
       2- Los arboles que haya que plantar
    */
    this->datos.push_back(IU::getInstancia()->getEditorSenderoPlantacion()->generarCurva());

    Coordenadas* c;
    list<Coordenadas*>::iterator it=this->semillas.begin() ;
    while(it != this->semillas.end()){
    	c = (Coordenadas*)*it;
		Arbol* arbol = new Arbol(IU::getInstancia()->getEditorHoja()->generarCurva(),
				this->nivelesArbol, this->mapeo(c->getX(),c->getY()));
		this->datos.push_back(arbol);
    	it++;
    }

    list<Coordenadas*>::iterator it2=this->semillas.begin() ;
    while(it2 != this->semillas.end()){
        delete *it2;
        it2++;
    }
    this->semillas.clear();
//    Arbol* arbol = new Arbol(IU::getInstancia()->getEditorHoja()->generarCurva(), this->nivelesArbol,new Coordenadas(1,1));
//    this->datos.push_back(arbol);
}

void Motor::limpiarBufferDatos(){
    list<Dibujable*>::iterator it=this->datos.begin() ;
    while(it != this->datos.end()){
        delete *it;
        it++;
    }
    this->datos.clear();

}

Coordenadas* Motor::mapeo(float x, float y) {
	return new Coordenadas(x*10,y*10);
}
