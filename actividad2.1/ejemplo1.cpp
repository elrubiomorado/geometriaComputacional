#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>

int al = 1080;
int an = 1920;

void init ( void )
{
    glEnable ( GL_DEPTH_TEST );//Se habilita la utilización de cálculos de profundidad

    //Color de fonfo
    glClearColor(0.0,0.0,1.0,0.0);//dark blue
}


void display ( void ){

    glClear ( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); //Resetea el buffer de colores y profundidad, eliminando posibles contenidos de ventanas anteriores

    glPushMatrix ( ); //En OpenGL, los cálculos de rotaciones, texturas, translaciones, se realizan mediante el cálculo de matrices. Esta función crea una copia de la matriz de modelado y la empuja una posición la pila de matrices.

    //Color de la figura en formato rgb
    glColor4f(1.0f, 0.0f, 1.0f, 0.0f);//purple

    glTranslatef(0.0, 0.0, -4.0); //Esta función realiza una translación del origen de coordenadas al punto (0,0,-4)

    /*
    Esta estructura es la encargada de dibujar el triángulo. glBegin() comienza una secuencia de vértices con
    los que se construirá la primitiva. El tipo de primitivas viene dado por el parámetro de glBegin(), en este
    caso GL_TRIANGLES que se encarga de definir un triángulo. glEnd() se encarga simplemente de cerrar
    la estructura. Existen más posibles parámetros de glBegin () para dibujar otras primitivas, que se verán
    mas adelante.
    */
    // glBegin(GL_TRIANGLES);
    //     glVertex3f( 0.0f, 1.0f, 0.0f);
    //     glVertex3f(-1.0f,-1.0f, 0.0f);
    //     glVertex3f( 1.0f,-1.0f, 0.0f);
    // glEnd();

    //Color de la figura en formato rgb
    // glColor3f(0.0f, 1.0f, 0.0f);//Green
    
    // glBegin(GL_LINES);
    // {
    //     glVertex3f ( -1.0f, -1.0f, 0.0f);
    //     glVertex3f ( 1.0f, 1.0f, 0.0f);
    //     glVertex3f ( -1.0f, 1.0f, 0.0f);
    //     glVertex3f ( 1.0f, -1.0f, 0.0f);
    // }
    // glEnd();
    /*
        OBJETOS GEOMÉTRICOS 3D.
        GLUT incluye un conjunto de rutinas que permiten la generación de forma fácil de objetos geometricos
        en 3D. A continuación se presentan las más importantes, así como un ejemplo de su uso.
        • glutSolidSphere
        • glutSolidCube
        • glutSolidCone
        • glutSolidTorus
        • glutSolidDodecahedron
        • glutSolidOctahedron
        • glutSolidTetrahedron
        • glutSolidIcosahedron
        • glutSolidTeapot
        A continuación se presenta el código necesario para dibujar un dodecaedro solido
        glutSolidDodecahedron();
    */

    glutSolidDodecahedron();

    glPopMatrix ( );//Una vez realizadas los cálculos sobre la matriz de segundo plano, se coloca esta en la cima de la pila de matrices
    
    glutSwapBuffers ( );//Esta función se encarga de intercambiar el buffer posterior con el buffer anterior, siendo necesaria porque se ha definido que se trabaje con un doble buffer. La utilización de este doble buffer evita parpadeos en la generación de la imagen.
}

//Como toda callback, la función reshape() es de tipo void. Se pasan como argumentos los valores de ancho y alto después de la redimensión de la ventana
void reshape(int w, int h)
{
    glViewport ( 0, 0, w, h );//Esta función indica la porción de ventana donde OpenGL podrá dibujar

    glMatrixMode ( GL_PROJECTION );
    /*
    Esta función especifica la matriz de proyección como matriz sobre la que se van a realizar las
    transformaciones. OpenGL dispone de tres tipos de matrices, la matriz de proyección
    (GL_PROJECTION), la matriz de modelo (GL_MODELVIEW) y la matriz de textura (GL_TEXTURE)
    */

    glLoadIdentity ( );//Esta función carga como matriz de proyección la matriz identidad. 
    if ( h==0 )
        gluPerspective ( 80, ( float ) w, 1.0, 5000.0 );
        /*
        Esta función opera sobre la matriz de proyección y define el ángulo del campo de visión en sentido
        vertical (en grados), la relación entre la altura y la anchura de la figura (aspecto), el plano más cercano a
        la cámara y el plano más lejano de la cámara, respectivamente. Estos dos últimos son los planos de corte,
        que son los que se encargan de acotar el volumen de visualización por delante y por detrás de la figura.
        ttodo lo que esté por delante del plano más cercano y todo lo que esté detrás del plano más lejano no será
        representado en la ventana.
        */
    else
        gluPerspective ( 80, ( float ) w / ( float ) h, 1.0, 5000.0 );

        glMatrixMode ( GL_MODELVIEW );//Esta función especifica la matriz de modelado como matriz sobre la que se van a realizar las transformaciones.

        glLoadIdentity ( );//Esta función carga como matriz de modelado la matriz identidad
}

//Funcion de eventos en teclado
void keyboard ( unsigned char key, int x, int y )
{

    //Eventos al precionar teclas
    switch ( key ) {//Key === tecla presionada
        case 27: /* tecla de Escape */
            exit ( 0 );
            break;
        case 'f':
            glutFullScreen ( );
            break;
        case 'w':
            glutReshapeWindow ( 400,400 );
            break;
        default:
            break;
    }
}

//Funcion de eventos mouse
void mouse ( int button, int state, int x, int y )
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_UP){//Tecla precionada && click derecho
        printf("\nClick izquierdo presionado");
    }
    if ( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )//tecla soltada && click izquierdo
    {
        printf("\nClick izquierdo soltado");
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_UP){//Tecla precionada && click derecho
        printf("\nClick derecho presionado");
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN){//Tecla soltada && click derecho
        printf("\nClick derecho soltado");
    }
    
}

int main ( int argc, char** argv )
{
    
    glutInit (&argc, argv);//Esta funcion inicia GLUT

    glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    //Define el modo en que se dibuja la ventana
    /*
        GLUT_RGB indica que los colores se definirán con tres componentes (Red, Green, Blue)
        GLUT_DOUBLE indica que se utilizarán dos buffer para componer la imagen.
        GLUT_DEPTH indica que se va a utilizar buffer de profundidad.
    */

    glutInitWindowSize (1920,1080); //Define el tamaño de la ventana en pixeles

    glutInitWindowPosition (0,0); //Define la posicion donde se abrira la ventana

    glutCreateWindow ("Mi Ejemplo"); //Crea la ventane y de parametro tiene el nombre de dicha ventana

    init ( ); //Esta funcion la definimos para inicializar los parametros de OpenGl antes de pasar al control del programa a GLUT
    
    glutReshapeFunc ( reshape );//Funcion callback, la funcion pasada como parametro se ejecutara cada vez que GLUT determine que la ventana debe de ser redibujada (Ejemplo, al maximizar, poner ventanas arriba, etc)

    glutKeyboardFunc ( keyboard ); //Eventos del teclado

    glutMouseFunc (mouse );//Eventos del mouse

    glutDisplayFunc ( display );//Eventos del teclado

    glutMainLoop ( ); //Esta función cede el control de flujo del programa a GLUT, que a partir de estos “eventos”, irá llamando a las funciones que han sido pasadas como callback. 
    return 0;
}
