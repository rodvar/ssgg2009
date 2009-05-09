#include "Luz.h"

Luz::Luz(){
    this->light_color[0] = 1.0f;
    this->light_color[1] = 1.0f;
    this->light_color[2] = 1.0f;
    this->light_color[3] = 1.0f;
    this->light_position[0] = 10.0f;
    this->light_position[1] = 10.0f;
    this->light_position[2] = 8.0f;
    this->light_ambient[0] = 0.05f;
    this->light_ambient[1] = 0.05f;
    this->light_ambient[2] = 0.05f;
    this->light_ambient[3] = 1.0f;
}

Luz::~Luz()
{
    //dtor
}
