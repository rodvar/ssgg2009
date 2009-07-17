#include "Texturable.h"
#include <GL/glut.h>
#include <iostream>
#include "ImageLoader.h"

Texturable::Texturable()
{
    glGenTextures(1, &this->idTextura);
    this->nombreArchivo = "";
}

Texturable::~Texturable()
{
    glDeleteTextures(1,&this->idTextura);
}

void Texturable::setTextura(std::string nombre) {
    this->nombreArchivo = nombre;
}

bool Texturable::listoTexturar(){
    return (this->nombreArchivo != "");
}

void Texturable::cargarImagen(){
    if (this->listoTexturar()){
        Image* image = ImageLoader::loadBMP(this->nombreArchivo.c_str());
        this->idTextura = ImageLoader::loadTexture(image);
        delete image;
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

