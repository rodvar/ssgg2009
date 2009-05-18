#include "Arbol.h"

Arbol::Arbol(Curva* modeladoHoja, const unsigned short int niveles){
    this->niveles = niveles;
    this->raiz = new Rama(modeladoHoja);
    this->crearArbol(this->raiz);
    this->nivelIzq = 0;
    this->nivelCtr = 0;
    this->nivelDer = 0;
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
            case -1:// nivelIzq
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
            case 0: // nivelCtrO
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
            case 1: //nivelDer
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
    if (raiz){
        if ((nivelIzq < this->niveles) && (nivelCtr < this->niveles) && (nivelDer < this->niveles)){
            raiz->ramificar();
            this->nivelIzq++;
            this->crearArbol(raiz->getRamaSecundaria1());
            this->nivelCtr++;
            this->crearArbol(raiz->getRamaSecundaria2());
            this->nivelDer++;
            this->crearArbol(raiz->getRamaSecundaria3());
        }
        else{
            if (this->nivelIzq < this->niveles) nivelIzq = 0;
            if (this->nivelCtr < this->niveles) nivelCtr = 0;
            if (this->nivelDer < this->niveles) nivelDer = 0;
        }
    }
}
