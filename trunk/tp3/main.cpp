#include "Visualizacion/OpenGLHelper.h"
#include "Escena/Faro.h"
#include "Escena/Isla.h"

// Variables que controlan la ubicaci�n de la c�mara en la Escena 3D
float eye[3] = {15.0, 15.0, 5.0};
float at[3]  = { 0.0,  0.0, 0.0};
float up[3]  = { 0.0,  0.0, 1.0};
float zoom = 45.0;
float anguloAlfa = 0.0;
float anguloFi = 0.0;

// Variables de control
bool view_axis = true;

// Altura base del faro
#define ALTURA_FARO 9

// Handle para el control de las Display Lists
GLuint dl_handle;
#define DL_AXIS (dl_handle+0)
#define DL_GRID (dl_handle+1)
#define DL_FARO (dl_handle+2)
#define DL_ISLA (dl_handle+3)
//#define DL_OTHER (dl_handle+4)

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

void recalcularDisplayLists(){
    glDeleteLists(dl_handle,3);
    dl_handle = glGenLists(3);
    glNewList(DL_AXIS, GL_COMPILE);
		OpenGLHelper::dibujarEjes();
	glEndList();
    glNewList(DL_GRID, GL_COMPILE);
		OpenGLHelper::dibujarGrillaXY(); // Mar
	glEndList();
	glNewList(DL_FARO, GL_COMPILE); // Faro
        Faro faro(ALTURA_FARO);
        glPushMatrix();
            glTranslatef(1,1,0); // Esto va a cambiar cuando este la isla
            glScalef(0.5f,0.5f,0.5f); // esto tambien
            faro.dibujar();
        glPopMatrix();
    glEndList();
    glNewList(DL_ISLA, GL_COMPILE); // Isla
        Isla isla(1.5f);
        isla.dibujar();
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
    gluPerspective(zoom, (GLfloat) W_WIDTH/(GLfloat) W_HEIGHT, 0.10, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt (eye[0], eye[1], eye[2], at[0], at[1], at[2], up[0], up[1], up[2]);
	glRotatef(anguloAlfa,0,0,1);
	glRotatef(anguloFi,-1,1,0);
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	///////////////////////////////////////////////////
	// Escena 3D
	Set3DEnv();
	if (view_axis)
		 glCallList(DL_AXIS);
	glCallList(DL_GRID); // -->> TODO: Esto cuelga todo nic!!!
	//
	///////////////////////////////////////////////////
	// DIBUJAR //
    glCallList(DL_FARO);
    glCallList(DL_ISLA);
    glPushMatrix();
        glTranslatef(1,1,0); // Esto va a cambiar cuando este la isla
        glScalef(0.5f,0.5f,0.5f); // esto tambien
        Faro::iluminar(ALTURA_FARO);
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

    if (deltaX > 0) anguloAlfa += 0.50;
    if (deltaX < 0) anguloAlfa += -0.50;
    if (deltaY > 0) anguloFi += 0.50;
    if (deltaY < 0) anguloFi += -0.50;

    ultimoX = x;
    ultimoY = y;
}

void keyboard (unsigned char key, int x, int y){
    switch (key) {
        case 0x1b: //ESC
            exit (0);
            break;
        /*case 'g':
            view_grid = !view_grid;
            glutPostRedisplay();
            break;
        */
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
            zoom--;
            break;
        case '-':
            zoom++;
            break;
        default:
            break;
    }
}

void init(void)
{
    // Variables asociadas a �nica fuente de luz de la escena
    float light_color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    float light_ambient[4] = {0.05f, 0.05f, 0.05f, 1.0f}; //intensidad
    float light_position[3] = {10.0f, 10.0f, 8.0f};
    float material[3] = {1.0f,1.0f,1.0f};
	dl_handle = glGenLists(3);

	glClearColor (155.0f/256.0f, 196.0f/256.0f, 226.0f/256.0f, 0.0f);
    glShadeModel (GL_SMOOTH);
    //glMaterialfv(GL_FRONT, GL_SPECULAR,material); NICO INVESTIGA ESTO!
    glEnable(GL_DEPTH_TEST);

    // glLightModel q onda??
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);

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
