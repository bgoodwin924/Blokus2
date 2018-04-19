#include <iostream>
#include "Blokus.h"
#include <stdlib.h>
#include <math.h>
#include <string>
#include <sstream>
//using namespace std;
enum mode {menu,game,gameOver,unknown};
mode m;

GLdouble width, height;
int wd;


const int interval = 500;
int points = 0;
Shape s;
Board b;

void init() {
    glClearColor(1, 1, 1, 0);
    glColor3f(0, 0, 0);
    //srand(time(NULL));
    s.init_curr_block();
}



void displayMenu(){
    // draw words


    std::string message = "Blokus!";
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2i(0, 0);
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
    //glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    //glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

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
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    for (int i = 0; i < b.column_count; i++) {
        for (int j = 0; j < b.row_count; j++) {
            if (b.blocks[i][j]) {
                glVertex2f(j, b.column_count - i);
                glVertex2f(j, b.column_count - i - 1);
                glVertex2f(j + 1, b.column_count - i - 1);
                glVertex2f(j + 1, b.column_count - i);
            }
        }
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (s.curr_block[i][j]) {
                //glColor3f(0,1,0);
                glVertex2f(s.curr_pos[0] + j, b.column_count - (s.curr_pos[1] + i));
                glVertex2f(s.curr_pos[0] + j, b.column_count - (s.curr_pos[1] + i + 1));
                glVertex2f(s.curr_pos[0] + j + 1, b.column_count - (s.curr_pos[1] + i + 1));
                glVertex2f(s.curr_pos[0] + j + 1, b.column_count - (s.curr_pos[1] + i));

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
    //glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    //glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    //glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

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
    gluOrtho2D(0, width / s.block_size, 0, height / s.block_size);
}

bool isempty(int next_x, int next_y) {
    if (next_x < 0 || b.row_count <= next_x) {
        return false;
    }
    if (next_y < 0 || b.column_count <= next_y) {
        return false;
    }
    if (b.blocks[next_y][next_x]) {
        return false;
    }
    return true;
}

bool move(int x, int y) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (s.curr_block[i][j]) {
                int next_x = s.curr_pos[0] + j + x;
                int next_y = s.curr_pos[1] + i + y;
                if (!isempty(next_x, next_y)) {
                    return false;
                }
            }
        }
    }
    s.curr_pos[0] += x;
    s.curr_pos[1] += y;
    glutPostRedisplay();
    return true;
}

void rotate() {
    int tmp[4][4] = {};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (s.curr_block[i][j]) {
                int next_x = s.curr_pos[0] + i;
                int next_y = s.curr_pos[1] + 4 - j;
                if (!isempty(next_x, next_y)) {
                    return;
                }
                tmp[4 - j][i] = 1;
            }
        }
    }
    memcpy(s.curr_block, tmp, 4 * 4 * sizeof(int));
    glutPostRedisplay();
}

void timer(int value);

void flush(int value);

void shift(int value);

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
            move(0,-1);
            break;
        case GLUT_KEY_DOWN:
            move(0, 1);
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

void timer(int value) {
    /* if (!move(0, 1)) {
         for (int i = 0; i < 4; i++) {
             for (int j = 0; j < 4; j++) {
                 if (curr_block[i][j]) {
                     blocks[curr_pos[1] + i][curr_pos[0] + j] = 1;
                 }
             }
         }
         memset(curr_block, 0, 4 * 4 * sizeof(int));
         curr_pos[0] = 0;
         curr_pos[1] = 0;
         flush(0);
         return;
     }*/
    glutTimerFunc(interval, timer, 0);
}

void throw_new_block() {
    s.init_curr_block();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (s.curr_block[i][j] && b.blocks[s.curr_pos[1] + i][s.curr_pos[0] + j]) {
                //game_over();
                return;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(interval, timer, 0);
}

void flush(int value) {
    for (int i = b.column_count - 1; i >= 0; i--) {
        int j;
        for (j = 0; j < b.row_count; j++) {
            if (!b.blocks[i][j]) {
                break;
            }
        }
        if (j == b.row_count) {
            std::ostringstream os;
            os << "Score: " << ++points * 10 << " points";
            glutSetWindowTitle(os.str().c_str());
            memset(b.blocks[i], 0, b.row_count * sizeof(int));
            glutPostRedisplay();
            glutTimerFunc(interval, shift, i);
            return;
        }
    }
    throw_new_block();
}

void shift(int y) {
    for (int i = y; i >= 1; i--) {
        for (int j = 0; j < b.row_count; j++) {
            b.blocks[i][j] = b.blocks[i - 1][j];
        }
    }
    glutPostRedisplay();
    glutTimerFunc(interval, flush, 0);
}
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {



    glutInit(&argc, argv);          // Initialize GLUT

    glutInitDisplayMode(GLUT_RGBA);

    //glutInitWindowSize((int)width, (int)height);
    glutInitWindowSize((s.block_size * b.row_count)+500, (s.block_size * b.column_count)+500);
    glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Blokus!!!" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
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
    glutTimerFunc(interval, timer, 0);

    // Enter the event-processing loop
    init();
    glutMainLoop();
    return 0;
}