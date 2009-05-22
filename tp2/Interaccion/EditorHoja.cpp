#include "EditorHoja.h"
#include "../Geometria/Segmento.h"

EditorHoja::EditorHoja(float ancho, float alto):Editor(ancho,alto)
{
    Coordenadas* coordenadas = new Coordenadas(ancho*PJE_ANCHO_H + this->marco.getBase()/2,alto*PJE_ALTO_H - this->marco.getAltura()/2);
    this->marco.setCentro(*coordenadas);
    delete coordenadas;
}

EditorHoja::~EditorHoja()
{
    //dtor
}

void EditorHoja::procesarSeleccion(Coordenadas coordenadas){
    //TODO: Implementame!
}

void EditorHoja::terminar(){
    unsigned int cantidadElementos = this->puntosEdicion.size();
    if ( cantidadElementos == 4)
        cantidadElementos = 4;
    for (unsigned short int i = 0; i < cantidadElementos; i++)
        this->puntosEdicion.push_back(((Coordenadas*)*this->puntosEdicion.begin())->copia());
}

void EditorHoja::redimensionar(const float ancho, const float alto){
    Coordenadas coordenadas(ancho*PJE_ANCHO_H + this->marco.getBase()/2,alto*PJE_ALTO_H - this->marco.getAltura()/2);
    this->marco.setCentro(coordenadas);
    this->marco.setBase(ancho*PJE_DIMENSIONES);
    this->marco.setAltura(alto*PJE_DIMENSIONES);
}

void EditorHoja::dibujar(){
    Segmento* segmento;
    list<Coordenadas*>::iterator it = this->puntosEdicion.begin();
    Coordenadas* punto;
    Coordenadas* mapeadoD;
    Coordenadas* mapeadoH;
    Color gris(0.5,0.5,0.5);
    if(this->puntosEdicion.size()>3) {
		Curva curva(this->puntosEdicion);
		curva.dibujarBezier();
	}
	punto = (Coordenadas*) *it;
    it++;
    if (this->puntosEdicion.size() == 1) {
        mapeadoD = this->mapeo(punto->getX(),punto->getY());
        mapeadoD->setColorBorde(gris);
        mapeadoD->setColorRelleno(gris);
        mapeadoD->dibujar();
    }
    while ( it != this->puntosEdicion.end()){
        mapeadoD = this->mapeo(punto->getX(),punto->getY());
        mapeadoH = this->mapeo(((Coordenadas*)*it)->getX(),((Coordenadas*)*it)->getY());
        mapeadoD->setColorBorde(gris);
        mapeadoD->setColorRelleno(gris);
        mapeadoH->setColorBorde(gris);
        mapeadoH->setColorRelleno(gris);
        mapeadoD->dibujar();
        mapeadoH->dibujar();
        segmento = new Segmento(mapeadoD,mapeadoH);
        segmento->dibujarPunteado();
        delete segmento;
        punto = (Coordenadas*) *it;
        punto->dibujar();
        it++;
    }
}
