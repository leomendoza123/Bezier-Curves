#include "main.h"
#include "bezier.h"
#include "plot.c"

int main(int argc, char* argv[])
{

	//Inicia GLUT
	glutInit(&argc, argv);
	//Crea buffer
	init ();



    int x[4], y[4];
    int i;

    /// FOR ARREGLO CON TODOS LAS LINEAS
    printf ("Enter the x- and y-coordinates of the four control points.\n");
    for (i=0; i<4; i++)
	scanf ("%d%d", &x[i], &y[i]);

    bezier (x, y);
    /// TERMINA FOR

    //Dibueja el buffer
	draw ();

}
