#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "loadMap.h"


bool loadMap(int mX, int mY)		//fonction qui ouvre le fichier txt et charge la carte dans le tableau
{
    map = malloc(sizeof(char *) * mX);	
    FILE *f = NULL;
    f = fopen("map.txt", "r");
    if(f == NULL)
    {
        printf("file empty");
        return false;
    }
    char c;
    int i = 0;
    int j = 0;
	
	*(map + i) = malloc(sizeof(char *) * mY);	
	for(i = 0; i < mX; i++)
		{
		*(map + i) = malloc(sizeof(char *) * mY);	
			for(j = 0; j < mY; j++)
			{		
				c = fgetc(f);
				*(*(map + i) + j) = c;
			}
			fgetc(f);
		}

	    fclose(f);
		
	    printf("\n");

		for(i = 0; i < mX; i++)
		{
			for(j = 0; j < mY; j++)
			{
				printf("%c", map[i][j]);
			}
			printf("\n");
		}
				
		
 return true;
 }		

