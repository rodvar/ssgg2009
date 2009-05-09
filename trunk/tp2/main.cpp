#include <math.h>
#include "Visualizacion/IU.h"
#include "Visualizacion/Pantalla.h"

void display(void)
{
	Motor::getInstancia()->actualizar();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
   glutInitWindowSize (1024, 768);
   glutInitWindowPosition (0, 0);
   glutCreateWindow (argv[0]);
   glutFullScreen();

   Pantalla::getInstancia(); // Fuerza ña inicializacion

   // Configuracion de callbacks
   glutDisplayFunc(display);
   glutReshapeFunc(Pantalla::redimensionar);
   glutKeyboardFunc(IU::keyboard);
   glutMouseFunc(IU::mouse);
   glutIdleFunc(IU::OnIdle);
   glutMainLoop();
   return 0;
}
