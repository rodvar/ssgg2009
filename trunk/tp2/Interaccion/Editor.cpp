#include "Editor.h"

Editor::Editor(float ancho, float alto)
{
    this->marco.setBase(ancho*0.30f);
    this->marco.setAltura(alto*0.30f);
}

Editor::~Editor()
{
    //dtor
}
