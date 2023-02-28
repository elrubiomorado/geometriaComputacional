#include <stdio.h>
#include <GL/glut.h>
enum {
	MENU_CHANGE = 1,
	MENU_EXIT
};

static int mode = 0;
static int color = 0;

void changeColor(int idCommand){
    switch(idCommand){
        case 1:
            glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
        break;
        case 2:
            glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
        break;
        default:
            glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
        break;

    }
}
void SelectFromMenu(int idCommand)
{
  switch (idCommand)
  {
	case MENU_EXIT: // termina el programa
		exit(0);
		break;
	}
}

void colors(int idCommand)
{
  switch (idCommand)
  {
	case 1://cambia el color del triangulo (modo a c)
		mode = 1; // si mode es igual a 0, entonces mode toma el valor d 1, si no toma el valor de cero.
        glutPostRedisplay();
			break;
    case 2://cambia el color del triangulo (modo a c)
		mode = 2; // si mode es igual a 0, entonces mode toma el valor d 1, si no toma el valor de cero.
        glutPostRedisplay();
			break;
    case 3://cambia el color del triangulo (modo a c)
		mode = 3; // si mode es igual a 0, entonces mode toma el valor d 1, si no toma el valor de cero.
        glutPostRedisplay();
			break;
    case 4://cambia el color del triangulo (modo a c)
		mode = 4; // si mode es igual a 0, entonces mode toma el valor d 1, si no toma el valor de cero.
        glutPostRedisplay();
			break;
    case 5://cambia el color del triangulo (modo a c)
		mode = 3; // si mode es igual a 0, entonces mode toma el valor d 1, si no toma el valor de cero.
        glutPostRedisplay();
			break;
	}

	glutPostRedisplay();
}
//Función para leer evento del teclado (espera la tecla c o el esc)
void Keyboard(unsigned char key, int x, int y)
{
	 switch (key)
	{
	case 27: // tecla esc
		exit(0);
		break;
    }
}

// ventana del menú:
int buildPopupMenu(void)
{
    int subMenu = glutCreateMenu(colors);
    glutAddMenuEntry("Red", 1);
    glutAddMenuEntry("Yellow", 2);
    glutAddMenuEntry("Purple", 3);
    glutAddMenuEntry("Light Blue", 4);
    glutAddMenuEntry("Brown", 5);

	int menu = glutCreateMenu(SelectFromMenu);
    glutAddSubMenu("Color", subMenu);
	glutAddMenuEntry("Salir", MENU_EXIT);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
	return menu;
}

//ventana de despliegue de la aplicación
void display ()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity(); // carga matriz de identidad (matriz de ubicación del triangulo en la pantalla), la matriz tiene 1's en su diagonal principal
	glTranslatef(0.0, 0.0, -4.0); 
		/* Multiplica la matriz actual, por una matreiz de tralación con los valores pasados como argumentos una traslación es una transformación geométrica que mueve cada punto de una figura o un espacio a la misma distancia en una dirección determinada. 
	
	*/
	if(mode == 0) // Carga el triágulo
	 {
		glBegin(GL_TRIANGLES);
			glColor3f (1.f, 1.f, 1.f);//elegimos color blanco
			glVertex3f(0.0, 1.0, 0.0); // primer vértice del triángilo
			glVertex3f(-1.0, -1.0, 0.0); //segundo vértice del triángilo
			glVertex3f(1.0, -1.0, 0.0); // tercer  vértice del triángilo
	  glEnd();
	}
    else if(mode == 1) // Carga el triágulo
	{
		glBegin(GL_TRIANGLES);
			glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
			glVertex3f(0.0, 1.0, 0.0); // primer vértice del triángilo
			glVertex3f(-1.0, -1.0, 0.0); //segundo vértice del triángilo
			glVertex3f(1.0, -1.0, 0.0); // tercer  vértice del triángilo
	  glEnd();
    } 
    else if(mode == 2) // Carga el triágulo
	{
		glBegin(GL_TRIANGLES);
			glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
			glVertex3f(0.0, 1.0, 0.0); // primer vértice del triángilo
			glVertex3f(-1.0, -1.0, 0.0); //segundo vértice del triángilo
			glVertex3f(1.0, -1.0, 0.0); // tercer  vértice del triángilo
	  glEnd();
    } 
    else if(mode == 3) // Carga el triágulo
	{
		glBegin(GL_TRIANGLES);
			glColor4f(1.0f, 0.0f, 1.0f, 0.0f);//purple
			glVertex3f(0.0, 1.0, 0.0); // primer vértice del triángilo
			glVertex3f(-1.0, -1.0, 0.0); //segundo vértice del triángilo
			glVertex3f(1.0, -1.0, 0.0); // tercer  vértice del triángilo
	  glEnd();
    }
    else if(mode == 4) // Carga el triágulo
	{
		glBegin(GL_TRIANGLES);
			glColor4f(0.0f, 1.0f, 1.0f, 1.0f);//light blue
			glVertex3f(0.0, 1.0, 0.0); // primer vértice del triángilo
			glVertex3f(-1.0, -1.0, 0.0); //segundo vértice del triángilo
			glVertex3f(1.0, -1.0, 0.0); // tercer  vértice del triángilo
	  glEnd();
    } 
    else if(mode == 5) // Carga el triágulo
	{
		glBegin(GL_TRIANGLES);
			glColor4f(1.0f, 0.5f, 0.0f, 0.0f);//orange/brown
			glVertex3f(0.0, 1.0, 0.0); // primer vértice del triángilo
			glVertex3f(-1.0, -1.0, 0.0); //segundo vértice del triángilo
			glVertex3f(1.0, -1.0, 0.0); // tercer  vértice del triángilo
	  glEnd();
    } 
    else
	{
		glBegin(GL_TRIANGLES); //Cargamos el segundo triángulo
			glColor3f (0.f, 1.f, 0.f);  // Color verde
			glVertex3f(0.0, 1.0, 0.0); //Pintamos el primer vértice del segundo triángulo
			glColor3f (1.f, 1.f, 1.f);//Color blanco
			glVertex3f(-1.0, -1.0, 0.0);//pintamos el segundo vértice del segundo triángulo
			glColor3f (1.f, 0.f, 0.f); // Color rojo
			glVertex3f(1.0, -1.0, 0.0); //pintamos el tercer vértice del segundo triángulo

		glEnd();
	 }

		glutSwapBuffers(); // intercambiamos los buffers para cargar ambos triágulos 
}

void resize (int w, int h) // Redimiensionar la ventana de ejecución de la aplicación
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50., w/(double)h, 1., 10.);
	glMatrixMode(GL_MODELVIEW);
}

void init (void)
{
	glEnable(GL_DEPTH_TEST);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Ejercicio");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(resize);
	glutKeyboardFunc(Keyboard);

	buildPopupMenu();
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glutMainLoop();
	return 0;
}
