#include <iostream>
#include "game.h"
#include <stdlib.h>
#include <math.h>
#include <string>
//using namespace std;
enum mode {menu,game,gameOver,unknown};
mode m;

GLdouble width, height;
int wd;


const int interval = 500;
const int block_size = 20;
const int column_count = 20;
const int row_count = 20;
const int init_pos[2] = {3, 0};

const int tetrominos[7][4][4] = {
        {       {0, 0, 0, 0},
                {0, 1, 0, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}},

        {       {0, 0, 0, 0},
                {0, 1, 1, 0},
                {0, 0, 0, 0},
                {0, 0, 0, 0}},

        {       {0, 0, 0, 0},
                {0, 1, 1, 0},
                {0, 0, 1, 0},
                {0, 0, 0, 0}},

        {       {0, 0, 0, 0},
                {0, 1, 1, 1},
                {0, 0, 0, 0},
                {0, 0, 0, 0}},

        {       {0, 0, 0, 0},
                {0, 1, 1, 0},
                {0, 1, 1, 0},
                {0, 0, 0, 0}},

        {       {0, 0, 0, 0},
                {0, 0, 1, 0},
                {0, 1, 1, 1},
                {0, 0, 0, 0}},

        {       {0, 0, 0, 0},
                {1, 1, 1, 1},
                {0, 0, 0, 0},
                {0, 0, 0, 0}},
};

int points = 0;
int curr_block[4][4] = {};
int curr_pos[2] = {};
int blocks[column_count][row_count] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

void init_curr_block() {
    memcpy(curr_block, tetrominos[rand() % 7], 4 * 4 * sizeof(int));
    curr_pos[0] = init_pos[0];
    curr_pos[1] = init_pos[1];
}

void init() {
    // Set "clearing" or background color
    glClearColor(0.961f, 0.961f, 0.961f, 1.0f); // Black and opaque
    width = 1000;
    height = 1000;
    init_curr_block();
}



void displayMenu(){
    // draw words


     std::string message = "Blokus!";
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2i(400, 500);
    for (char c : message) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
    std::string message2 = "by: The Blok-Boys";
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
    
        /*glBegin(GL_LINES);
        glColor3f(1.0f, 0.0f, 0.0f); // Red (RGB)
        for (float x = 0; x < 600; x += 30) {
            glVertex3f(x, 0.0f, 0.0f);
            glVertex3f(x, float(600), 0.0f);
        }
        for (float y = 0; y < 600; y += 30) {
            glVertex3f(0.0f, y, 0.0f);
            glVertex3f(float(600), y, 0.0f);
        }
        glEnd();*/

    glBegin(GL_QUADS);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (curr_block[i][j]) {
                glColor3f(0,1,0);
                glVertex2f(curr_pos[0] + j, column_count - (curr_pos[1] + i));
                glVertex2f(curr_pos[0] + j, column_count - (curr_pos[1] + i + 1));
                glVertex2f(curr_pos[0] + j + 1, column_count - (curr_pos[1] + i + 1));
                glVertex2f(curr_pos[0] + j + 1, column_count - (curr_pos[1] + i));

            }
        }
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

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glLoadIdentity();
    gluOrtho2D(0, width, 0, height);
}

bool is_empty(int next_x, int next_y) {
    if (next_x < 0 || row_count <= next_x) {
        return false;
    }
    if (next_y < 0 || column_count <= next_y) {
        return false;
    }
    if (blocks[next_y][next_x]) {
        return false;
    }
    return true;
}

bool move(int x, int y) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (curr_block[i][j]) {
                int next_x = curr_pos[0] + j + x;
                int next_y = curr_pos[1] + i + y;
                if (!is_empty(next_x, next_y)) {
                    return false;
                }
            }
        }
    }
    curr_pos[0] += x;
    curr_pos[1] += y;
    glutPostRedisplay();
    return true;
}

void rotate() {
    int tmp[4][4] = {};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (curr_block[i][j]) {
                int next_x = curr_pos[0] + i;
                int next_y = curr_pos[1] + 4 - j;
                if (!is_empty(next_x, next_y)) {
                    return;
                }
                tmp[4 - j][i] = 1;
            }
        }
    }
    memcpy(curr_block, tmp, 4 * 4 * sizeof(int));
    glutPostRedisplay();
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
        rotate();
    }

    glutPostRedisplay();

    return;
}

void kbdS(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            move(-1, 0);
            break;
        case GLUT_KEY_RIGHT:
            move(1, 0);
            break;
        case GLUT_KEY_UP:
            move(0,1);
            break;
        case GLUT_KEY_DOWN:
            move(0, -1);
            break;
    }
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
    //glutInitWindowSize(block_size * row_count, block_size * column_count);
    glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Blokus!!!" /* title */ );
    init();
    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
   // glutReshapeFunc(reshape);
    // Our own OpenGL initialization


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