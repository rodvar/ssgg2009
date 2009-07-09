#include "Faro.h"
#include "../Visualizacion/OpenGLHelper.h"
#include "../Visualizacion/OpenGLSurfacer.h"
#include "../Visualizacion/PintorCurva.h"
#include "../Geometria/CalculadorBezier.h"

float Faro::altura = UNITARIO;
float Faro::radioMax = UNITARIO;
float Faro::radioMin = UNITARIO;

Faro::Faro(const float altura)
{
    this->altura = altura;
    this->radioMax = altura/5;
    this->radioMin = PORCENTAJE_ESCALA*this->radioMax;
}

Faro::~Faro(){}

float Faro::getAlturaFoco(){;
    return (PORCENTAJE_ESCALA*altura + getLargoCabina()/2 + 0.20f);
}

float Faro::getLargoCabina(){
    return (0.50f*altura*getLargoBarroteCabina()/PORCENTAJE_ESCALA);
}

float Faro::getLargoBarroteCabina(){
    return (radioMax*sin(DOSPI/PRECISION_CABINA));
}

float Faro::getDistanciaVistaStd(){
    return radioMin-0.05f;
}

void Faro::iluminar(){
    static int rotacionZ = 180;
    Coordenadas direccionIluminada;

    glColor3f(UNITARIO,UNITARIO,UNITARIO);
    glPushMatrix();
		glTranslatef(NULO,NULO,getAlturaFoco());
        glRotatef(++rotacionZ,NULO,NULO,UNITARIO);
        glRotatef(-95,NULO,UNITARIO,NULO);

        OpenGLHelper::dibujarSamba(PRECISION_COLUMNA,UNITARIO/3,UNITARIO/3);
        OpenGLSurfacer::setTranslucido();//Vidrio del foco de iluminacion
			OpenGLHelper::dibujarCirculo(10,UNITARIO/5);
        OpenGLSurfacer::setPorDefecto();

        direccionIluminada = Matematica::rotar(Coordenadas(0,0,1),rotacionZ,135);

        GLfloat light_diffuse[] = { UNITARIO, UNITARIO, UNITARIO, UNITARIO };
        GLfloat light_specular[] = { UNITARIO, UNITARIO, UNITARIO, UNITARIO };
        GLfloat light_position[] = { 0.05f, 0.05f, getAlturaFoco()-0.05f, UNITARIO };
        GLfloat light_direction[] = { direccionIluminada.getX(), direccionIluminada.getY(), direccionIluminada.getZ() };

        glLightfv(GL_LIGHT4, GL_DIFFUSE, light_diffuse);
        glLightfv(GL_LIGHT4, GL_SPECULAR, light_specular);
        glLightfv(GL_LIGHT4, GL_POSITION, light_position);
        glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 45.0);
        glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, light_direction);
        glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 3.0f);
    glPopMatrix();

    OpenGLSurfacer::setTranslucido();
    glPushMatrix();
		glTranslatef(NULO,NULO,getAlturaFoco());
		glRotatef(rotacionZ,NULO,NULO,UNITARIO);
		glRotatef(110,NULO,-UNITARIO,NULO);
		OpenGLHelper::dibujarCilindro(20, 0, 3, 30);
	glPopMatrix();
	OpenGLSurfacer::setPorDefecto();

    if (rotacionZ == 360)
        rotacionZ = 0;
}

void Faro::dibujar(){
    this->dibujarColumna();
    this->dibujarCabina();
    this->dibujarSombrero();
}

void Faro::dibujarColumna(){
    float altura = PORCENTAJE_ESCALA * this->altura;

    glColor3f(0.75f,0.75f,0.8f);
    OpenGLHelper::dibujarCilindro(PRECISION_COLUMNA,this->radioMax, this->radioMin, altura);
    glPushMatrix();
        glTranslatef(0,0,altura);
        OpenGLHelper::dibujarSamba(PRECISION_COLUMNA,this->radioMax, 0.30f*this->radioMax);
    glPopMatrix();
}

void Faro::dibujarCabina(){
    float deltaAlfa = 360.0f/PRECISION_CABINA;
    float largoBarrote = getLargoBarroteCabina();
    float largo = 0.50f*this->altura*largoBarrote/PORCENTAJE_ESCALA;
    float altura = PORCENTAJE_ESCALA*this->altura;

    glColor3f(0.50f,0.50f,0.50f);
    for (int i = 0; i < PRECISION_CABINA ; i++){
        // Barrotes de soporte
        glPushMatrix();
            glRotatef(i*deltaAlfa,0,0,1);
            glPushMatrix();
                glRotatef(i*deltaAlfa,0,0,1);
                glTranslatef(PORCENTAJE_ESCALA*this->radioMax,largoBarrote/2,altura);
                glRotatef(90,1,0,0);
                OpenGLHelper::dibujarCilindro(PRECISION_CABINA/2,0.01f,0.01f,largoBarrote);
            glPopMatrix();
            glPushMatrix();
                glRotatef(i*deltaAlfa,0,0,1);
                glTranslatef(PORCENTAJE_ESCALA*this->radioMax,largoBarrote/2,altura+largo);
                glRotatef(90,1,0,0);
                OpenGLHelper::dibujarCilindro(PRECISION_CABINA/2,0.01f,0.01f,largoBarrote);
            glPopMatrix();
            // Barrotes soporta ventana
            glPushMatrix();
                glRotatef(i*deltaAlfa,0,0,1);
                glTranslatef(PORCENTAJE_ESCALA*this->radioMax,largoBarrote/2,altura);
                OpenGLHelper::dibujarCilindro(PRECISION_CABINA/2,0.01f,0.01f,largo);
            glPopMatrix();
            // Barrotes de soporte de los anteriores
            glPushMatrix();
                glTranslatef(PORCENTAJE_ESCALA*this->radioMax,largoBarrote/2,altura + PORCENTAJE_ESCALA*largo);
                glRotatef(90,1,0,0);
                OpenGLHelper::dibujarCilindro(PRECISION_CABINA/2,0.01f,0.01f,largoBarrote);
            glPopMatrix();
        glPopMatrix();
    }
}

void Faro::dibujarSombrero(){
    CalculadorBezier bezier(8);
    PintorCurva pintor;
    std::vector<Coordenadas> puntosDesde;
    std::vector<Coordenadas> puntosHasta;
    float posicionZ = PORCENTAJE_ESCALA*this->altura + getLargoCabina();
    float radio = (this->radioMax + this->radioMin)/2;
    float paso = PI/5; //rad

    glColor3f(0.50f,0.25f,0.25f);
    glPushMatrix();
        glTranslatef(NULO,NULO,posicionZ);
        //piso
        OpenGLHelper::dibujarSamba(PRECISION_CABINA,this->radioMin,0.30f*this->radioMax);
        //tapa
        puntosDesde.push_back(Coordenadas(radio,NULO,NULO));
        puntosDesde.push_back(Coordenadas(radio*(float)cos(MEDIOPI/3),NULO,radio*(float)sin(MEDIOPI/3)));
        puntosDesde.push_back(Coordenadas(radio*(float)cos(2*MEDIOPI/3),NULO,radio*(float)sin(2*MEDIOPI/3)));
        puntosDesde.push_back(Coordenadas(NULO,NULO,radio));
        bezier.setControlPoints(puntosDesde);
        puntosDesde = bezier.calcularPuntos();

        puntosHasta.push_back(Coordenadas(radio*(float)cos(paso),radio*(float)sin(paso),NULO));
        puntosHasta.push_back(Coordenadas(radio*(float)(cos(paso)*sin(2*MEDIOPI/3)),radio*(float)(sin(paso)*sin(2*MEDIOPI/3)),radio*(float)cos(2*MEDIOPI/3)));
        puntosHasta.push_back(Coordenadas(radio*(float)(cos(paso)*sin(MEDIOPI/3)),radio*(float)(sin(paso)*sin(MEDIOPI/3)),radio*(float)cos(MEDIOPI/3)));
        puntosHasta.push_back(Coordenadas(NULO,NULO,radio));
        bezier.setControlPoints(puntosHasta);
        puntosHasta = bezier.calcularPuntos();
        for (float alfa = NULO; alfa < 360; alfa += 18){
            glPushMatrix();
                glTranslatef(NULO,NULO, 0.30f);
                glRotatef(alfa, NULO, NULO, UNITARIO);
                glScalef(UNITARIO,UNITARIO,0.50f);
                pintor.pintarGajo(puntosDesde,puntosHasta, Coordenadas(NULO,NULO,posicionZ));
            glPopMatrix();
        }
    glPopMatrix();

}
