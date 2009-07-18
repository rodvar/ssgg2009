#include "Texturable.h"
#include <GL/glut.h>
#include <iostream>
#include "ImageLoader.h"

Texturable::Texturable()
{
    glGenTextures(1, &this->idTextura);
    this->nombreArchivo = "";
    this->imagenCargada = false;
}

Texturable::~Texturable()
{
    glDeleteTextures(1,&this->idTextura);
}

void Texturable::setTextura(std::string nombre) {
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
    // TODO: Nico busca el metodo glTexEnvf a ver como combiene configurarlo segun el caso
    // por un tema de performance..
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
        glEnable(GL_TEXTURE_2D);
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

