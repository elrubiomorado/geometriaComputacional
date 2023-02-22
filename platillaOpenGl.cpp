//comando para compilar: g++ nombreArchivo.cpp -o nombreEjecutable -lglut -lGLU -lGL

#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
void init ( void )
{
/* En esta sección se indicarán los parámetros de inicialización de OpenGL (estado de buffers, .) */
}
void display ( void )
{
/* En esta sección, se indicarán las características de OpenGL .incluyendo el código necesario para
representar los objetos en pantalla */
}
void reshape ( int w, int h)
{
/* En esta sección, se indicará el código a ejecutar cuando se produce una redimensión de la ventana.
También es utilizada para definir el área de proyección de la figura en la ventana.
*/
}
void keyboard (unsigned char key, int x, int y)
{
/* En esta sección, se indicarán las tareas a realizar ante un evento de teclado. Se ha de tener presente
que todos los eventos de teclado no producen un redibujado de la pantalla, por lo que es conveniente
forzar este redibujado con funciones como glutPostRedisplay () */
}
void mouse ( int button, int state, int x, int y )
{
/* En esta sección, se indicarán las tareas a realizar ante un evento de ratón. Se ha de tener presente
que todos los eventos de ratón no producen un redibujado de la pantalla, por lo que es conveniente
forzar este redibujado con funciones como glutPostRedisplay () */
}
int main ( int argc, char** argv )
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize (250,250);
    glutInitWindowPosition (100,100);
    glutCreateWindow ("Título de la Ventana");
    init ( );
    glutReshapeFunc ( reshape );
    glutKeyboardFunc ( keyboard );
    glutMouseFunc ( mouse );
    glutDisplayFunc ( display );
    glutMainLoop ( );
    return 0;
}