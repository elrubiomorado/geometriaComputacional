#include <GL/glut.h>

void iniciar()
{
      glClearColor(1.0f, 0.5f, 0.0f, 0.0f);//orange/brown

      glColor3f(1.f, 0, 0);

      glLineWidth(3.f);

      glOrtho(-5, 3, -4, 3, -4, 2);
}

void dibujar()
{

      glClear(GL_COLOR_BUFFER_BIT);

      glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white

      glBegin(GL_TRIANGLES);

      glVertex3i(1, -1, 3);

      glVertex3i(2, 1, 7);

      glVertex3i(4, 2, 6);

      glEnd();

      glFlush();
}

int main(int argc, char *args[])
{
      glutInit(&argc, args);

      glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);

      glutInitWindowPosition(50, 50);

      glutInitWindowSize(1920, 1080);

      glutCreateWindow("Ejercicio 2.4");

      iniciar();

      glutDisplayFunc(dibujar);

      glutMainLoop();

      return 0;
}
