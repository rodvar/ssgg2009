#include "OpenGLSurfacer.h"

void OpenGLSurfacer::setFactorFocalizacion(const float n){
    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,&n);
}

void OpenGLSurfacer::setPorDefecto(){
    GLfloat reflexion_ambiente[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat reflexion_difusa[] = {0.8, 0.8, 0.8, 1.0};
    GLfloat reflexion_especular[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat emisividad[] = {0.0, 0.0, 0.0, 1.0};
    //GLint color_indexes[] = {0, 1, 1};

    setFactorFocalizacion(1.0f);
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,reflexion_ambiente);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,reflexion_difusa);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,reflexion_especular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,emisividad);
    //glMaterialiv(GL_FRONT_AND_BACK,GL_COLOR_INDEXES,color_indexes);

    glBlendFunc (GL_ONE, GL_ZERO);
    glDepthMask (GL_TRUE);
    glDisable(GL_BLEND);
}

void OpenGLSurfacer::setMetal(){
    GLfloat reflexion_especular[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,reflexion_especular);
    setFactorFocalizacion(50.0f);

}

void OpenGLSurfacer::setTranslucido(){
    glEnable (GL_BLEND);
    glDepthMask (GL_FALSE);
    glBlendFunc (GL_ONE, GL_ONE);
    GLfloat mat_shininess[] = { 70.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
}
