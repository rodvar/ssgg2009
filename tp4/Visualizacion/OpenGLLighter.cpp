#include "OpenGLLighter.h"
#include <iostream>

void OpenGLLighter::setModeloIluminacion(const float ambiente[], bool local, bool dobleCara){
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambiente);
    glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, local?GL_TRUE:GL_FALSE);
    glLightModeli(GL_LIGHT_MODEL_TWO_SIDE, dobleCara?GL_TRUE:GL_FALSE);
}
void OpenGLLighter::setModeloIluminacionPorDefecto(){
    GLfloat ambiente[] = { 0.2, 0.2, 0.2, 1.0 };
    setModeloIluminacion(ambiente,false,false);
}

void OpenGLLighter::setFactorFocalizacion(const int i, const float n){
    GLenum luz = GL_LIGHT0 + i;
    glLightfv(luz , GL_SPOT_EXPONENT,&n);
}

void OpenGLLighter::setAperturaSpot(const int i, const float cutoff){
    GLenum luz = GL_LIGHT0 + i;
    glLightfv(luz, GL_SPOT_CUTOFF,&cutoff);
}

void OpenGLLighter::setAtenuacion(const int i, const float constante, const float lineal, const float cuad){
    GLenum luz = GL_LIGHT0 + i;
    glLightf(luz, GL_CONSTANT_ATTENUATION, constante);
    glLightf(luz, GL_LINEAR_ATTENUATION, lineal);
    glLightf(luz, GL_QUADRATIC_ATTENUATION, cuad);
}

void OpenGLLighter::switchIluminador(const int i){
    static bool prendido0=true;
    static bool prendido1=true;
    static bool prendido2=true;
    static bool prendido3=true;
    static bool prendido4=false;
    static bool prendido5=false;
    static bool prendido6=false;
    static bool prendido7=true;

    switch (i){
        case 0:
            prendido0 ? glDisable(GL_LIGHT0) : glEnable(GL_LIGHT0);
            prendido0 = !prendido0;
            break;
        case 1:
            prendido1 ? glDisable(GL_LIGHT1) : glEnable(GL_LIGHT1);
            prendido1 = !prendido1;
            break;
        case 2:
            prendido2 ? glDisable(GL_LIGHT2) : glEnable(GL_LIGHT2);
            prendido2 = !prendido2;
            break;
        case 3:
            prendido3 ? glDisable(GL_LIGHT3) : glEnable(GL_LIGHT3);
            prendido3 = !prendido3;
            break;
        case 4:
            prendido4 ? glDisable(GL_LIGHT4) : glEnable(GL_LIGHT4);
            prendido4 = !prendido4;
            break;
        case 5:
            prendido5 ? glDisable(GL_LIGHT5) : glEnable(GL_LIGHT5);
            prendido5 = !prendido5;
            break;
        case 6:
            prendido6 ? glDisable(GL_LIGHT6) : glEnable(GL_LIGHT6);
            prendido6 = !prendido6;
            break;
        case 7:
            prendido7 ? glDisable(GL_LIGHT7) : glEnable(GL_LIGHT7);
            prendido7 = !prendido7;
            break;
        default:
            break;
    }
}

void OpenGLLighter::generarLuzAmbiente(){
    // Le pongo max intensidad difusa para que se note dsede donde viene la luz ambiente
    GLfloat light_color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat light_ambient[4] = {0.05f, 0.05f, 0.05f, 1.0f}; //intensidad
    GLfloat light_position0[4] = {34.0f, 34.0f, 34.0f, 1.0f};
    GLfloat light_position1[4] = {-34.0f, 34.0f, 34.0f, 1.0f};
    GLfloat light_position2[4] = {-34.0f, -34.0f, 34.0f, 1.0f};
    GLfloat light_position3[4] = {34.0f, -34.0f, 34.0f, 1.0f};

    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT2, GL_POSITION, light_position2);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT3, GL_POSITION, light_position3);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT3);
}

void OpenGLLighter::generarLuzAmbienteDiurna(){
    GLfloat light_specular[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat light_color[4] = {0.05f, 0.05f, 0.05f, 1.0f};
    GLfloat light_ambient[4] = {0.05f, 0.05f, 0.05f, 1.0f}; //intensidad
    GLfloat light_position0[4] = {34.0f, 34.0f, 34.0f, 1.0f};
    GLfloat light_position1[4] = {-34.0f, 34.0f, 34.0f, 1.0f};
    GLfloat light_position2[4] = {-34.0f, -34.0f, 34.0f, 1.0f};
    GLfloat light_position3[4] = {34.0f, -34.0f, 34.0f, 1.0f};
    GLfloat sol_color[4] = {1.0f, 1.0f, 0.80f, 1.0f};
    GLfloat sol_ambient[4] = {1.0f, 1.0f, 0.80f, 1.0f}; //intensidad
    GLfloat sol_position[4] = {0.0f, 0.0f, 50.0f, 0.0f}; // Luz del sol direccional

    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT2, GL_POSITION, light_position2);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT3, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT3, GL_POSITION, light_position3);
    //Sol
    glLightfv(GL_LIGHT7,GL_DIFFUSE,sol_color);
    glLightfv(GL_LIGHT7, GL_AMBIENT, sol_ambient);
    glLightfv(GL_LIGHT7, GL_POSITION, sol_position);
    glLightfv(GL_LIGHT7, GL_SPECULAR, light_specular);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT3);
    glEnable(GL_LIGHT7);
}

void OpenGLLighter::generarLuzAmbienteNocturna(){
    GLfloat light_specular[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat light_color[4] = {0.2f*0.27f, 0.2f*0.44f, 0.2f*0.76f, 1.0f};
    GLfloat light_ambient[4] = {0.01f, 0.01f, 0.01f, 1.0f}; //intensidad
    GLfloat light_position0[4] = {34.0f, 34.0f, 1.0f, 1.0f};
    GLfloat light_position1[4] = {-34.0f, 34.0f, 1.0f, 1.0f};
    GLfloat light_position2[4] = {-34.0f, -34.0f, 1.0f, 1.0f};
    GLfloat light_position3[4] = {34.0f, -34.0f, 1.0f, 1.0f};
    GLfloat luna_color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat luna_ambient[4] = {0.0f, 0.0f, 0.0f, 1.0f}; //intensidad
    GLfloat luna_position[4] = {0.0f, 8.5f-50.0f, 10.0f}; // Luz de luna
    GLfloat luna_specular[4] = {1.0f, 1.0f, 1.0f, 1.0f}; //

    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position0);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT1, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT1, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT1, GL_POSITION, light_position1);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT2, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT2, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT2, GL_POSITION, light_position2);
    glLightfv(GL_LIGHT3, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT3, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT3, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT3, GL_POSITION, light_position3);
    //Luna
    glLightfv(GL_LIGHT7,GL_DIFFUSE,luna_color);
    glLightfv(GL_LIGHT7, GL_AMBIENT, luna_ambient);
    glLightfv(GL_LIGHT7, GL_POSITION, luna_position);
    glLightfv(GL_LIGHT7, GL_SPECULAR, luna_specular);

    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);
    glEnable(GL_LIGHT3);
    glEnable(GL_LIGHT7);
}

void OpenGLLighter::generarLuzSpot(){
    //TODO: Modificar y Utilizar para la unica luz spot de la escena
    GLfloat n = 30.0;
    GLfloat cutoff = 45;
    GLfloat light_ambient[4] = {0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat light_color1[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat light_specular1[4] = {1.0f, 1.0f, 1.0f, 1.0f}; //intensidad
    GLfloat light_position1[4] = {0.0f, 3.0f, 0.0f,1.0f};
    GLfloat light_direccion1[4] = {0, -1, 0.0f, 1.0f};

    glLightfv(GL_LIGHT4, GL_SPOT_EXPONENT,&n);
    glLightfv(GL_LIGHT4, GL_SPOT_CUTOFF,&cutoff);
    glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, light_direccion1);
    glLightfv(GL_LIGHT4, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT4, GL_DIFFUSE, light_color1);
    glLightfv(GL_LIGHT4, GL_SPECULAR, light_specular1);
    glLightfv(GL_LIGHT4, GL_POSITION, light_position1);
}
