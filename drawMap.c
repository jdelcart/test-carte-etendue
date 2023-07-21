#ifdef __APPLE_CC__
#include <OpenGL/OpenGL.h>
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "loadMap.h"
#include "drawMap.h"
#include "game.h"
#include "renard.c"

/*void loadAvatarTexture() //A inclure dans la fonction game, dans game.c
{
    int width, height;
    unsigned char *image = SOIL_load_image("renard.xcf", &width, &height, 0, SOIL_LOAD_RGBA);
    glGenTextures(1, &avatarTexture);
    glBindTexture(GL_TEXTURE_2D, avatarTexture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
    SOIL_free_image_data(image);

   //Set texture parameters (optional, but can improve texture quality)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
} utilise la bibliothèque SOIL.*/
void drawWall(int mX, int mY)			// fonction qui affiche les murs et les plateformes
{
	for (int j = 0; j < mX; ++j)
	{
		for (int i = 0; i < mY; ++i)
		{
			if(*(*(map + j) + i) == '#')
			{
				glColor3f(1.0f,1.0f,1.0f);

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				
				glTranslatef(j*Square_size,i*Square_size,0.0f);// Pour le scrolling horizontal
				//glTranslatef(i*Square_size,j*Square_size,0.0f); //Pour le scrolling vertical
				
				

				glBegin(GL_QUADS);
				//glColor3f(1.0,1.0,0.0);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glVertex3f(Square_size, 0.0f, 0.0f);
				glVertex3f(Square_size,Square_size, 0.0f);
				glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();
				
				glBegin(GL_POLYGON);         //draw road
				glColor3f(0.5,0.5,0.5);
				glVertex3f(0,15, 0.0f);
				glVertex3f(50, 15, 0.0f);
				glVertex3f(mX*Square_size, 15, 0.0f);
				glVertex3f(0, mY*Square_size, 0.0f);
				glEnd();
			}
			if (*(*(map + j) + i) == '|')
			{
				glColor3f(1.0f,1.0f,0.0f);

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				glTranslatef(j*Square_size,i*Square_size,0.0f);// Pour le scrolling horizontal
				//glTranslatef(i*Square_size,j*Square_size,0.0f); //Pour le scrolling vertical
				glBegin(GL_QUADS);
				glVertex3f(0.0f, 0.0f, 0.0f);
				glVertex3f(Square_size, 0.0f, 0.0f);
				glVertex3f(Square_size,Square_size, 0.0f);
				glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();
			}
			
			
			if(*(*(map + j) + i) == 'e')
			{	
				//glColor3f(1.0f,1.0f,0.0f);
				glColor3f(1,0,0);

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				
				glTranslatef(j*Square_size,i*Square_size,0.0f);// Pour le scrolling horizontal
				//glTranslatef(i*Square_size,j*Square_size,0.0f); //Pour le scrolling vertical
			
				glBegin(GL_QUADS);

				glVertex3f(0.0f, 0.0f, 0.0f);
				glVertex3f(Square_size, 0.0f, 0.0f);
				glVertex3f(Square_size,Square_size, 0.0f);
				glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();
			
			}


			if(*(*(map + j) + i) == 'b')
			{	
				//glColor3f(1.0f,1.0f,0.0f);
				glColor3f(0.3,0.3,1);

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				
				glTranslatef(j*Square_size,i*Square_size,0.0f);// Pour le scrolling horizontal
				//glTranslatef(i*Square_size,j*Square_size,0.0f); //Pour le scrolling vertical
			
				glBegin(GL_QUADS);

				glVertex3f(0.0f, 0.0f, 0.0f);
				glVertex3f(Square_size, 0.0f, 0.0f);
				glVertex3f(Square_size,Square_size, 0.0f);
				glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();
			
			}
			if(*(*(map + j) + i) == '-')
			{	
				//glColor3f(1.0f,1.0f,0.0f);
				glColor3f(0,0,1);

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				
				glTranslatef(j*Square_size,i*Square_size,0.0f);// Pour le scrolling horizontal
				//glTranslatef(i*Square_size,j*Square_size,0.0f); //Pour le scrolling vertical
			
				glBegin(GL_QUADS);

				glVertex3f(0.0f, 0.0f, 0.0f);
				glVertex3f(Square_size, 0.0f, 0.0f);
				glVertex3f(Square_size,Square_size, 0.0f);
				glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();
			
			}
			if(*(*(map + j) + i) == 'h')
			{	
				//glColor3f(1.0f,1.0f,0.0f);
				glColor3f(0.8,0.8,0.2);

				glMatrixMode(GL_MODELVIEW);
				glLoadIdentity();
				
				glTranslatef(j*Square_size,i*Square_size,0.0f);// Pour le scrolling horizontal
				//glTranslatef(i*Square_size,j*Square_size,0.0f); //Pour le scrolling vertical
			
				glBegin(GL_QUADS);

				glVertex3f(0.0f, 0.0f, 0.0f);
				glVertex3f(Square_size, 0.0f, 0.0f);
				glVertex3f(Square_size,Square_size, 0.0f);
				glVertex3f(0.0f,Square_size, 0.0f);

				glEnd();
			
			}
		
		
		}
	}

	

}

void drawPlayer(player p)
{
	int i, j;
	i = p->pos.x;
	j = p->pos.y;
	
	//Avatar carré
	/*glColor3f(0.0f,1.0f,0.0f);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(j*Square_size,i*Square_size,0.0f);// Pour le scrolling horizontal
	//glTranslatef(i*Square_size,j*Square_size,0.0f); //Pour le scrolling vertical
				
	glBegin(GL_QUADS);

	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(Square_size, 0.0f, 0.0f);
	glVertex3f(Square_size,Square_size, 0.0f);
	glVertex3f(0.0f,Square_size, 0.0f);*/
	

	//Avatar vulpin
	/*glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, avatarTexture);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef((j*Square_size, i*Square_size, 0.0f));

	glBegin(GL_QUADS);
	// Specification des coordonnées de la texture pour chaque vertex.
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(0.0f, 0.0f, 0.0f);

    glTexCoord2f(1.0f, 0.0f);
    glVertex3f(Square_size, 0.0f, 0.0f);

    glTexCoord2f(1.0f, 1.0f);
    glVertex3f(Square_size, Square_size, 0.0f);

    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(0.0f, Square_size, 0.0f);

    glEnd();

    // Terminaison de la cartographie de la texture après dessin.
    glDisable(GL_TEXTURE_2D);
	Implémentation utilisant la bibliothèque SOIL.
	*/

	int *texture = &renard; //Modèle vu en cours
	
	//glColor3f(1,0.3,0.3);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(j*Square_size,i*Square_size,0.0f);// Pour le scrolling horizontal
	
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
	gluBuild2DMipmaps(GL_TEXTURE_2D, renard.bytes_per_pixel, renard.width, renard.height, GL_RGB, GL_UNSIGNED_BYTE, renard.pixel_data);
	glEnable(GL_TEXTURE_2D);
	glTranslatef(0.0,0.0,-5.0);
	
	glBegin(GL_QUADS);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(Square_size, 0.0f, 0.0f);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(Square_size,Square_size, 0.0f);
	glTexCoord2f(0.0, 1.0);
	glVertex3f(0.0f,Square_size, 0.0f);
	
	glEnd();
	glFlush();
	glDisable(GL_TEXTURE_2D); 
	glutSwapBuffers(); 
}