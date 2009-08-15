#include "Texturable.h"
#include <GL/glut.h>
#include <iostream>
#include "ImageLoader.h"

void Texturable::setAltaCalidad(){
    this->altaCalidad = true;
}

Texturable::Texturable()
{
    this->nombreArchivo = "";
    this->imagenCargada = false;
    this->altaCalidad = false;
}

Texturable::~Texturable()
{
    glDeleteTextures(1,&this->idTextura);
}

void Texturable::setTextura(std::string nombre) {
    glGenTextures(1, &this->idTextura);
    this->nombreArchivo = nombre;
}

void Texturable::cambiarTextura(std::string nombre){
    this->setTextura(nombre);
    this->imagenCargada = false;
    this->cargarImagen();
}

bool Texturable::listoTexturar(){
    return (this->nombreArchivo != "");
}

void Texturable::cargarImagen(){
    if (this->listoTexturar()){
        if (!this->imagenCargada){
            Image* image = ImageLoader::loadBMP(this->nombreArchivo.c_str());
            ImageLoader::loadTexture(image, this->idTextura);
            delete image;
            this->imagenCargada = true;
        }
        glEnable(GL_TEXTURE_2D);
        if (this->altaCalidad){
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        }
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        glBindTexture(GL_TEXTURE_2D,this->idTextura);
    }
    else{
        glBindTexture(GL_TEXTURE_2D,0);
        glDisable(GL_TEXTURE_2D);
    }
}

void Texturable::dibujarTexturado(){
    this->cargarImagen();
    this->dibujar();
    glFlush();
    glDisable(GL_TEXTURE_2D);
}

