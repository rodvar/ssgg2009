#include "Camara.h"

Camara::Camara(){
    this->eye[0] = 15.0;
    this->eye[1] = 15.0;
    this->eye[2] = 5.0;
    this->at[0]  = 0.0;
    this->at[1]  = 0.0;
    this->at[2]  = 0.0;
    this->up[0]  = 0.0;
    this->up[1]  = 0.0;
    this->up[2]  = 1.0;
    this->zoom = 30.0;
}

Camara::~Camara()
{
    //dtor
}
