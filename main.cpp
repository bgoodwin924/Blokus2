#include <iostream>
#include <cmath>
#include "Blokus.h"

//using namespace std;
enum mode {menu,game,gameOver,unknown};
mode m=menu;

GLdouble width, height;
int wd;


const int interval = 500;
int points = 0;
int mouseX;
int mouseY;
bool hidden;

Shape s1; //inventory
Shape s2; //player piece
Board b;
Player p1(red);
Player p2(blue);

void init() {
    glClearColor(1, 1, 1, 0);
    glColor3f(0, 0, 0);
    srand(time(NULL));
    s2.init_curr_block(0);

}

void displayMenu(){
    // draw words
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.847f, 0.749f, 0.847f ,0.0f);

    std::string message = "Blokus!";
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2i(15, 10);
    for (char c : message) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
    std::string message2 = "by: The Blok-Boys";
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2i(13, 8);
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
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    //glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color


    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.847f, 0.749f, 0.847f ,0.0f);

    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i)-2);
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i + 1)-2);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i + 1)-2);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i)-2);
        }
    }

    //glClear(GL_COLOR_BUFFER_BIT);
    s1.init_curr_block(0);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i)-2);
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i + 1)-2);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i + 1)-2);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i)-2);
        }
    }

    glEnd();
    s1.init_curr_block(1);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i)-4);
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i + 1)-4);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i + 1)-4);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i)-4);
        }
    }

    glEnd();
    s1.init_curr_block(2);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i)-6);
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i + 1)-6);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i + 1)-6);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i)-6);
        }
    }

    glEnd();
    s1.init_curr_block(3);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i)-9);
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i + 1)-9);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i + 1)-9);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i)-9);
        }
    }

    glEnd();
    s1.init_curr_block(4);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i)-11);
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i + 1)-11);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i + 1)-11);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i)-11);
        }
    }

    glEnd();
    s1.init_curr_block(4);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i)-11);
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i + 1)-11);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i + 1)-11);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i)-11);
        }
    }

    glEnd();
    s1.init_curr_block(5);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i)-14);
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i + 1)-14);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i + 1)-14);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i)-14);
        }
    }

    glEnd();
    s1.init_curr_block(6);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i)-17);
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i + 1)-17);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i + 1)-17);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i)-17);
        }
    }

    glEnd();
    s1.init_curr_block(7);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+24, b.column_count - (s1.curr_pos[1] + i)-1);
            glVertex2f(s1.curr_pos[0] + j+24, b.column_count - (s1.curr_pos[1] + i + 1)-1);
            glVertex2f(s1.curr_pos[0] + j + 1+24, b.column_count - (s1.curr_pos[1] + i + 1)-1);
            glVertex2f(s1.curr_pos[0] + j + 1+24, b.column_count - (s1.curr_pos[1] + i)-1);
        }
    }

    glEnd();
    s1.init_curr_block(8);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+24, b.column_count - (s1.curr_pos[1] + i)-4);
            glVertex2f(s1.curr_pos[0] + j+24, b.column_count - (s1.curr_pos[1] + i + 1)-4);
            glVertex2f(s1.curr_pos[0] + j + 1+24, b.column_count - (s1.curr_pos[1] + i + 1)-4);
            glVertex2f(s1.curr_pos[0] + j + 1+24, b.column_count - (s1.curr_pos[1] + i)-4);
        }
    }

    glEnd();
    s1.init_curr_block(9);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+24, b.column_count - (s1.curr_pos[1] + i)-7);
            glVertex2f(s1.curr_pos[0] + j+24, b.column_count - (s1.curr_pos[1] + i + 1)-7);
            glVertex2f(s1.curr_pos[0] + j + 1+24, b.column_count - (s1.curr_pos[1] + i + 1)-7);
            glVertex2f(s1.curr_pos[0] + j + 1+24, b.column_count - (s1.curr_pos[1] + i)-7);
        }
    }

    glEnd();
    s1.init_curr_block(10);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+24, b.column_count - (s1.curr_pos[1] + i)-10);
            glVertex2f(s1.curr_pos[0] + j+24, b.column_count - (s1.curr_pos[1] + i + 1)-10);
            glVertex2f(s1.curr_pos[0] + j + 1+24, b.column_count - (s1.curr_pos[1] + i + 1)-10);
            glVertex2f(s1.curr_pos[0] + j + 1+24, b.column_count - (s1.curr_pos[1] + i)-10);
        }
    }

    glEnd();
    s1.init_curr_block(11);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+24, b.column_count - (s1.curr_pos[1] + i)-14);
            glVertex2f(s1.curr_pos[0] + j+24, b.column_count - (s1.curr_pos[1] + i + 1)-14);
            glVertex2f(s1.curr_pos[0] + j + 1+24, b.column_count - (s1.curr_pos[1] + i + 1)-14);
            glVertex2f(s1.curr_pos[0] + j + 1+24, b.column_count - (s1.curr_pos[1] + i)-14);
        }
    }

    glEnd();
    s1.init_curr_block(12);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+28, b.column_count - (s1.curr_pos[1] + i));
            glVertex2f(s1.curr_pos[0] + j+28, b.column_count - (s1.curr_pos[1] + i + 1));
            glVertex2f(s1.curr_pos[0] + j + 1+28, b.column_count - (s1.curr_pos[1] + i + 1));
            glVertex2f(s1.curr_pos[0] + j + 1+28, b.column_count - (s1.curr_pos[1] + i));
        }
    }

    glEnd();
    s1.init_curr_block(13);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+28, b.column_count - (s1.curr_pos[1] + i)-4);
            glVertex2f(s1.curr_pos[0] + j+28, b.column_count - (s1.curr_pos[1] + i + 1)-4);
            glVertex2f(s1.curr_pos[0] + j + 1+28, b.column_count - (s1.curr_pos[1] + i + 1)-4);
            glVertex2f(s1.curr_pos[0] + j + 1+28, b.column_count - (s1.curr_pos[1] + i)-4);
        }
    }

    glEnd();

    s1.init_curr_block(15);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+30, b.column_count - (s1.curr_pos[1] + i)-7);
            glVertex2f(s1.curr_pos[0] + j+30, b.column_count - (s1.curr_pos[1] + i + 1)-7);
            glVertex2f(s1.curr_pos[0] + j + 1+30, b.column_count - (s1.curr_pos[1] + i + 1)-7);
            glVertex2f(s1.curr_pos[0] + j + 1+30, b.column_count - (s1.curr_pos[1] + i)-7);
        }
    }

    glEnd();

    s1.init_curr_block(16);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+28, b.column_count - (s1.curr_pos[1] + i)-12);
            glVertex2f(s1.curr_pos[0] + j+28, b.column_count - (s1.curr_pos[1] + i + 1)-12);
            glVertex2f(s1.curr_pos[0] + j + 1+28, b.column_count - (s1.curr_pos[1] + i + 1)-12);
            glVertex2f(s1.curr_pos[0] + j + 1+28, b.column_count - (s1.curr_pos[1] + i)-12);
        }
    }

    glEnd();

    s1.init_curr_block(17);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+28, b.column_count - (s1.curr_pos[1] + i)-16);
            glVertex2f(s1.curr_pos[0] + j+28, b.column_count - (s1.curr_pos[1] + i + 1)-16);
            glVertex2f(s1.curr_pos[0] + j + 1+28, b.column_count - (s1.curr_pos[1] + i + 1)-16);
            glVertex2f(s1.curr_pos[0] + j + 1+28, b.column_count - (s1.curr_pos[1] + i)-16);
        }
    }

    glEnd();

    s1.init_curr_block(18);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+33, b.column_count - (s1.curr_pos[1] + i)-1);
            glVertex2f(s1.curr_pos[0] + j+33, b.column_count - (s1.curr_pos[1] + i + 1)-1);
            glVertex2f(s1.curr_pos[0] + j + 1+33, b.column_count - (s1.curr_pos[1] + i + 1)-1);
            glVertex2f(s1.curr_pos[0] + j + 1+33, b.column_count - (s1.curr_pos[1] + i)-1);
        }
    }

    glEnd();
    s1.init_curr_block(19);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+33, b.column_count - (s1.curr_pos[1] + i)-5);
            glVertex2f(s1.curr_pos[0] + j+33, b.column_count - (s1.curr_pos[1] + i + 1)-5);
            glVertex2f(s1.curr_pos[0] + j + 1+33, b.column_count - (s1.curr_pos[1] + i + 1)-5);
            glVertex2f(s1.curr_pos[0] + j + 1+33, b.column_count - (s1.curr_pos[1] + i)-5);
        }
    }

    glEnd();
    s1.init_curr_block(20);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+33, b.column_count - (s1.curr_pos[1] + i)-9);
            glVertex2f(s1.curr_pos[0] + j+33, b.column_count - (s1.curr_pos[1] + i + 1)-9);
            glVertex2f(s1.curr_pos[0] + j + 1+33, b.column_count - (s1.curr_pos[1] + i + 1)-9);
            glVertex2f(s1.curr_pos[0] + j + 1+33, b.column_count - (s1.curr_pos[1] + i)-9);
        }
    }

    glEnd();
    s1.init_curr_block(14);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p1.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p1.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p1.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p1.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+32, b.column_count - (s1.curr_pos[1] + i)-13);
            glVertex2f(s1.curr_pos[0] + j+32, b.column_count - (s1.curr_pos[1] + i + 1)-13);
            glVertex2f(s1.curr_pos[0] + j + 1+32, b.column_count - (s1.curr_pos[1] + i + 1)-13);
            glVertex2f(s1.curr_pos[0] + j + 1+32, b.column_count - (s1.curr_pos[1] + i)-13);
        }
    }

    glEnd();

    //Player 2 Inventory
    s1.init_curr_block(0);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+40, b.column_count - (s1.curr_pos[1] + i)-2);
            glVertex2f(s1.curr_pos[0] + j+40, b.column_count - (s1.curr_pos[1] + i + 1)-2);
            glVertex2f(s1.curr_pos[0] + j + 1+40, b.column_count - (s1.curr_pos[1] + i + 1)-2);
            glVertex2f(s1.curr_pos[0] + j + 1+40, b.column_count - (s1.curr_pos[1] + i)-2);
        }
    }

    glEnd();
    s1.init_curr_block(1);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+40, b.column_count - (s1.curr_pos[1] + i)-4);
            glVertex2f(s1.curr_pos[0] + j+40, b.column_count - (s1.curr_pos[1] + i + 1)-4);
            glVertex2f(s1.curr_pos[0] + j + 1+40, b.column_count - (s1.curr_pos[1] + i + 1)-4);
            glVertex2f(s1.curr_pos[0] + j + 1+40, b.column_count - (s1.curr_pos[1] + i)-4);
        }
    }

    glEnd();
    s1.init_curr_block(2);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+40, b.column_count - (s1.curr_pos[1] + i)-6);
            glVertex2f(s1.curr_pos[0] + j+40, b.column_count - (s1.curr_pos[1] + i + 1)-6);
            glVertex2f(s1.curr_pos[0] + j + 1+40, b.column_count - (s1.curr_pos[1] + i + 1)-6);
            glVertex2f(s1.curr_pos[0] + j + 1+40, b.column_count - (s1.curr_pos[1] + i)-6);
        }
    }

    glEnd();
    s1.init_curr_block(3);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+40, b.column_count - (s1.curr_pos[1] + i)-9);
            glVertex2f(s1.curr_pos[0] + j+40, b.column_count - (s1.curr_pos[1] + i + 1)-9);
            glVertex2f(s1.curr_pos[0] + j + 1+40, b.column_count - (s1.curr_pos[1] + i + 1)-9);
            glVertex2f(s1.curr_pos[0] + j + 1+40, b.column_count - (s1.curr_pos[1] + i)-9);
        }
    }

    glEnd();
    s1.init_curr_block(4);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+40, b.column_count - (s1.curr_pos[1] + i)-11);
            glVertex2f(s1.curr_pos[0] + j+40, b.column_count - (s1.curr_pos[1] + i + 1)-11);
            glVertex2f(s1.curr_pos[0] + j + 1+40, b.column_count - (s1.curr_pos[1] + i + 1)-11);
            glVertex2f(s1.curr_pos[0] + j + 1+40, b.column_count - (s1.curr_pos[1] + i)-11);
        }
    }

    glEnd();
    s1.init_curr_block(4);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+40, b.column_count - (s1.curr_pos[1] + i)-11);
            glVertex2f(s1.curr_pos[0] + j+40, b.column_count - (s1.curr_pos[1] + i + 1)-11);
            glVertex2f(s1.curr_pos[0] + j + 1+40, b.column_count - (s1.curr_pos[1] + i + 1)-11);
            glVertex2f(s1.curr_pos[0] + j + 1+40, b.column_count - (s1.curr_pos[1] + i)-11);
        }
    }

    glEnd();
    s1.init_curr_block(5);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+40, b.column_count - (s1.curr_pos[1] + i)-14);
            glVertex2f(s1.curr_pos[0] + j+40, b.column_count - (s1.curr_pos[1] + i + 1)-14);
            glVertex2f(s1.curr_pos[0] + j + 1+40, b.column_count - (s1.curr_pos[1] + i + 1)-14);
            glVertex2f(s1.curr_pos[0] + j + 1+40, b.column_count - (s1.curr_pos[1] + i)-14);
        }
    }

    glEnd();
    s1.init_curr_block(6);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+40, b.column_count - (s1.curr_pos[1] + i)-17);
            glVertex2f(s1.curr_pos[0] + j+40, b.column_count - (s1.curr_pos[1] + i + 1)-17);
            glVertex2f(s1.curr_pos[0] + j + 1+40, b.column_count - (s1.curr_pos[1] + i + 1)-17);
            glVertex2f(s1.curr_pos[0] + j + 1+40, b.column_count - (s1.curr_pos[1] + i)-17);
        }
    }

    glEnd();
    s1.init_curr_block(7);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+44, b.column_count - (s1.curr_pos[1] + i)-1);
            glVertex2f(s1.curr_pos[0] + j+44, b.column_count - (s1.curr_pos[1] + i + 1)-1);
            glVertex2f(s1.curr_pos[0] + j + 1+44, b.column_count - (s1.curr_pos[1] + i + 1)-1);
            glVertex2f(s1.curr_pos[0] + j + 1+44, b.column_count - (s1.curr_pos[1] + i)-1);
        }
    }

    glEnd();
    s1.init_curr_block(8);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+44, b.column_count - (s1.curr_pos[1] + i)-4);
            glVertex2f(s1.curr_pos[0] + j+44, b.column_count - (s1.curr_pos[1] + i + 1)-4);
            glVertex2f(s1.curr_pos[0] + j + 1+44, b.column_count - (s1.curr_pos[1] + i + 1)-4);
            glVertex2f(s1.curr_pos[0] + j + 1+44, b.column_count - (s1.curr_pos[1] + i)-4);
        }
    }

    glEnd();
    s1.init_curr_block(9);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+44, b.column_count - (s1.curr_pos[1] + i)-7);
            glVertex2f(s1.curr_pos[0] + j+44, b.column_count - (s1.curr_pos[1] + i + 1)-7);
            glVertex2f(s1.curr_pos[0] + j + 1+44, b.column_count - (s1.curr_pos[1] + i + 1)-7);
            glVertex2f(s1.curr_pos[0] + j + 1+44, b.column_count - (s1.curr_pos[1] + i)-7);
        }
    }

    glEnd();
    s1.init_curr_block(10);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+44, b.column_count - (s1.curr_pos[1] + i)-10);
            glVertex2f(s1.curr_pos[0] + j+44, b.column_count - (s1.curr_pos[1] + i + 1)-10);
            glVertex2f(s1.curr_pos[0] + j + 1+44, b.column_count - (s1.curr_pos[1] + i + 1)-10);
            glVertex2f(s1.curr_pos[0] + j + 1+44, b.column_count - (s1.curr_pos[1] + i)-10);
        }
    }

    glEnd();
    s1.init_curr_block(11);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+44, b.column_count - (s1.curr_pos[1] + i)-14);
            glVertex2f(s1.curr_pos[0] + j+44, b.column_count - (s1.curr_pos[1] + i + 1)-14);
            glVertex2f(s1.curr_pos[0] + j + 1+44, b.column_count - (s1.curr_pos[1] + i + 1)-14);
            glVertex2f(s1.curr_pos[0] + j + 1+44, b.column_count - (s1.curr_pos[1] + i)-14);
        }
    }

    glEnd();
    s1.init_curr_block(12);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+48, b.column_count - (s1.curr_pos[1] + i));
            glVertex2f(s1.curr_pos[0] + j+48, b.column_count - (s1.curr_pos[1] + i + 1));
            glVertex2f(s1.curr_pos[0] + j + 1+48, b.column_count - (s1.curr_pos[1] + i + 1));
            glVertex2f(s1.curr_pos[0] + j + 1+48, b.column_count - (s1.curr_pos[1] + i));
        }
    }

    glEnd();
    s1.init_curr_block(13);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+48, b.column_count - (s1.curr_pos[1] + i)-4);
            glVertex2f(s1.curr_pos[0] + j+48, b.column_count - (s1.curr_pos[1] + i + 1)-4);
            glVertex2f(s1.curr_pos[0] + j + 1+48, b.column_count - (s1.curr_pos[1] + i + 1)-4);
            glVertex2f(s1.curr_pos[0] + j + 1+48, b.column_count - (s1.curr_pos[1] + i)-4);
        }
    }

    glEnd();

    s1.init_curr_block(15);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+50, b.column_count - (s1.curr_pos[1] + i)-7);
            glVertex2f(s1.curr_pos[0] + j+50, b.column_count - (s1.curr_pos[1] + i + 1)-7);
            glVertex2f(s1.curr_pos[0] + j + 1+50, b.column_count - (s1.curr_pos[1] + i + 1)-7);
            glVertex2f(s1.curr_pos[0] + j + 1+50, b.column_count - (s1.curr_pos[1] + i)-7);
        }
    }

    glEnd();

    s1.init_curr_block(16);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+48, b.column_count - (s1.curr_pos[1] + i)-12);
            glVertex2f(s1.curr_pos[0] + j+48, b.column_count - (s1.curr_pos[1] + i + 1)-12);
            glVertex2f(s1.curr_pos[0] + j + 1+48, b.column_count - (s1.curr_pos[1] + i + 1)-12);
            glVertex2f(s1.curr_pos[0] + j + 1+48, b.column_count - (s1.curr_pos[1] + i)-12);
        }
    }

    glEnd();

    s1.init_curr_block(17);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+48, b.column_count - (s1.curr_pos[1] + i)-16);
            glVertex2f(s1.curr_pos[0] + j+48, b.column_count - (s1.curr_pos[1] + i + 1)-16);
            glVertex2f(s1.curr_pos[0] + j + 1+48, b.column_count - (s1.curr_pos[1] + i + 1)-16);
            glVertex2f(s1.curr_pos[0] + j + 1+48, b.column_count - (s1.curr_pos[1] + i)-16);
        }
    }

    glEnd();

    s1.init_curr_block(18);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+53, b.column_count - (s1.curr_pos[1] + i)-1);
            glVertex2f(s1.curr_pos[0] + j+53, b.column_count - (s1.curr_pos[1] + i + 1)-1);
            glVertex2f(s1.curr_pos[0] + j + 1+53, b.column_count - (s1.curr_pos[1] + i + 1)-1);
            glVertex2f(s1.curr_pos[0] + j + 1+53, b.column_count - (s1.curr_pos[1] + i)-1);
        }
    }

    glEnd();
    s1.init_curr_block(19);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+53, b.column_count - (s1.curr_pos[1] + i)-5);
            glVertex2f(s1.curr_pos[0] + j+53, b.column_count - (s1.curr_pos[1] + i + 1)-5);
            glVertex2f(s1.curr_pos[0] + j + 1+53, b.column_count - (s1.curr_pos[1] + i + 1)-5);
            glVertex2f(s1.curr_pos[0] + j + 1+53, b.column_count - (s1.curr_pos[1] + i)-5);
        }
    }

    glEnd();
    s1.init_curr_block(20);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+53, b.column_count - (s1.curr_pos[1] + i)-9);
            glVertex2f(s1.curr_pos[0] + j+53, b.column_count - (s1.curr_pos[1] + i + 1)-9);
            glVertex2f(s1.curr_pos[0] + j + 1+53, b.column_count - (s1.curr_pos[1] + i + 1)-9);
            glVertex2f(s1.curr_pos[0] + j + 1+53, b.column_count - (s1.curr_pos[1] + i)-9);
        }
    }

    glEnd();
    s1.init_curr_block(14);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p2.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p2.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p2.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p2.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+52, b.column_count - (s1.curr_pos[1] + i)-13);
            glVertex2f(s1.curr_pos[0] + j+52, b.column_count - (s1.curr_pos[1] + i + 1)-13);
            glVertex2f(s1.curr_pos[0] + j + 1+52, b.column_count - (s1.curr_pos[1] + i + 1)-13);
            glVertex2f(s1.curr_pos[0] + j + 1+52, b.column_count - (s1.curr_pos[1] + i)-13);
        }
    }

    glEnd();




    s2.draw(p1.pieceColor,b);

    b.DrawBoard();
    //Create Player Area
    std::string message = "Player 1's Pieces!";
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2i(24, 18);
    for (char c : message) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

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
    gluOrtho2D(0, width / s1.block_size, 0, height / s1.block_size);
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
    //r key
    if(key ==114){
        s2.rotate(b);
    }
    //spacebar
    if(key ==32){
        /*function to place block goes here*/
        flush(0);
        s2.throw_new_block(b);
    }

    glutPostRedisplay();

}

void kbdS(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_LEFT:
            s2.move(b,-1, 0);
            break;
        case GLUT_KEY_RIGHT:
            s2.move(b,1, 0);
            break;
        case GLUT_KEY_UP:
            s2.move(b,0,-1);
            break;
        case GLUT_KEY_DOWN:
            s2.move(b,0, 1);
            break;
    }
}

void cursor(int x, int y) {
    cout<<x<<','<<y<<endl;
    mouseX=x;
    mouseY=y;
    s1.isInShape(x,y, b, s1);


    glutPostRedisplay();
}

// button will be GLUT_LEFT_BUTTON or GLUT_RIGHT_BUTTON
// state will be GLUT_UP or GLUT_DOWN
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && m == menu) {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        m = game;
    }

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN && m == game) {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
        m = menu;
        glutPostRedisplay();
    }
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
    s2.throw_new_block(b);
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
    glutInitWindowSize((s2.block_size * b.row_count)+850, (s2.block_size * b.column_count));
    glutInitWindowPosition(500, 300); // Position the window's initial top-left corner
    /* create the window and store the handle to it */
    wd = glutCreateWindow("Blokus!!!" /* title */ );

    // Register callback handler for window re-paint event
    glutDisplayFunc(display);

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
    glutReshapeFunc(reshape);
    init();
    glutMainLoop();
    return 0;
}
