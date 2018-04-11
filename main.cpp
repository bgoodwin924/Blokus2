#include <iostream>
#include "game.h"
#include <math.h>
#include <string>
using namespace std;
enum mode {menu,game,gameOver,unknown};
mode m;

GLdouble width, height;
int wd;

void init() {
    width = 1000;
    height = 1000;
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.961f, 0.961f, 0.961f, 1.0f); // Black and opaque
}

void displayMenu(){
    // draw words


    string message = "Blokus!";
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2i(400, 500);
    for (char c : message) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
    string message2 = "by: The Blok-Boys";
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2i(400, 550);
    for (char c : message2) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
}
void displayGame()
{
        // tell OpenGL to use the whole window for drawing
        glViewport(0, 0, width, height);

        // do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

        glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

        glBegin(GL_LINES);
        glColor3f(1.0f, 0.0f, 0.0f); // Red (RGB)
        for (float x = 0; x < 600; x += 30) {
            glVertex3f(x, 0.0f, 0.0f);
            glVertex3f(x, float(600), 0.0f);
        }
        for (float y = 0; y < 600; y += 30) {
            glVertex3f(0.0f, y, 0.0f);
            glVertex3f(float(600), y, 0.0f);
        }
        glEnd();
        glFlush();
}

void displayEnd(){

}
/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {

        // tell OpenGL to use the whole window for drawing
        glViewport(0, 0, width, height);

        // do an orthographic parallel projection with the coordinate
        // system set to first quadrant, limited by screen/window size
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

        glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

        /*
         * Draw here
         */
        switch(m) {
            case menu: displayMenu();
                break;
            case game: displayGame();
                break;
            case gameOver: displayEnd();
                break;
    }


    glFlush();  // Render now

}

// http://www.theasciicode.com.ar/ascii-control-characters/escape-ascii-code-27.html
void kbd(unsigned char key, int x, int y)
{
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }
    //spacebar
    if(key ==32){
        glClearColor(0.0f, 0.0f, 1.0f,0.0f);
    }

    glutPostRedisplay();

    return;
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:

            break;
        case GLUT_KEY_LEFT:

            break;
        case GLUT_KEY_RIGHT:

            break;
        case GLUT_KEY_UP:

            break;
    }

    glutPostRedisplay();

    return;
}

void cursor(int x, int y) {


    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        m=game;
    }


    glutPostRedisplay();
}

void timer(int extra) {

    glutPostRedisplay();
    glutTimerFunc(30, timer, 0);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

    init();

    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    glutInitWindowSize((int)width, (int)height);
    glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Blokus!!!" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

    // Our own OpenGL initialization
    initGL();

    // register keyboard press event processing function
    // works for numbers, letters, spacebar, etc.
    glutKeyboardFunc(kbd);

    // register special event: function keys, arrows, etc.
    glutSpecialFunc(kbdS);

    // handles mouse movement
    glutPassiveMotionFunc(cursor);

    // handles mouse click
    glutMouseFunc(mouse);

    // handles timer
    glutTimerFunc(0, timer, 0);

    // Enter the event-processing loop
    glutMainLoop();
    return 0;
}