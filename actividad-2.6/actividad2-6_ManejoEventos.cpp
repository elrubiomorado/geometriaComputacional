//Edgar Avila Gonzalez

#include <stdio.h>
#include <GL/glut.h>
enum {
	MENU_CHANGE = 1,
	MENU_EXIT
};

//Cambiar color figura
void changeColor(int idCommand){
    switch(idCommand){
        case 1:
            glColor4f(1.0f, 0.0f, 0.0f, 0.0f);//red
            glutPostRedisplay();
        break;
        case 2:
            glColor4f(1.0f, 1.0f, 0.0f, 0.0f);//yellow
            glutPostRedisplay();
        break;
        case 3:
            glColor4f(1.0f, 0.0f, 1.0f, 0.0f);//purple
            glutPostRedisplay();
        break;
        case 4:
            glColor4f(0.0f, 1.0f, 1.0f, 1.0f);//light blue
            glutPostRedisplay();
        break;
        case 5:
            glColor3f(0.0f, 1.0f, 0.0f);//Green
            glutPostRedisplay();
        break;
        case 6:
            glColor3f(0.0f, 0.0f, 1.0f);//Blue
            glutPostRedisplay();
        break;
        case 7:
            glColor3f(0.0f, 0.0f, 0.0f);//Black
            glutPostRedisplay();
        break;
        default:
            glColor4f(1.0f, 1.0f, 1.0f, 0.0f);//white
            glutPostRedisplay();
        break;
    }
}

//Cambiar color de fondo
void changeFontColor(int idCommand){
    switch(idCommand){
        case 1:
            glClearColor(1.0f, 0.0f, 0.0f, 0.0f);//red
            glutPostRedisplay();
        break;
        case 2:
            glClearColor(1.0f, 1.0f, 0.0f, 0.0f);//yellow
            glutPostRedisplay();
        break;
        case 3:
            glClearColor(1.0f, 0.0f, 1.0f, 0.0f);//purple
            glutPostRedisplay();
        break;
        case 4:
            glClearColor(0.0f, 1.0f, 1.0f, 1.0f);//light blue
            glutPostRedisplay();
        break;
        case 5:
            glClearColor(0.0f, 1.0f, 0.0f, 1.0f);//Green
            glutPostRedisplay();
        break;
        case 6:
            glClearColor(0.0f, 0.0f, 1.0f,0.0f);//Blue
            glutPostRedisplay();
        break;
        case 7:
            glClearColor(0.0f, 0.0f, 0.0f, 0.0f);//Black
            glutPostRedisplay();
        break;
        default:
            glClearColor(1.0f, 1.0f, 1.0f, 0.0f);//white
            glutPostRedisplay();
        break;
    }
}

//Menu principal
void SelectFromMenu(int idCommand)
{
  switch (idCommand)
  {
	case MENU_EXIT: // termina el programa
		exit(0);
		break;
	}
}



//Función para leer evento del teclado (espera la tecla c o el esc)
void Keyboard(unsigned char key, int x, int y)
{
	 switch (key)
	{
    //Evento salir
	case 27: // tecla esc
		exit(0);
		break;

    //Eventos Cambiar color figura    
    case 'r'://Figura roja
        changeColor(1);
    break;
    case 'y'://Figura yellow
        changeColor(2);
    break;
    case 'p'://Figura purple
        changeColor(3);
    break;
    case 'l'://Figura lightblue
        changeColor(4);
    break;
    case 'g'://Figura green
        changeColor(5);
    break;
    case 'b'://Figura azul
        changeColor(6);
    break;
    case 'n'://Figura negro
        changeColor(7);
    break;
    case 'w'://Figura blanco
        changeColor(8);
    break;

    //Eventos color de fondo
    case '1'://fondo rojo
        changeFontColor(1);
    break;
    case '2'://fondo amarillo
        changeFontColor(2);
    break;
    case '3'://fondo purpura
        changeFontColor(3);
    break;
    case '4'://fondo light blue
        changeFontColor(4);
    break;
    case '5'://fondo verde
        changeFontColor(5);
    break;
    case '6'://fondo azul
        changeFontColor(6);
    break;
    case '7'://fondo negro
        changeFontColor(7);
    break;
    case '8'://fondo blanco
        changeFontColor(8);
    break;
    }
    
}

// ventana del menú:
int buildPopupMenu(void)
{
    //sub menu para cambiar color de figuras
    int subMenuColor = glutCreateMenu(changeColor);
        //Opciones de color
        glutAddMenuEntry("Red", 1);
        glutAddMenuEntry("Yellow", 2);
        glutAddMenuEntry("Purple", 3);
        glutAddMenuEntry("Light Blue", 4);
        glutAddMenuEntry("Green", 5);
        glutAddMenuEntry("Blue", 6);
        glutAddMenuEntry("Black", 7);

    //sub menu cambiar color de fondo
    int subMenuFontColor = glutCreateMenu(changeFontColor);
        //Opciones de colores de fondo
        glutAddMenuEntry("Red", 1);
        glutAddMenuEntry("Yellow", 2);
        glutAddMenuEntry("Purple", 3);
        glutAddMenuEntry("Light Blue", 4);
        glutAddMenuEntry("Green", 5);
        glutAddMenuEntry("Blue", 6);
        glutAddMenuEntry("Black", 7);

    //Menu pricipal
	int menu = glutCreateMenu(SelectFromMenu);
        //Agregamos los submenus al menu principal
        glutAddSubMenu("Color", subMenuColor);
        glutAddSubMenu("Font Color", subMenuFontColor);
        //Opcion para salir
        glutAddMenuEntry("Salir", MENU_EXIT);
        //Tecla con la que se mostrara el munu, click derecho
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
    //Creamos la figura    
    glBegin(GL_TRIANGLES);
		glVertex3f(0.0, 1.0, 0.0); // primer vértice del triángilo
		glVertex3f(-1.0, -1.0, 0.0); //segundo vértice del triángilo
	    glVertex3f(1.0, -1.0, 0.0); // tercer  vértice del triángilo
	glEnd();
    
	glutSwapBuffers(); 
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
