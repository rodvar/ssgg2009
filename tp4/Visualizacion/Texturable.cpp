#include "Texturable.h"

Texturable::Texturable()
{
   //TODO : si algo se ejecuta siempre independientemente del nombre del archivo iria aca
}

Texturable::~Texturable()
{
    //dtor
}

void Texturable::setTextura(std::string nombre) {
    this->nombreArchivo = nombre;
}

bool Texturable::listoTexturar(){
    return nombreArchivo != ""; // NIC FIJATE SI ESTO ANDA!
}

void Texturable::dibujarTexturado(){
    // TODO: Nico aca configuras el Pipeline para que pueda dibujar texturado, supongo q tenes
    // que abrir el archivo de (this->nombreArchivo) y demas

    this->dibujar();
}

