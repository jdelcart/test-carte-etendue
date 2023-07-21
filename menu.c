#include <stdio.h>
#include <stdlib.h>
#include <GLUT/glut.h>
#include "menu.h"
#include "drawMap.h"
#include "game.h"
//Contrôler l'efficience: code ChatGPT
// Global variable to keep track of the menu state
int menuIsOpen=0;
/*int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Exemple de menu pour SOS");
    creation_menu();
    glutDisplayFunc(display);
    glutMouseFunc(handleMouse);
    glutMainLoop();

    return 0;
}*/
void creation_menu(){
    // Create a menu and specify the menu callback function
    glutCreateMenu(menu);
    glutAddMenuEntry("Continuer la partie en cours", 1);
    glutAddMenuEntry("Nouvelle partie", 2);
    glutAddMenuEntry("Configuration de la partie", 3);
    glutAddMenuEntry("Lire les règles", 4);
    glutAddMenuEntry("Tableau des records", 5);
    glutAddMenuEntry("Quitter le jeu", 6);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
void affichage_texte(void* police, const char* chaine){
    const char* c;
    for(c = chaine; *c!='\0';c++){
        glutBitmapCharacter(police, *c);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    if (menuIsOpen) {
        drawMenu();
    }

    glFlush();
}

void drawMenu() {
    // Set up the orthographic view to draw the menu
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 800, 0, 600);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    // Draw a simple menu background (you can customize this part)
    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_QUADS);
    glVertex2i(200, 200);
    glVertex2i(600, 200);
    glVertex2i(600, 400);
    glVertex2i(200, 400);
    glEnd();

    // Draw menu options (you can customize this part)
    glRasterPos2i(300, 350);
    glColor3f(1.0f, 1.0f, 1.0f);
    affichage_texte(GLUT_BITMAP_HELVETICA_18, "Continuer la partie");

    glRasterPos2i(300, 300);
    affichage_texte(GLUT_BITMAP_HELVETICA_18, "Nouvelle partie");

    glRasterPos2i(300, 250);
    affichage_texte(GLUT_BITMAP_HELVETICA_18, "Configuration de la partie");

    glRasterPos2i(250, 350);
    affichage_texte(GLUT_BITMAP_HELVETICA_18, "Lire les règles");

    glRasterPos2i(250, 300);
    affichage_texte(GLUT_BITMAP_HELVETICA_18, "Tableau des records");

    glRasterPos2i(250, 250);
    affichage_texte(GLUT_BITMAP_HELVETICA_18, "Quitter le jeu");
}

void menu(int option) {
    switch (option) {
        case 1:
            // Add code for option 1 action
            printf("Reprise de la partie...\n");
            break;
        case 2:
            // Add code for option 2 action
            printf("Creation de la partie...\n");
            break;
        case 3:
            // Add code for option 3 action
            printf("Affichage des options de configuration...\n");
            break;
        case 4:
            // Add code for option 4 action
            printf("Affichage des règles...\n");
            break;
        case 5:
            // Add code for option 5 action
            printf("Affichage des records...\n");
            break;
        case 6:
            // Add code for option 6 action
            printf("Arrêt du programme.\n");
            break;
        default:
            break;
    }
}

void handleMouse(int button, int state, int x, int y) {
    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        menuIsOpen = 1;
        glutPostRedisplay(); // Request redrawing the window to show the menu
    } else if (state == GLUT_UP) {
        menuIsOpen = 0;
        glutPostRedisplay(); // Request redrawing the window to close the menu
    }
}
