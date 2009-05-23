#include "Rama.h"
#include "../Geometria/Rectangulo.h" // PAra probar

Rama::Rama(Curva* modeladoHoja)
{
    this->color.setRojo(0.6f);
    this->color.setVerde(0.25f);
    this->qobj = gluNewQuadric(); // crea un objeto cuadrático
    this->modeladoHoja = modeladoHoja;
    float orientacion = this->calcularOrientacionHoja();
    this->hoja1 = new Hoja(modeladoHoja,orientacion);
    this->hoja2 = new Hoja(modeladoHoja,orientacion);
    this->hoja3 = new Hoja(modeladoHoja,orientacion);
    this->ramaSecundaria1 = NULL;
    this->ramaSecundaria2 = NULL;
    this->ramaSecundaria3 = NULL;
}

Rama::~Rama()
{
    gluDeleteQuadric(qobj);
    delete hoja1;
    delete hoja2;
    delete hoja3;
    this->desRamificar();
}


void Rama::ramificar(){
    this->desRamificar();
    this->ramaSecundaria1 = new Rama(this->modeladoHoja);
    this->ramaSecundaria2 = new Rama(this->modeladoHoja);
    this->ramaSecundaria3 = new Rama(this->modeladoHoja);
}

void Rama::desRamificar(){
    if (this->ramaSecundaria1)
        delete this->ramaSecundaria1;
    if (this->ramaSecundaria2)
        delete this->ramaSecundaria2;
    if (this->ramaSecundaria3)
        delete this->ramaSecundaria3;
}

void Rama::dibujar(){
    // Cilindro unitario
    float separacionX = -0.40;
    float separacionY = -0.80;
	float z = .8;
	glDisable(GL_LIGHTING);
    glColor3f(this->color.getRojo(), this->color.getVerde(), this->color.getAzul());

    glPushMatrix(); // Cilindro
        glScalef(0.125,0.125,1.5);
        gluQuadricDrawStyle(this->qobj, GLU_FILL); //estilo relleno
        gluCylinder(qobj, 1, 1, 1, 100, 100);
    glPopMatrix();
    glPushMatrix();
        glTranslatef(separacionX,separacionY+0.2,1.2*z);
        glRotatef(this->hoja1->getOrientacion(),1,1,0);
        glRotatef(this->hoja1->getOrientacion(), 0, 0, 1); // rotacion en x
        glScalef(0.5,0.5,1);
        this->hoja1->dibujar();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(separacionX+0.4,separacionY-0.2,0.9*z);
        glRotatef(this->hoja2->getOrientacion(),1,1,0);
        glRotatef(this->hoja2->getOrientacion(), 0, 0, 1); // rotacion en x
        glScalef(0.5,0.5,1);
        this->hoja2->dibujar();
    glPopMatrix();
    glPushMatrix();
        glTranslatef(separacionX,separacionY-0.1,0.7*z);
        glRotatef(this->hoja3->getOrientacion(),1,1,0);
        glRotatef(this->hoja3->getOrientacion(), 0, 0, 1); // rotacion en x
        glScalef(0.5,0.5,1);
        this->hoja3->dibujar();
    glPopMatrix();

    glEnable(GL_LIGHTING);

}

float Rama::calcularOrientacionHoja(){
    float orientacion = rand() % 181;
    if (orientacion > 45)
        orientacion = 45 - orientacion;
    return 0;
}
