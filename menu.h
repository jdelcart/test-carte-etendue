#include <stdio.h>
#include <stdlib.h>
#include <GLUT/glut.h> // This includes the GLUT library on MacOS
//Contrôler l'efficience: code ChatGPT
// Global variable to keep track of the menu state

// Function prototypes
void display();
void menu(int option);
void drawMenu();
void handleMouse(int button, int state, int x, int y);
void affichage_texte(void* police, const char* chaine);
void creation_menu(void);
