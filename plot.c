/*
 * Instituto Tecnologico de Costa Rica
 * Escuela de Ingenieria en Computacion
 * Computer Graphics
 *
 * Programa: Mesa Example
 * Archivo: mesa_example.c
 */
#include "plot.h"
#include "malloc.h"

COLOR **buffer;
int h_size, v_size;
h_size =400;
v_size =800;



void plot (i,j){
	if (i>=0&&i<h_size && j>=0&&j< v_size ){
		buffer[i][j].r = 1;
		buffer[i][j].g = 1;
		buffer[i][j].b = 1;
	}
}

void init (){
	int i, j;
	buffer = (COLOR **)malloc(h_size * sizeof(COLOR*));
	for (i = 0; i < h_size; i++)
	{
		buffer[i] = (COLOR *)malloc(v_size * sizeof(COLOR));
	}
	for (i = 0; i < h_size; i++)
	{
		for (j = 0; j < v_size; j++){
			buffer[i][j].r = 0;
			buffer[i][j].g = 0;
			buffer[i][j].b = 0;
		}
	}
}
void draw (){
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(h_size,v_size);
	glutCreateWindow("Mesa Example");
	glClear(GL_COLOR_BUFFER_BIT);
	gluOrtho2D(-0.5, h_size +0.5, -0.5, v_size + 0.5);
	glutDisplayFunc(draw_scene);
	glutMainLoop();
}
void draw_scene() {
	static int last_x = 0;
	int i, j;
	COLOR color;
	for (i = 0; i < last_x; i++)
	{
		for (j = 0; j < v_size; j++)
		{
			glColor3f (buffer[i][j].r,buffer[i][j].g,buffer[i][j].b);
			glBegin (GL_POINTS);
			glVertex2i (i,j);
			glEnd();
		}
	}
	for (i = last_x; i < h_size; i++)
	{
		for (j = 0; j < v_size; j++)
		{
			glColor3f (buffer[i][j].r,buffer[i][j].g,buffer[i][j].b);
			glBegin(GL_POINTS);
			glVertex2i(i,j);
			glEnd();
			last_x = i;
		}
	}
	glFlush();
}
