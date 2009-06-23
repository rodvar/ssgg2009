#include "Faro.h"
#include "../Visualizacion/OpenGLHelper.h"
#include "../Visualizacion/PintorCurva.h"
#include "../Geometria/CalculadorBezier.h"

Faro::Faro(const float altura)
{
    this->altura = altura;
    this->radioMax = UNITARIO;
    this->radioMin = 0.75f*this->radioMax;
}

Faro::~Faro(){}

float Faro::getAlturaFoco(){
    float largoBarrote = 0.75f*UNITARIO*sin(DOSPI/PRECISION_CABINA);
    return (0.75f*UNITARIO + largoBarrote/2);
}

float Faro::getLargoCabina(){
    return (0.75f*UNITARIO*sin(DOSPI/PRECISION_CABINA));
}


void Faro::iluminar(const float altura){
    int precision = 30;
    static int rotacionZ = NULO;
    float z = altura +getAlturaFoco();
    float largo = getLargoCabina()*2;
    glColor3f(UNITARIO,UNITARIO,UNITARIO);
    glPushMatrix();
        glTranslatef(0,0,z);
        glRotatef(++rotacionZ,NULO,NULO,UNITARIO);
        glRotatef(95,NULO,UNITARIO,NULO);
        glScalef(largo,largo,largo/2);
        OpenGLHelper::dibujarSamba(precision);
    glPopMatrix();
    if (rotacionZ == 360)
        rotacionZ = 0;
}

void Faro::dibujar(){
    this->dibujarColumna();
    this->dibujarCabina();
    this->dibujarSombrero();
}

void Faro::dibujarColumna(){
    int precision = 30;
    float deltaAlfa = 360.0f/precision;
    float inclinacionInterna = atan(this->altura/0.25f*this->radioMax);
    float base = this->radioMax*sin(DOSPI/precision);
    float altura = this->altura/sin(inclinacionInterna);
    Coordenadas normalCorridaMenos = Matematica::calcularNormal(Coordenadas(1,0,0),-deltaAlfa);
    Coordenadas normalCorrida = Matematica::calcularNormal(Coordenadas(1,0,0),deltaAlfa);

    glColor3f(0.35f,0.60f,0.65f);
    OpenGLHelper::dibujarCirculo(0.125f); //Cic inferior
    for (int i = 0; i < precision ; i++){
        glPushMatrix();
            glRotatef(i*deltaAlfa,0,0,1);
            glPushMatrix();// Base
                glTranslatef(this->radioMax,NULO,NULO);
                glRotated(90.0f-Matematica::anguloGrados(inclinacionInterna),0,-1,0);
                glTranslatef(NULO,-base/2,NULO);
                glBegin(GL_QUADS);
                    glNormal3f(normalCorridaMenos.getX(),normalCorridaMenos.getY(),normalCorridaMenos.getZ());
                    glVertex3f(NULO, NULO,NULO);
                    glVertex3f(NULO,NULO,altura);
                    glNormal3f(normalCorrida.getX(),normalCorrida.getY(),normalCorrida.getZ());
                    glVertex3f(NULO,base,altura);
                    glVertex3f(NULO,base,NULO);
                glEnd();
            glPopMatrix();
        glPopMatrix();
    }
    //Dibujar Barandal
    glPushMatrix();
        glTranslatef(0.0f,0.0f,this->altura);
        glPushMatrix();
            glScalef(0.75f,0.75f,1.0f);
            OpenGLHelper::dibujarCirculo(0.125f);//Circ superior
            OpenGLHelper::dibujarAbanico(0.125f);
        glPopMatrix();
        glPushMatrix();
            glScalef(1.0f,1.0f,0.30f);
            OpenGLHelper::dibujarSamba(precision);
        glPopMatrix();
    glPopMatrix();
}

void Faro::dibujarCabina(){
    int precision = PRECISION_CABINA;
    float deltaAlfa = 360.0f/precision;
    float largoBarrote = 0.75f*this->radioMax*sin(DOSPI/precision);//this->radioMax/4;
    float largo = this->altura*largoBarrote;

    glColor3f(1,0,0);
    for (int i = 0; i < precision ; i++){
        // Barrotes de soporte
        glPushMatrix();
            glRotatef(i*deltaAlfa,0,0,1);
            glPushMatrix();
                glRotatef(i*deltaAlfa,0,0,1);
                glTranslatef(0.75f*this->radioMax,largoBarrote/2,this->altura);
                glRotatef(90,1,0,0);
                glScalef(0.01f,0.01f,largoBarrote);
                OpenGLHelper::dibujarCilindro(precision);
            glPopMatrix();
            glPushMatrix();
                glRotatef(i*deltaAlfa,0,0,1);
                glTranslatef(0.75f*this->radioMax,largoBarrote/2,this->altura+largo);
                glRotatef(90,1,0,0);
                glScalef(0.01f,0.01f,largoBarrote);
                OpenGLHelper::dibujarCilindro(precision);
            glPopMatrix();
            // Barrotes soporta ventana
            glPushMatrix();
                glRotatef(i*deltaAlfa,0,0,1);
                glTranslatef(0.75f*this->radioMax,largoBarrote/2,this->altura);
                glScalef(0.01f,0.01f,largo);
                OpenGLHelper::dibujarCilindro(precision);
            glPopMatrix();
            // Barrotes de soporte de los anteriores
            glPushMatrix();
                glTranslatef(0.75f*this->radioMax,largoBarrote/2,this->altura + 0.75f*largo);
                glRotatef(90,1,0,0);
                glScalef(0.01f,0.01f,largoBarrote);
                OpenGLHelper::dibujarCilindro(precision);
            glPopMatrix();
        glPopMatrix();
    }
}

void Faro::dibujarSombrero(){
    int precision = 17;
    CalculadorBezier bezier(8);
    PintorCurva pintor;
    std::vector<Coordenadas> puntosDesde;
    std::vector<Coordenadas> puntosHasta;
    float posicionZ = this->altura*(1+ 0.75f*this->radioMax*sin(DOSPI/precision));
    float radio = 0.75f*this->radioMax;
    float paso = PI/5; //rad

    glColor3f(1.0f, 0.0f,0.0f);
    glPushMatrix();
        glTranslatef(NULO,NULO,posicionZ);
        //piso
        glPushMatrix();
            glScalef(this->radioMin,this->radioMin,0.30f);
            OpenGLHelper::dibujarSamba(precision);
        glPopMatrix();
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
        for (float alfa = 0.0f; alfa < 360; alfa += 18){
            glPushMatrix();
                glTranslatef(NULO,NULO, 0.30f);
                glRotatef(alfa, NULO, NULO, UNITARIO);
                glScalef(UNITARIO,UNITARIO,0.50f);
                pintor.pintarGajo(puntosDesde,puntosHasta);
            glPopMatrix();
        }
    glPopMatrix();

}
