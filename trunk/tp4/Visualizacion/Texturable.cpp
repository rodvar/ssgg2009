#include "Texturable.h"
#include <GL/glut.h>
#include <iostream>

Texturable::Texturable()
{
    glGenTextures(1, &this->idTextura);
}

Texturable::~Texturable()
{
    glDeleteTextures(1,&this->idTextura);
}

void Texturable::setTextura(std::string nombre) {
    this->nombreArchivo = nombre;
}

bool Texturable::listoTexturar(){
    return nombreArchivo != "";
}

void Texturable::dibujarTexturado(){
    glEnable(GL_TEXTURE_2D);
    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D,this->idTextura);
    this->dibujar();
    glFlush();
    glDisable(GL_TEXTURE_2D);
}

