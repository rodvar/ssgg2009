#include "Visualizacion/OpenGLHelper.h"
#include "Visualizacion/OpenGLLighter.h"
#include "Visualizacion/OpenGLSurfacer.h"
#include "Visualizacion/Camara.h"
#include "Escena/Faro.h"
#include "Escena/Isla.h"
#include "Escena/Mar.h"
#include "Escena/Domo.h"

// Objetos unicos
Camara camara;
Mar mar(100,0.50);
// Variables de control
bool view_axis = false;
bool esDia = true;

// Altura base del faro
#define ALTURA_FARO         5.00f
#define ALTURA_CLAVADO_FARO 0.75f
#define ALTURA_ISLA         0.30f
#define LADO_DOMO           100

// Handle para el control de las Display Lists
GLuint dl_handle;
#define DL_AXIS (dl_handle+0)
#define DL_DOME (dl_handle+1)
#define DL_FARO (dl_handle+2)
#define DL_ISLA (dl_handle+3)

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
    //glEnable(GL_NORMALIZE);
        glDeleteLists(dl_handle,3);
        dl_handle = glGenLists(3);
        glNewList(DL_AXIS, GL_COMPILE);
            OpenGLHelper::dibujarEjes();
        glEndList();
        glNewList(DL_DOME, GL_COMPILE);
			Domo domo(LADO_DOMO);
			glPushMatrix();
				glTranslatef(-LADO_DOMO/2,-LADO_DOMO/2,LADO_DOMO-1);
				domo.dibujar();
			glPopMatrix();
        glEndList();
        glNewList(DL_FARO, GL_COMPILE); // Faro
            Faro faro(ALTURA_FARO);
            glPushMatrix();
                glTranslatef(NULO,NULO,ALTURA_CLAVADO_FARO);
                faro.dibujar();
            glPopMatrix();
        glEndList();
        glNewList(DL_ISLA, GL_COMPILE); // Isla
            Isla isla(ALTURA_ISLA);
            glPushMatrix();
                glTranslatef(NULO,NULO,0.1f); //correccion evita mescla texturas
                isla.dibujar();
            glPopMatrix();
        glEndList();
    //glDisable(GL_NORMALIZE);
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

	glCallList(DL_DOME);

	mar.dibujar();

	if (view_axis)
		 glCallList(DL_AXIS);

	if (!esDia){// dibujar luna
        glPushMatrix();
            glTranslatef (-60.0f, -50.0f, 7.0f);
            OpenGLSurfacer::setLuna();
            glutSolidSphere(1.0f, 16, 16);
            OpenGLSurfacer::setPorDefecto();
        glPopMatrix();
	}

    glCallList(DL_FARO);
    glCallList(DL_ISLA);
    glPushMatrix();
        glTranslatef(NULO,NULO,ALTURA_CLAVADO_FARO);
        Faro::iluminar(esDia);
    glPopMatrix();
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
    if (deltaX < 0) camara.incrementarRotacionXY(-0.50f);
    if (deltaY > 0) camara.incrementarRotacionZ(0.50f);
    if (deltaY < 0) camara.incrementarRotacionZ(-0.50f);

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
        //case '4': Se evita que se pueda controlar la luz del faro
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

void init(void)
{
    // Variables asociadas a �nica fuente de luz de la escena
	dl_handle = glGenLists(3);

	glClearColor (155.0f/256.0f, 196.0f/256.0f, 226.0f/256.0f, 0.0f);
    glShadeModel (GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);

    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);

    OpenGLSurfacer::setPorDefecto();
    OpenGLLighter::generarLuzAmbienteDiurna();

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
