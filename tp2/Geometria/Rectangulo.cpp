#include "Rectangulo.h"
#include "Segmento.h"
#include "../Visualizacion/Scanline.h"

Rectangulo::Rectangulo(float base, float altura, Coordenadas* centro)
{
    this->base = base;
    this->altura = altura;
    this->centro = centro;
    this->rellenoParcialInferior = false;
}
Rectangulo::Rectangulo(){
    this->base = 0;
    this->altura = 0;
    this->centro = NULL;
    this->rellenoParcialInferior = false;
}

Rectangulo::~Rectangulo()
{
	if(this->centro!=NULL) {
		delete this->centro;
	}
}

Coordenadas* Rectangulo::getVerticeNO(){
    int x = this->centro->getX() - floor(this->base/2);
    int y = this->centro->getY() - floor(this->altura/2);
    return new Coordenadas(x,y);
}

Coordenadas* Rectangulo::getVerticeNE(){
    int x = this->centro->getX() + floor(this->base/2);
    int y = this->centro->getY() - floor(this->altura/2);
    return new Coordenadas(x,y);
}

Coordenadas* Rectangulo::getVerticeSO(){
    int x = this->centro->getX() - floor(this->base/2);
    int y = this->centro->getY() + floor(this->altura/2);
    return new Coordenadas(x,y);
}

Coordenadas* Rectangulo::getVerticeSE(){
    int x = this->centro->getX() + floor(this->base/2);
    int y = this->centro->getY() + floor(this->altura/2);
    return new Coordenadas(x,y);
}

void Rectangulo::setRellenoParcial(){
    this->rellenoParcialInferior = true;
}

void Rectangulo::setRellenoTotal(){
    this->rellenoParcialInferior = false;
}

void Rectangulo::setCentro(Coordenadas centro) {
    if (this->centro)
        delete this->centro;
    this->centro = new Coordenadas(centro.getX(), centro.getY());
}

void Rectangulo::dibujar(){
    glColor3f(this->borde.getRojo(), this->borde.getVerde(), this->borde.getAzul());
    Segmento* baseSur = new Segmento(this->getVerticeSO(), this->getVerticeSE());
    Segmento* baseNorte = new Segmento(this->getVerticeNE(), this->getVerticeNO());
    Segmento* alturaOeste = new Segmento(this->getVerticeNO(), this->getVerticeSO());
    Segmento* alturaEste = new Segmento(this->getVerticeSE(), this->getVerticeNE());
    baseSur->setColorBorde(this->borde);
    baseNorte->setColorBorde(this->borde);
    alturaEste->setColorBorde(this->borde);
    alturaOeste->setColorBorde(this->borde);
    baseSur->dibujar();
    alturaEste->dibujar();
    baseNorte->dibujar();
    alturaOeste->dibujar();
    delete baseSur;
    delete baseNorte;
    delete alturaEste;
    delete alturaOeste;
    this->rellenar();
}

void Rectangulo::dibujarPunteado() {
    glColor3f(this->borde.getRojo(), this->borde.getVerde(), this->borde.getAzul());
    Segmento* baseSur = new Segmento(this->getVerticeSO(), this->getVerticeSE());
    Segmento* baseNorte = new Segmento(this->getVerticeNE(), this->getVerticeNO());
    Segmento* alturaOeste = new Segmento(this->getVerticeNO(), this->getVerticeSO());
    Segmento* alturaEste = new Segmento(this->getVerticeSE(), this->getVerticeNE());
    baseSur->setColorBorde(this->borde);
    baseNorte->setColorBorde(this->borde);
    alturaEste->setColorBorde(this->borde);
    alturaOeste->setColorBorde(this->borde);
    baseSur->dibujarPunteado();
    alturaEste->dibujarPunteado();
    baseNorte->dibujarPunteado();
    alturaOeste->dibujarPunteado();
    delete baseSur;
    delete baseNorte;
    delete alturaEste;
    delete alturaOeste;
    this->rellenar();
}

void Rectangulo::rellenar() {
	glBegin(GL_POINTS);

    if (this->esRellenable){
        Scanline scanline;
        dcPt *PolyVertices;
        Coordenadas* verticeSO = this->getVerticeSO();
        Coordenadas* verticeNO = this->getVerticeNO();
        Coordenadas* verticeNE = this->getVerticeNE();
        Coordenadas* verticeSE = this->getVerticeSE();
        int cnt=3;
        glColor3f(this->relleno.getRojo(), this->relleno.getVerde(), this->relleno.getAzul());

        if(!this->rellenoParcialInferior) { // si relleno total
            cnt++;
            PolyVertices = (dcPt *)calloc(cnt, sizeof(dcPt));
            PolyVertices[0].x = verticeSO->getX()+1; PolyVertices[0].y = verticeSO->getY()-1;
            PolyVertices[1].x = verticeNO->getX()+1; PolyVertices[1].y = verticeNO->getY()+1;
            PolyVertices[2].x = verticeNE->getX()-1; PolyVertices[2].y = verticeNE->getY()+1;
            PolyVertices[3].x = verticeSE->getX()-1; PolyVertices[3].y = verticeSE->getY()-1;
            scanline.scanFill(cnt,PolyVertices);
            free(PolyVertices);
        }
        else{
            PolyVertices = (dcPt *)calloc(cnt, sizeof(dcPt));
            PolyVertices[0].x = verticeNE->getX()-1; PolyVertices[0].y = verticeNE->getY()+1;
            PolyVertices[1].x = verticeSO->getX()+1; PolyVertices[1].y = verticeSO->getY()-1;
            PolyVertices[2].x = verticeSE->getX()-1; PolyVertices[2].y = verticeSE->getY()-1;
            scanline.scanFill(cnt,PolyVertices);
            free(PolyVertices);
        }
		delete verticeNE;
		delete verticeNO;
		delete verticeSO;
		delete verticeSE;

    }

    glEnd();
}

bool Rectangulo::contiene(int x, int y){
    Coordenadas* so = this->getVerticeSO();
    Coordenadas* ne = this->getVerticeNE();
    bool contenido = ((x >= so->getX()) && (x <= ne->getX())
                    && (y <= so->getY()) && (y >= ne->getY()));
    delete so;
    delete ne;
    return contenido;
}
