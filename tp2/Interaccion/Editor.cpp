#include "Editor.h"

Editor::Editor(float ancho, float alto)
{
    this->marco.setBase(ancho*PJE_DIMENSIONES);
    this->marco.setAltura(alto*PJE_DIMENSIONES);
}

Editor::~Editor()
{
    //dtor
}
