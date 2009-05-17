#include "Arbol.h"

Arbol::Arbol(Curva* modeladoHoja, const unsigned short int niveles){
    this->niveles = niveles;
    this->raiz = new Rama(modeladoHoja);
    this->raiz->ramificar();
    for (unsigned short int i = 1; i < this->niveles; i++){
        this->raiz->getRamaSecundaria1()->ramificar();
        this->raiz->getRamaSecundaria2()->ramificar();
        this->raiz->getRamaSecundaria3()->ramificar();
    }
}

Arbol::~Arbol(){
    delete this->raiz;
}

void Arbol::dibujar(){
    this->raiz->dibujar();
    this->dibujarRecursivo(this->raiz);
}

void Arbol::dibujarRecursivo(Rama* raiz){
    if (raiz){
        glPushMatrix();
            glTranslatef(0,0,1);
            glRotatef(-45,0,1,0);
            glRotatef(180,0,0,1);
            glScalef(0.75,0.75,0.75);
            raiz->dibujar();
            this->dibujarRecursivo(raiz->getRamaSecundaria1());
            this->dibujarRecursivo(raiz->getRamaSecundaria2());
            this->dibujarRecursivo(raiz->getRamaSecundaria3());
        glPopMatrix();
    }

    /*

    if (i == 0){
        this->rama->dibujar();
        this->dibujarRecursivo(i + 1,0);
    }
    else if (i < this->niveles){
        // ramificacion 1
        glPushMatrix();
            glTranslatef(0,0,1);
            glRotatef(-45,0,1,0);
            glRotatef(180,0,0,1);
            glScalef(0.75,0.75,0.75);
            this->ramas[i]->dibujar();
            if (secundarias < 3)
                this->dibujarRecursivo(i,secundarias+1);
            else
                secundarias = 0;
        glPopMatrix();

        // ramificacion 2
        glPushMatrix();
            glTranslatef(0,0,1);
            glRotatef(-45,0,1,0);
            glRotatef(180,0,0,1);
            glScalef(0.75,0.75,0.75);
            this->ramas[i]->dibujar();
            if (secundarias < 3)
                this->dibujarRecursivo(i,secundarias+1);
            else
                secundarias = 0;
        glPopMatrix();

        // ramificacion 3
        glPushMatrix();
            glTranslatef(0,0,1);
            glRotatef(-45,0,1,0);
            glRotatef(180,0,0,1);
            glScalef(0.75,0.75,0.75);
            this->ramas[i]->dibujar();
            if (secundarias < 3)
                this->dibujarRecursivo(i,secundarias+1);
            else
                secundarias = 0;
        glPopMatrix();




*/


        /*

        glPushMatrix();
            glTranslatef(0,0,1);
            glRotatef(this->ramas[i]->getAngulo(),0,1,0);
            glRotatef(this->ramas[i]->getOrientacion(),0,0,1);
            glScalef(0.75,0.75,0.75);
            this->ramas[i]->dibujar();

            //Ramas secundarias
            glPushMatrix();
                glRotatef(this->ramas[i]->getAngulo(),0,1,0);
                glScalef(0.75,0.75,0.75);
                glPushMatrix();
                    glTranslatef(0,0,1);
                    this->ramas[i]->dibujar();
                glPopMatrix();
                glPushMatrix();
                    glTranslatef(0,0,0.66);
                    this->ramas[i]->dibujar();
                glPopMatrix();
                glPushMatrix();
                    glTranslatef(0,0,0.33);
                    this->ramas[i]->dibujar();
                glPopMatrix();
            glPopMatrix();
            this->dibujarRecursivo(i + 1);
        glPopMatrix();
        */
}

Rama* Arbol::crearArbol(Rama* raiz){
    static int i = 0;
    if (raiz){
        i++;
        if (i < this->niveles){
            raiz->ramificar();
            this->crearArbol(raiz->getRamaSecundaria1());
            this->crearArbol(raiz->getRamaSecundaria2());
            this->crearArbol(raiz->getRamaSecundaria3());
        }
        else
            i = 0;
    }
}
