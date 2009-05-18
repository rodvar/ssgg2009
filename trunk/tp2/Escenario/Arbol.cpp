#include "Arbol.h"

Arbol::Arbol(Curva* modeladoHoja, const unsigned short int niveles){
    this->niveles = niveles;
    this->raiz = new Rama(modeladoHoja);
    this->crearArbol(this->raiz);
}

Arbol::~Arbol(){
    delete this->raiz;
}

void Arbol::dibujar(){
    this->raiz->dibujar();
    this->dibujarRecursivo(this->raiz->getRamaSecundaria1(),-1);
    this->dibujarRecursivo(this->raiz->getRamaSecundaria1(),0);
    this->dibujarRecursivo(this->raiz->getRamaSecundaria1(),1);
}

void Arbol::dibujarRecursivo(Rama* raiz, int tipo){
    if (raiz){
        switch (tipo){
            case -1:// IZQ
                glPushMatrix();
                    glTranslatef(0,0,1);
                    glRotatef(-45,0,1,0);
                    glRotatef(180,0,0,1);
                    glScalef(0.75,0.75,0.75);
                    raiz->dibujar();
                    this->dibujarRecursivo(raiz->getRamaSecundaria1(), -1);
                    this->dibujarRecursivo(raiz->getRamaSecundaria2(), 0);
                    this->dibujarRecursivo(raiz->getRamaSecundaria3(), 1);
                glPopMatrix();
                break;
            case 0: // CTRO
                glPushMatrix();
                    glTranslatef(0,0,1);
                    glRotatef(-45,1,0,0);
                    glRotatef(180,0,0,1);
                    glScalef(0.75,0.75,0.75);
                    raiz->dibujar();
                    this->dibujarRecursivo(raiz->getRamaSecundaria1(), -1);
                    this->dibujarRecursivo(raiz->getRamaSecundaria2(), 0);
                    this->dibujarRecursivo(raiz->getRamaSecundaria3(), 1);
                glPopMatrix();
                break;
            case 1: //DER
                glPushMatrix();
                    glTranslatef(0,0,1);
                    glRotatef(-45,0,-1,0);
                    glRotatef(180,0,0,1);
                    glScalef(0.75,0.75,0.75);
                    raiz->dibujar();
                    this->dibujarRecursivo(raiz->getRamaSecundaria1(), -1);
                    this->dibujarRecursivo(raiz->getRamaSecundaria2(), 0);
                    this->dibujarRecursivo(raiz->getRamaSecundaria3(), 1);
                glPopMatrix();
                break;
        }
    }
}

void Arbol::crearArbol(Rama* raiz){
    static int izq = 0;
    static int ctr = 0;
    static int der = 0;
    if (raiz){
        if ((izq < this->niveles) && (ctr < this->niveles) && (der < this->niveles)){
            raiz->ramificar();
            izq++;
            this->crearArbol(raiz->getRamaSecundaria1());
            ctr++;
            this->crearArbol(raiz->getRamaSecundaria2());
            der++;
            this->crearArbol(raiz->getRamaSecundaria3());
        }
        else{
            if (izq < this->niveles) izq = 0;
            if (ctr < this->niveles) ctr = 0;
            if (der < this->niveles) der = 0;
        }
    }
}
