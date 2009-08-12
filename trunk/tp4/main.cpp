#include "Visualizacion/OpenGLHelper.h"
#include "Visualizacion/OpenGLLighter.h"
#include "Visualizacion/OpenGLSurfacer.h"
#include "Visualizacion/Camara.h"
#include "Escena/Faro.h"
#include "Escena/Isla.h"
#include "Escena/Mar.h"
#include "Escena/Domo.h"

// PARAMETROS DIMENSIONALES
#define ALTURA_FARO         5.00f
#define ALTURA_ISLA         0.50f
#define ALTURA_CLAVADO_FARO 1.25f
#define LADO_DOMO           100
#define ALTURA_DOMO         50
#define DIMENSIONES_MAR     100
#define ALTURA_MAX_OLAS     0.50f
#define TEXTURA_DOMO "cielo.bmp"
#define TEXTURA_MAR "mar.bmp"
#define TEXTURA_ISLA "tierra.bmp"

// Objetos unicos
Camara camara;
Mar mar(DIMENSIONES_MAR,ALTURA_MAX_OLAS);
// Variables de control
bool view_axis = false;
bool esDia = true;
bool diaIniciado = false;

// Handle para el control de las Display Lists
GLuint dl_handle;
#define DL_AXIS (dl_handle+0)
#define DL_DOME (dl_handle+1)
#define DL_FARO (dl_handle+2)
#define DL_ISLA (dl_handle+3)
#define DL_LUNA (dl_handle+4)
#define DL_HAZ (dl_handle+5)

// Tama�o de la ventana
GLfloat window_size[2];
#define W_WIDTH window_size[0]
#define W_HEIGHT window_size[1]

#define TOP_VIEW_POSX	((int)((float)W_WIDTH*0.70f))
#define TOP_VIEW_W		((int)((float)W_WIDTH*0.30f))
#define TOP_VIEW_POSY	((int)((float)W_HEIGHT*0.70f))
#define TOP_VIEW_H		((int)((float)W_HEIGHT*0.30f))

#define HEIGHT_VIEW_POSX	((int)((float)W_WIDTH*0.70f))
#define HEIGHT_VIEW_W		((int)((float)W_WIDTH*0.30f))
#define HEIGHT_VIEW_POSY	((int)((float)W_HEIGHT*0.40f))
#define HEIGHT_VIEW_H		((int)((float)W_HEIGHT*0.30f))

/* Activa el NORMALIZE de OpenGL solo para las DisplayList */
void recalcularDisplayLists(){
    glDeleteLists(dl_handle,6);
    dl_handle = glGenLists(6);
    glNewList(DL_AXIS, GL_COMPILE);
        OpenGLHelper::dibujarEjes();
    glEndList();
    glNewList(DL_DOME, GL_COMPILE);
        Domo domo(LADO_DOMO, ALTURA_DOMO);
        glPushMatrix();
            domo.setTextura(TEXTURA_DOMO);
            domo.dibujarTexturado();
        glPopMatrix();
    glEndList();
    glNewList(DL_FARO, GL_COMPILE); // Faro
        Faro faro(ALTURA_FARO);
        glPushMatrix();
            glTranslatef(NULO,NULO,ALTURA_CLAVADO_FARO);
            faro.dibujarTexturado();
        glPopMatrix();
    glEndList();
    glNewList(DL_HAZ, GL_COMPILE); // Haz Luz Faro
        OpenGLSurfacer::setTranslucido();
        glColor4f(0.5,0.5,0.3,0.1);// amarillento clarito
        OpenGLHelper::dibujarCilindro(20, 0.3, 10*UNITARIO/3, 40);
        OpenGLSurfacer::setPorDefecto();
    glEndList();
    glNewList(DL_ISLA, GL_COMPILE); // Isla
        Isla isla(ALTURA_ISLA);
        isla.setTextura(TEXTURA_ISLA);
        isla.dibujarTexturado();
    glEndList();
    glNewList(DL_LUNA, GL_COMPILE); // Luna
        glPushMatrix();
            glTranslatef (0.0f, -DISTANCIA_LUCES, 10.0f);
            OpenGLSurfacer::setLuna();
            glutSolidSphere(1.0f, 10, 10);
            OpenGLSurfacer::setPorDefecto();
        glPopMatrix();
    glEndList();
}

void OnIdle (void){
    glutPostRedisplay();
}

void Set3DEnv()
{
	glViewport (0, 0, (GLsizei) W_WIDTH, (GLsizei) W_HEIGHT);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
    // Params: angulo de apertura de la lente / relacionHorizoVert / distancia min y max para q salga un obj
    gluPerspective(camara.getZoom(), (GLfloat) W_WIDTH/(GLfloat) W_HEIGHT, 0.10, 100.0);
    camara.preparar();
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Set3DEnv();

	mar.dibujarTexturado();

	if (view_axis)
		 glCallList(DL_AXIS);

	if (!esDia){// dibujar luna
	    glCallList(DL_LUNA);
	}

    glCallList(DL_FARO);
    glCallList(DL_ISLA);
	glCallList(DL_DOME);
    glPushMatrix();
        glTranslatef(NULO,NULO,ALTURA_CLAVADO_FARO);
        Faro::iluminar(esDia?-1:DL_HAZ);
    glPopMatrix();
    if(!diaIniciado) {
    	OpenGLLighter::generarLuzAmbienteDiurna();
    	GLfloat posicion[4] = {0.05f,0.05f,Faro::getAlturaFoco()-0.05f,UNITARIO};
    	OpenGLLighter::generarLuzSpot(posicion);
    	diaIniciado=true;
    }

	glutSwapBuffers();
}

void reshape (int w, int h)
{
   	W_WIDTH  = w;
	W_HEIGHT = h;
}

void mouse (int button, int status, int x, int y){
    // TODO
}

void mousePressed(int x,int y){
    static int ultimoX = 0;
    static int ultimoY = 0;

    int deltaX = x - ultimoX;
    int deltaY = y - ultimoY;

    if (deltaX > 0) camara.incrementarRotacionXY(0.50f);
    else if (deltaX < 0) camara.incrementarRotacionXY(-0.50f);
    if (deltaY > 0) camara.incrementarRotacionZ(0.50f);
    else if (deltaY < 0) camara.incrementarRotacionZ(-0.50f);

    ultimoX = x;
    ultimoY = y;
}

void keyboard (unsigned char key, int x, int y){
    switch (key) {
        case 0x1b: //ESC
            exit (0);
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
            OpenGLLighter::switchIluminador(atoi((const char*)&key));
            break;
        case 'c':
            camara.switchVista();
            break;
        case 'i': //Cambia de dia a noche y viceversa
            if (esDia)
                OpenGLLighter::generarLuzAmbienteNocturna();
            else
                OpenGLLighter::generarLuzAmbienteDiurna();
            OpenGLLighter::switchIluminador(LUZ_FARO);
            esDia = !esDia;
            glutPostRedisplay();
            break;
        case 'a':
            view_axis = !view_axis;
            glutPostRedisplay();
            break;
        case 'm':
            OpenGLHelper::cambiarModoPoligonos();
            recalcularDisplayLists();
            glutPostRedisplay();
            break;
        case '+':
            camara.incrementarZoom(-1);
            break;
        case '-':
            camara.incrementarZoom(1);
            break;
        case 'l':
        	camara.incrementarZVer(1);
        	break;
        case 'k':
			camara.incrementarZVer(-1);
			break;
        case 'p':
			mar.switchCalmoInquieto();
			break;
        default:
            break;
    }
}

void init(void) {
	glClearColor (155.0f/256.0f, 196.0f/256.0f, 226.0f/256.0f, 1.0f);
    glShadeModel (GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    float iluminacion[4] ={0.2, 0.2, 0.2, 1.0}; // TODO AFTER DATOS: Ver donde poner esto
    OpenGLLighter::setModeloIluminacion(iluminacion,true,false);

    mar.generar();
    mar.setTextura(TEXTURA_MAR);

	// Generacion de las Display Lists
	recalcularDisplayLists();
}

int main(int argc, char** argv){
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (1024, 768);
   glutInitWindowPosition (0, 0);

   glutCreateWindow (argv[0]);
   glutFullScreen();
   init ();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutKeyboardFunc(keyboard);
   glutMouseFunc(mouse);
   glutMotionFunc(mousePressed);
   glutIdleFunc(OnIdle);
   glutMainLoop();
   return 0;
}
