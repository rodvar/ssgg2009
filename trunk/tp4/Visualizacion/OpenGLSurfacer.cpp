#include "OpenGLSurfacer.h"

void OpenGLSurfacer::setFactorFocalizacion(const float n){
    glMaterialfv(GL_FRONT_AND_BACK,GL_SHININESS,&n);
}

void OpenGLSurfacer::setPorDefecto(){
    GLfloat reflexion_ambiente[] = {0.2, 0.2, 0.2, 1.0};
    GLfloat reflexion_difusa[] = {0.8, 0.8, 0.8, 1.0};
    GLfloat reflexion_especular[] = {0.0, 0.0, 0.0, 1.0};
    GLfloat emisividad[] = {0.0, 0.0, 0.0, 1.0};

    setFactorFocalizacion(1.0f);
    glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,reflexion_ambiente);
    glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,reflexion_difusa);
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,reflexion_especular);
    glMaterialfv(GL_FRONT_AND_BACK,GL_EMISSION,emisividad);

    glBlendFunc (GL_ONE, GL_ZERO);
    glDepthMask (GL_TRUE);
    glDisable(GL_BLEND);
}

void OpenGLSurfacer::setMetal(){
    GLfloat reflexion_especular[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,reflexion_especular);
    setFactorFocalizacion(50.0f);

}

void OpenGLSurfacer::setLuna(){
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_diffuse[] = { 0.1, 0.5, 0.8, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_emission[] = {1.0, 1.0, 1.0, 0.0};
    glMaterialfv(GL_FRONT, GL_AMBIENT, no_mat);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
    setFactorFocalizacion(0.0);
}

void OpenGLSurfacer::setAguaSalada(){
    GLfloat mat_amb_diff[] = { 0.1, 0.5, 0.8, 1.0 };
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, mat_amb_diff);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    setFactorFocalizacion(1.0f);
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
