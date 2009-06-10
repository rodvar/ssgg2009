#include <iostream>
#include <GL/glut.h>

// Rotation amounts
static GLfloat xangle = 0.0f;
static GLfloat yangle = 0.0f;

void init(void)
{
glClearColor (0.0, 0.0, 0.0, 0.0);
glShadeModel (GL_FLAT);
}

void SpecialKeys(int key, int x, int y)
{
if(key == GLUT_KEY_UP) {
yangle++;
}

if(key == GLUT_KEY_DOWN) {
yangle--;
}

if(key == GLUT_KEY_LEFT) {
xangle--;
}

if(key == GLUT_KEY_RIGHT) {
xangle++;
}
// Refresh the Window
glutPostRedisplay();
}


void display(void)
{
glClear (GL_COLOR_BUFFER_BIT);
glColor3f (1.0, 1.0, 1.0);
glLoadIdentity (); /* clear the matrix */
/* viewing transformation */
//gluLookAt(eye, center, up vector);
gluLookAt (0, 0, 5, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
glRotatef(xangle, 0, 1, 0);
glRotatef(yangle, 1, 0, 0);

//Front Face
glBegin(GL_QUADS);
glNormal3f(0.0f, 0.0f, 1.0f);
glVertex3f(1, 1, 1);
glVertex3f(1, -1, 1);
glVertex3f(-1, -1, 1);
glVertex3f(-1, 1, 1);
glEnd();

//Back Face
glBegin(GL_QUADS);
glNormal3f(0.0f, 0.0f, -1.0f);
glVertex3f(1, 1, -1);
glVertex3f(1, -1, -1);
glVertex3f(-1, -1, -1);
glVertex3f(-1, 1, -1);
glEnd();

glColor3f(0.0f, 1.0f, 0.0f);
//Right Face
glBegin(GL_QUADS);
glNormal3f(1.0f, 0.0f, 0.0f);
glVertex3f(1, 1, 1);
glVertex3f(1, -1, 1);
glVertex3f(1, -1, -1);
glVertex3f(1, 1, -1);
glEnd();

//Left Face
glBegin(GL_QUADS);
glNormal3f(-1.0f, 0.0f, 0.0f);
glVertex3f(-1, 1, 1);
glVertex3f(-1, -1, 1);
glVertex3f(-1, -1, -1);
glVertex3f(-1, 1, -1);
glEnd();

glColor3f(0.0f, 0.0f, 1.0f);
//Top Face
glBegin(GL_QUADS);
glNormal3f(0.0f, 1.0f, 0.0f);
glVertex3f(1, 1, 1);
glVertex3f(-1, 1, 1);
glVertex3f(-1, 1, -1);
glVertex3f(1, 1, -1);
glEnd();

//Bottom Face
glBegin(GL_QUADS);
glNormal3f(0.0f, -1.0f, 0.0f);
glVertex3f(1, -1, 1);
glVertex3f(-1, -1, 1);
glVertex3f(-1, -1, -1);
glVertex3f(1, -1, -1);
glEnd();

glFlush ();
}

void reshape (int w, int h)
{
glViewport (0, 0, (GLsizei) w, (GLsizei) h);
glMatrixMode (GL_PROJECTION);
glLoadIdentity ();
glFrustum (-1.0, 1.0, -1.0, 1.0, 1.5, 20.0);
glMatrixMode (GL_MODELVIEW);
}

int main(int argc, char** argv)
{
glutInit(&argc, argv);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
glutInitWindowSize (500, 500);
glutInitWindowPosition (100, 100);
glutCreateWindow (argv[0]);
init ();
glutDisplayFunc(display);
glutSpecialFunc(SpecialKeys);
glutReshapeFunc(reshape);
glutMainLoop();
return 0;
}
