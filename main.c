#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <stdlib.h>
#include <stdio.h>

#include "loadMap.h"
#include "drawMap.h"
#include "game.h"


//char **map;

int mX = MaxX;
int mY = MaxY;
player p;


void initRendering()
{
	glEnable(GL_DEPTH_TEST);
}

void handleResize(int width,int heigth)
{
	glViewport(0, 0, width, heigth);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, heigth, 0);
}

void Display()
{
	
	glClearColor(0.0f,0.0f,0.0f,0.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	game(mX, mY, p);
	//drawWall(mX, mY);
	glFlush();
}

int main(int argc, char *argv[])
{
	
	//set_scroll();
	loadMap(mX, mY);     //Charge la carte
	p = createPlayer(mX, mY);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);

	glutInitWindowSize(mX*Square_size, mY*Square_size);

	glutCreateWindow("Test");

	initRendering();

	glutDisplayFunc(Display);
	glutReshapeFunc(handleResize);

	glutMainLoop();

	return 0;
}