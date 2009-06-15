#include "Visualizacion/OpenGLHelper.h"
#include "Escena/Faro.h"

// Variables que controlan la ubicación de la cámara en la Escena 3D
float eye[3] = {15.0, 15.0, 5.0};
float at[3]  = { 0.0,  0.0, 0.0};
float up[3]  = { 0.0,  0.0, 1.0};
float zoom = 30.0;
float anguloAlfa = 0.0;
float anguloFi = 0.0;

// Variables de control
bool view_axis = true;


// Handle para el control de las Display Lists
GLuint dl_handle;
#define DL_AXIS (dl_handle+0)
#define DL_GRID (dl_handle+1)
#define DL_FARO (dl_handle+2)
#define DL_ISLA (dl_handle+3)

// Tamaño de la ventana
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

// Devuelve los puntos de control de la curva
std::list<Coordenadas> curve(){
    std::list<Coordenadas> lista;
    Coordenadas c;
    c.setX(1);
    c.setY(0);
    for(int i= 0; i < 10; i++){
        c.setZ(i);
        lista.insert(lista.end(),c);
    }
    return lista;
}

void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	///////////////////////////////////////////////////
	// Escena 3D
	Set3DEnv();
	if (view_axis)
		 glCallList(DL_AXIS);
	glCallList(DL_GRID);
	//
	///////////////////////////////////////////////////
	// DIBUJAR --> usar DL al mango!!!! //
    glCallList(DL_FARO);
	// Tengo que tener calculados todos los puntos de control de ambas curvas
    // tomar de a pares en un GL_QUAD_STRIP
	////////////////


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
    // Variables asociadas a única fuente de luz de la escena
    float light_color[4] = {1.0f, 1.0f, 1.0f, 1.0f};
    float light_ambient[4] = {0.05f, 0.05f, 0.05f, 1.0f}; //intensidad
    float light_position[3] = {10.0f, 10.0f, 8.0f};
	dl_handle = glGenLists(3);

	glClearColor (155.0f/256.0f, 196.0f/256.0f, 226.0f/256.0f, 0.0f);
    glShadeModel (GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    // glLightModel q onda??
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_color);
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHT0);
    glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);

	// Generación de las Display Lists
	glNewList(DL_AXIS, GL_COMPILE);
		OpenGLHelper::dibujarEjes();//Ejes
	glEndList();
	glNewList(DL_GRID, GL_COMPILE);
		OpenGLHelper::dibujarGrillaXY(); // Mar
	glEndList();
	glNewList(DL_FARO, GL_COMPILE); // Faro
        Faro faro(1,5);
        glPushMatrix();
            glTranslatef(1,1,0);
            glScalef(0.5f,0.5f,0.5f);
            faro.dibujar();
        glPopMatrix();
    glEndList();
	/** TODO: Aca crear una DL con la ISLA ¿y otra con el cielo? **/
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
