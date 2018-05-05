#include <iostream>
#include <cmath>
#include "Blokus.h"

//using namespace std;
enum mode {menu,game,gameOver,unknown};
mode m=menu;

GLdouble widthGlobal, heightGlobal;
int wd;

const int interval = 500;
int points = 0;
int mouseX;
int mouseY;

Shape s1; //inventory
Shape s2; //player piece
Board b;
Player p1(red);
Player p2(blue);
Player p3(green);
Player p4(yellow);

void init() {
    glClearColor(1, 1, 1, 0);
    glColor3f(0, 0, 0);
    srand(time(NULL));
    s2.init_curr_block(0);

}

void displayMenu(){
    // draw words
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 0.0, 0.0, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.847f, 0.749f, 0.847f ,0.0f);
    p1.drawIntro(s1,p1,p2,p3,p4,b);



    std::string message = "Blokus!";
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2i(28, 10);
    for (char c : message) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
    std::string message2 = "by: The Blok-Boys";
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2i(25, 9);
    for (char c : message2) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
    std::string message3 = "Click to Begin";
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2i(26, 8);
    for (char c : message3) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, c);
    }
    glFlush();
}

void displayGame() {
    // tell OpenGL to use the whole window for drawing
    //glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 0.0, 0.0, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.847f, 0.749f, 0.847f, 0.0f);

    p1.drawInventory(s1, p1, p2, b);

    s2.draw(p1.pieceColor, b);

    b.DrawBoard();

    if (mouseX > 485 && mouseX < 505 && mouseY > 60 && mouseY < 80) {//red shape 1
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(24, 16);
        glVertex2i(24, 17);
        glVertex2i(25, 16);
        glVertex2i(25, 17);
// Horizontal lines
        glVertex2i(24, 16);
        glVertex2i(25, 16);
        glVertex2i(24, 17);
        glVertex2i(25, 17);
        glEnd();
        glFlush();

    } else if (mouseX > 485 && mouseX < 525 && mouseY > 100 && mouseY < 120) {//red shape 2
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(24, 14);
        glVertex2i(24, 15);
        glVertex2i(26, 14);
        glVertex2i(26, 15);
// Horizontal lines
        glVertex2i(24, 14);
        glVertex2i(26, 14);
        glVertex2i(24, 15);
        glVertex2i(26, 15);
        glEnd();
        glFlush();

    } else if (mouseX > 485 && mouseX < 525 && mouseY > 140 && mouseY < 180) {//red shape 3
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(24, 13);
        glVertex2i(26, 13);
        glVertex2i(26, 11);
        glVertex2i(25, 11);
        glVertex2i(24,13);
        glVertex2i(24,12);
// Horizontal lines
        glVertex2i(24,12);
        glVertex2i(25,12);
        glVertex2i(25,12);
        glVertex2i(25,11);
        glVertex2i(26,11);
        glVertex2i(26,13);
        glEnd();
        glFlush();

    } else if (mouseX > 485 && mouseX < 544 && mouseY > 160 && mouseY < 220) {//red shape 4
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(24, 9);
        glVertex2i(27, 9);
        glVertex2i(27, 10);
        glVertex2i(24, 10);
        glVertex2i(24, 9);
// Horizontal lines
        glVertex2i(24, 9);
        glVertex2i(27, 9);
        glVertex2i(27, 10);
        glVertex2i(24, 10);
        glVertex2i(24, 9);
        glEnd();
        glFlush();

    } else if (mouseX > 485 && mouseX < 525 && mouseY > 240 && mouseY < 280) {//red shape 5
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(24, 8);
        glVertex2i(26, 8);
        glVertex2i(26, 6);
        glVertex2i(24, 6);
// Horizontal lines
        glVertex2i(24, 8);
        glVertex2i(24, 6);
        glVertex2i(26,8);
        glVertex2i(26,6);
        glEnd();
        glFlush();

    } else if (mouseX > 485 && mouseX < 544 && mouseY > 300 && mouseY < 340) {//red shape 6
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(24, 3);
        glVertex2i(24, 3);
        glVertex2i(28, 4);
        glVertex2i(28, 4);
        glVertex2i(25,4);
        glVertex2i(25,5);
// Horizontal lines
        glVertex2i(24, 3);
        glVertex2i(27, 3);
        glVertex2i(24, 4);
        glVertex2i(27, 4);
        glVertex2i(25,5);
        glVertex2i(26,5);
        glVertex2i(26,5);
        glVertex2i(26,4);
        glEnd();
        glFlush();

    } else if (mouseX > 485 && mouseX < 564 && mouseY > 340 && mouseY < 380) {//red shape 7
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(24, 0);
        glVertex2i(28, 0);
        glVertex2i(28, 1);
        glVertex2i(24, 1);
        glVertex2i(24, 0);
// Horizontal lines
        glVertex2i(24, 0);
        glVertex2i(28, 0);
        glVertex2i(28, 1);
        glVertex2i(24, 1);
        glVertex2i(24, 0);
        glEnd();
        glFlush();

    } else if (mouseX > 569 && mouseX < 626 && mouseY > 40 && mouseY < 82) {//red shape 8
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(28,17);
        glVertex2i(28,16);
        glVertex2i(28,16);
        glVertex2i(31,16);
        glVertex2i(29,16);
        glVertex2i(29,16);
        glVertex2i(30,18);
        glVertex2i(30,17);
// Horizontal lines
        glVertex2i(31,18);
        glVertex2i(31,16);
        glVertex2i(30,18);
        glVertex2i(31,18);
        glVertex2i(28,17);
        glVertex2i(30,17);
        glVertex2i(29,16);
        glVertex2i(31,16);
        glEnd();
        glFlush();

    } else if (mouseX > 566 && mouseX < 625 && mouseY > 108 && mouseY < 133) {//red shape 9
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(28,14);
        glVertex2i(28,13);
        glVertex2i(29,15);
        glVertex2i(29,14);
        glVertex2i(30,14);
        glVertex2i(30,13);
        glVertex2i(31,15);
        glVertex2i(31,14);
// Horizontal lines
        glVertex2i(29,15);
        glVertex2i(31,15);
        glVertex2i(28,14);
        glVertex2i(29,14);
        glVertex2i(30,14);
        glVertex2i(31,14);
        glVertex2i(28,13);
        glVertex2i(30,13);
        glEnd();
        glFlush();

    } else if (mouseX > 566 && mouseX < 646 && mouseY > 160 && mouseY < 202) {//red shape 10
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(28,12);
        glVertex2i(28,10);
        glVertex2i(29,12);
        glVertex2i(29,11);
        glVertex2i(32,11);
        glVertex2i(32,10);
// Horizontal lines
        glVertex2i(28,12);
        glVertex2i(29,12);
        glVertex2i(29,11);
        glVertex2i(32,11);
        glVertex2i(28,10);
        glVertex2i(32,10);
        glEnd();
        glFlush();
    } else if (mouseX > 566 && mouseX < 625 && mouseY > 221 && mouseY < 282) {//red shape 11
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(29,9);
        glVertex2i(29,7);
        glVertex2i(30,9);
        glVertex2i(30,7);
        glVertex2i(28,7);
        glVertex2i(28,6);
        glVertex2i(31,7);
        glVertex2i(31,6);
// Horizontal lines
        glVertex2i(29,9);
        glVertex2i(30,9);
        glVertex2i(28,7);
        glVertex2i(29,7);
        glVertex2i(30,7);
        glVertex2i(31,7);
        glVertex2i(28,6);
        glVertex2i(31,6);
        glEnd();
        glFlush();

    } else if (mouseX > 566 && mouseX < 626 && mouseY > 302 && mouseY < 360) {//red shape 12
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(28,5);
        glVertex2i(28,2);
        glVertex2i(29,5);
        glVertex2i(29,3);
        glVertex2i(31,3);
        glVertex2i(31,2);
// Horitzontal lines
        glVertex2i(28,5);
        glVertex2i(29,5);
        glVertex2i(29,3);
        glVertex2i(31,3);
        glVertex2i(28,2);
        glVertex2i(31,2);
        glEnd();
        glFlush();

    } else if (mouseX > 645 && mouseX < 728 && mouseY > 42 && mouseY < 81) {//red shape 13
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(32,17);
        glVertex2i(32,16);
        glVertex2i(33,18);
        glVertex2i(33,17);
        glVertex2i(34,17);
        glVertex2i(34,16);
        glVertex2i(36,18);
        glVertex2i(36,17);
// Horitzontal lines
        glVertex2i(32,17);
        glVertex2i(33,17);
        glVertex2i(32,16);
        glVertex2i(34,16);
        glVertex2i(33,18);
        glVertex2i(36,18);
        glVertex2i(34,17);
        glVertex2i(36,17);
        glEnd();
        glFlush();

    } else if (mouseX > 645 && mouseX < 707 && mouseY > 102 && mouseY < 162) {//red shape 14
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(32,14);
        glVertex2i(32,12);
        glVertex2i(33,13);
        glVertex2i(33,12);
        glVertex2i(34,15);
        glVertex2i(34,14);
        glVertex2i(35,15);
        glVertex2i(35,13);
// Horitzontal lines
        glVertex2i(34,15);
        glVertex2i(35,15);
        glVertex2i(32,14);
        glVertex2i(34,14);
        glVertex2i(33,13);
        glVertex2i(35,13);
        glVertex2i(32,12);
        glVertex2i(33,12);
        glEnd();
        glFlush();

    } else if (mouseX > 665 && mouseX < 707 && mouseY > 182 && mouseY < 240) {//red shape 15
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(33,11);
        glVertex2i(33,8);
        glVertex2i(34,11);
        glVertex2i(34,10);
        glVertex2i(35,10);
        glVertex2i(35,8);
// Horitzontal lines
        glVertex2i(33,11);
        glVertex2i(34,11);
        glVertex2i(34,10);
        glVertex2i(35,10);
        glVertex2i(33,8);
        glVertex2i(35,8);
        glEnd();
        glFlush();

    } else if (mouseX > 645 && mouseX < 707 && mouseY > 260 && mouseY < 320) {//red shape 16
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(33,7);
        glVertex2i(33,6);
        glVertex2i(32,6);
        glVertex2i(32,4);
        glVertex2i(33,5);
        glVertex2i(33,4);
        glVertex2i(34,6);
        glVertex2i(34,5);
        glVertex2i(35,7);
        glVertex2i(35,6);
// Horitzontal lines
        glVertex2i(32,4);
        glVertex2i(33,4);
        glVertex2i(32,6);
        glVertex2i(33,6);
        glVertex2i(33,5);
        glVertex2i(34,5);
        glVertex2i(34,6);
        glVertex2i(35,6);
        glVertex2i(33,7);
        glVertex2i(35,7);
        glEnd();
        glFlush();

    } else if (mouseX > 646 && mouseX < 685 && mouseY > 342 && mouseY < 395) {//red shape 17
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(32,3);
        glVertex2i(32,0);
        glVertex2i(33,2);
        glVertex2i(33,1);
        glVertex2i(34,3);
        glVertex2i(34,2);
        glVertex2i(33,2);
        glVertex2i(33,1);
        glVertex2i(34,1);
        glVertex2i(34,0);
// Horitzontal lines
        glVertex2i(32,3);
        glVertex2i(34,3);
        glVertex2i(33,2);
        glVertex2i(34,2);
        glVertex2i(33,1);
        glVertex2i(34,1);
        glVertex2i(32,0);
        glVertex2i(34,0);
        glEnd();
        glFlush();

    } else if (mouseX > 747 && mouseX < 807 && mouseY > 59 && mouseY < 100) {//red shape 18
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(38,18);
        glVertex2i(38,17);
        glVertex2i(37,17);
        glVertex2i(37,16);
        glVertex2i(38,16);
        glVertex2i(38,15);
        glVertex2i(39,17);
        glVertex2i(39,15);
        glVertex2i(40,18);
        glVertex2i(40,17);
// Horitzontal lines
        glVertex2i(38,18);
        glVertex2i(40,18);
        glVertex2i(37,17);
        glVertex2i(38,17);
        glVertex2i(38,15);
        glVertex2i(39,15);
        glVertex2i(39,17);
        glVertex2i(40,17);
        glVertex2i(37,16);
        glVertex2i(38,16);
        glEnd();
        glFlush();

    } else if (mouseX > 745 && mouseX < 807 && mouseY > 124 && mouseY < 182) {//red shape 19
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(37,13);
        glVertex2i(37,12);
        glVertex2i(38,12);
        glVertex2i(38,11);
        glVertex2i(38,14);
        glVertex2i(38,13);
        glVertex2i(39,14);
        glVertex2i(39,13);
        glVertex2i(39,12);
        glVertex2i(39,11);
        glVertex2i(40,13);
        glVertex2i(40,12);
// Horitzontal lines
        glVertex2i(38,14);
        glVertex2i(39,14);
        glVertex2i(37,13);
        glVertex2i(38,13);
        glVertex2i(39,13);
        glVertex2i(40,13);
        glVertex2i(37,12);
        glVertex2i(38,12);
        glVertex2i(39,12);
        glVertex2i(40,12);
        glVertex2i(38,11);
        glVertex2i(39,11);
        glEnd();
        glFlush();

    } else if (mouseX > 727 && mouseX < 806 && mouseY > 201 && mouseY < 242) {//red shape 20
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(36,9);
        glVertex2i(36,8);
        glVertex2i(37,10);
        glVertex2i(37,9);
        glVertex2i(38,10);
        glVertex2i(38,9);
        glVertex2i(40,9);
        glVertex2i(40,8);
// Horitzontal lines
        glVertex2i(36,9);
        glVertex2i(37,9);
        glVertex2i(37,10);
        glVertex2i(38,10);
        glVertex2i(38,9);
        glVertex2i(40,9);
        glVertex2i(36,8);
        glVertex2i(40,8);
        glEnd();
        glFlush();

    } else if (mouseX > 787 && mouseX < 807 && mouseY > 262 && mouseY < 362) {//red shape 21
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(39,7);
        glVertex2i(39,2);
        glVertex2i(40,7);
        glVertex2i(40,2);
// Horitzontal lines
        glVertex2i(39,7);
        glVertex2i(40,7);
        glVertex2i(39,2);
        glVertex2i(40,2);
        glEnd();
        glFlush();

    }else if(mouseX > 887 && mouseX <930  && mouseY > 100 && mouseY < 120){//blue shape 1
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(44,14);
        glVertex2i(44,15);
        glVertex2i(46,14);
        glVertex2i(46,15);
// Horitzontal lines
        glVertex2i(44,14);
        glVertex2i(46,14);
        glVertex2i(44,15);
        glVertex2i(46,15);
        glEnd();
        glFlush();

    }else if(mouseX > 890 && mouseX <930  && mouseY > 140 && mouseY < 180){//blue shape 2
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(44,12);
        glVertex2i(44,13);
        glVertex2i(46,11);
        glVertex2i(46,13);
        glVertex2i(45,12);
        glVertex2i(45,11);
// Horitzontal lines
        glVertex2i(44,12);
        glVertex2i(45,12);
        glVertex2i(44,13);
        glVertex2i(46,13);
        glVertex2i(45,11);
        glVertex2i(46,11);
        glEnd();
        glFlush();

    }else if(mouseX > 887 && mouseX <950  && mouseY > 200 && mouseY < 220){//blue shape 3
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(44,10);
        glVertex2i(44,9);
        glVertex2i(47,10);
        glVertex2i(47,9);
// Horitzontal lines
        glVertex2i(44,10);
        glVertex2i(47,10);
        glVertex2i(44,9);
        glVertex2i(47,9);
        glEnd();
        glFlush();

    }else if(mouseX > 887 && mouseX <920  && mouseY > 240 && mouseY < 280){//blue shape 4
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(44,8);
        glVertex2i(44,6);
        glVertex2i(46,8);
        glVertex2i(46,6);
// Horitzontal lines
        glVertex2i(44,8);
        glVertex2i(46,8);
        glVertex2i(44,6);
        glVertex2i(46,6);
        glEnd();
        glFlush();

    }else if(mouseX > 887 && mouseX <950  && mouseY > 300 && mouseY < 335){//blue shape 5
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(45,5);
        glVertex2i(45,4);
        glVertex2i(46,5);
        glVertex2i(46,4);
        glVertex2i(44,4);
        glVertex2i(44,3);
        glVertex2i(47,4);
        glVertex2i(47,3);
// Horitzontal lines
        glVertex2i(44,3);
        glVertex2i(47,3);
        glVertex2i(44,4);
        glVertex2i(45,4);
        glVertex2i(45,5);
        glVertex2i(46,5);
        glVertex2i(46,4);
        glVertex2i(47,4);
        glEnd();
        glFlush();

    }else if(mouseX > 887 && mouseX <970  && mouseY > 380 && mouseY < 400){//blue shape 6
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(44,1);
        glVertex2i(44,0);
        glVertex2i(48,1);
        glVertex2i(48,0);
// Horitzontal lines
        glVertex2i(44,1);
        glVertex2i(48,1);
        glVertex2i(44,0);
        glVertex2i(48,0);
        glEnd();
        glFlush();
    }

    else if(mouseX > 970 && mouseX <1030  && mouseY > 40 && mouseY < 80){//blue shape 7
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(48,17);
        glVertex2i(48,16);
        glVertex2i(50,18);
        glVertex2i(50,17);
        glVertex2i(51,18);
        glVertex2i(51,16);
// Horitzontal lines
        glVertex2i(48,16);
        glVertex2i(51,16);
        glVertex2i(48,17);
        glVertex2i(50,17);
        glVertex2i(50,18);
        glVertex2i(51,18);
        glEnd();
        glFlush();

    }else if(mouseX > 970 && mouseX <1030  && mouseY > 100 && mouseY < 140){//blue shape 8
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(48,14);
        glVertex2i(48,13);
        glVertex2i(49,15);
        glVertex2i(49,14);
        glVertex2i(50,14);
        glVertex2i(50,13);
        glVertex2i(51,15);
        glVertex2i(51,14);
// Horitzontal lines
        glVertex2i(49,15);
        glVertex2i(51,15);
        glVertex2i(48,14);
        glVertex2i(49,14);
        glVertex2i(50,14);
        glVertex2i(51,14);
        glVertex2i(48,13);
        glVertex2i(50,13);
        glEnd();
        glFlush();

    }else if(mouseX > 970 && mouseX <1050  && mouseY > 160 && mouseY < 200){//blue shape 9
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(48,12);
        glVertex2i(48,10);
        glVertex2i(49,12);
        glVertex2i(49,11);
        glVertex2i(52,11);
        glVertex2i(52,10);
// Horitzontal lines
        glVertex2i(48,12);
        glVertex2i(49,12);
        glVertex2i(49,11);
        glVertex2i(52,11);
        glVertex2i(48,10);
        glVertex2i(52,10);
        glEnd();
        glFlush();

    }else if(mouseX > 970 && mouseX <1030  && mouseY > 220 && mouseY < 280){//blue shape 10
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(49,9);
        glVertex2i(49,7);
        glVertex2i(50,9);
        glVertex2i(50,7);
        glVertex2i(48,7);
        glVertex2i(48,6);
        glVertex2i(51,7);
        glVertex2i(51,6);
// Horitzontal lines
        glVertex2i(49,9);
        glVertex2i(50,9);
        glVertex2i(48,7);
        glVertex2i(49,7);
        glVertex2i(50,7);
        glVertex2i(51,7);
        glVertex2i(48,6);
        glVertex2i(51,6);
        glEnd();
        glFlush();

    }else if(mouseX > 970 && mouseX <1030  && mouseY > 300 && mouseY < 360){//blue shape 11
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(48,5);
        glVertex2i(48,2);
        glVertex2i(49,5);
        glVertex2i(49,3);
        glVertex2i(51,3);
        glVertex2i(51,2);
// Horitzontal lines
        glVertex2i(48,5);
        glVertex2i(49,5);
        glVertex2i(49,3);
        glVertex2i(51,3);
        glVertex2i(48,2);
        glVertex2i(51,2);
        glEnd();
        glFlush();

    }else if(mouseX > 1050 && mouseX <1130  && mouseY > 40 && mouseY < 80){//blue shape 12
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(52,17);
        glVertex2i(52,16);
        glVertex2i(53,18);
        glVertex2i(53,17);
        glVertex2i(54,17);
        glVertex2i(54,16);
        glVertex2i(56,18);
        glVertex2i(56,17);
// Horitzontal lines
        glVertex2i(52,17);
        glVertex2i(53,17);
        glVertex2i(52,16);
        glVertex2i(54,16);
        glVertex2i(53,18);
        glVertex2i(56,18);
        glVertex2i(54,17);
        glVertex2i(56,17);
        glEnd();
        glFlush();

    }else if(mouseX > 1050 && mouseX <1110  && mouseY > 100 && mouseY < 160){//blue shape 13
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(52,14);
        glVertex2i(52,12);
        glVertex2i(53,13);
        glVertex2i(53,12);
        glVertex2i(54,15);
        glVertex2i(54,14);
        glVertex2i(55,15);
        glVertex2i(55,13);
// Horitzontal lines
        glVertex2i(54,15);
        glVertex2i(55,15);
        glVertex2i(52,14);
        glVertex2i(54,14);
        glVertex2i(53,13);
        glVertex2i(55,13);
        glVertex2i(52,12);
        glVertex2i(53,12);
        glEnd();
        glFlush();

    }else if(mouseX > 1070 && mouseX <1110  && mouseY > 180 && mouseY < 240){//blue shape 14
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(53,11);
        glVertex2i(53,8);
        glVertex2i(54,11);
        glVertex2i(54,10);
        glVertex2i(55,10);
        glVertex2i(55,8);
// Horitzontal lines
        glVertex2i(53,11);
        glVertex2i(54,11);
        glVertex2i(54,10);
        glVertex2i(55,10);
        glVertex2i(53,8);
        glVertex2i(55,8);
        glEnd();
        glFlush();

    }else if(mouseX > 1050 && mouseX <1110  && mouseY > 260 && mouseY < 320){//blue shape 15
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(53,7);
        glVertex2i(53,6);
        glVertex2i(52,6);
        glVertex2i(52,4);
        glVertex2i(53,5);
        glVertex2i(53,4);
        glVertex2i(54,6);
        glVertex2i(54,5);
        glVertex2i(55,7);
        glVertex2i(55,6);
// Horitzontal lines
        glVertex2i(52,4);
        glVertex2i(53,4);
        glVertex2i(52,6);
        glVertex2i(53,6);
        glVertex2i(53,5);
        glVertex2i(54,5);
        glVertex2i(54,6);
        glVertex2i(55,6);
        glVertex2i(53,7);
        glVertex2i(55,7);
        glEnd();
        glFlush();

    }else if(mouseX > 1050 && mouseX <1090  && mouseY > 340 && mouseY < 400){//blue shape 16
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(52,3);
        glVertex2i(52,0);
        glVertex2i(53,2);
        glVertex2i(53,1);
        glVertex2i(54,3);
        glVertex2i(54,2);
        glVertex2i(53,2);
        glVertex2i(53,1);
        glVertex2i(54,1);
        glVertex2i(54,0);
// Horitzontal lines
        glVertex2i(52,3);
        glVertex2i(54,3);
        glVertex2i(53,2);
        glVertex2i(54,2);
        glVertex2i(53,1);
        glVertex2i(54,1);
        glVertex2i(52,0);
        glVertex2i(54,0);
        glEnd();
        glFlush();

    }else if(mouseX > 1150 && mouseX <1210  && mouseY > 40 && mouseY < 100){//blue shape 17
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(58,18);
        glVertex2i(58,17);
        glVertex2i(57,17);
        glVertex2i(57,16);
        glVertex2i(58,16);
        glVertex2i(58,15);
        glVertex2i(59,17);
        glVertex2i(59,15);
        glVertex2i(60,18);
        glVertex2i(60,17);
// Horitzontal lines
        glVertex2i(58,18);
        glVertex2i(60,18);
        glVertex2i(57,17);
        glVertex2i(58,17);
        glVertex2i(58,15);
        glVertex2i(59,15);
        glVertex2i(59,17);
        glVertex2i(60,17);
        glVertex2i(57,16);
        glVertex2i(58,16);
        glEnd();
        glFlush();

    }else if(mouseX > 1150 && mouseX <1210  && mouseY > 120 && mouseY < 180){//blue shape 18
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(57,13);
        glVertex2i(57,12);
        glVertex2i(58,12);
        glVertex2i(58,11);
        glVertex2i(58,14);
        glVertex2i(58,13);
        glVertex2i(59,14);
        glVertex2i(59,13);
        glVertex2i(59,12);
        glVertex2i(59,11);
        glVertex2i(60,13);
        glVertex2i(60,12);
// Horitzontal lines
        glVertex2i(58,14);
        glVertex2i(59,14);
        glVertex2i(57,13);
        glVertex2i(58,13);
        glVertex2i(59,13);
        glVertex2i(60,13);
        glVertex2i(57,12);
        glVertex2i(58,12);
        glVertex2i(59,12);
        glVertex2i(60,12);
        glVertex2i(58,11);
        glVertex2i(59,11);
        glEnd();
        glFlush();

    }else if(mouseX > 1150 && mouseX <1210  && mouseY > 40 && mouseY < 100){//blue shape 19
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(58,18);
        glVertex2i(58,17);
        glVertex2i(57,17);
        glVertex2i(57,16);
        glVertex2i(58,16);
        glVertex2i(58,15);
        glVertex2i(59,17);
        glVertex2i(59,15);
        glVertex2i(60,18);
        glVertex2i(60,17);
// Horizontal lines
        glVertex2i(58,18);
        glVertex2i(60,18);
        glVertex2i(57,17);
        glVertex2i(58,17);
        glVertex2i(58,15);
        glVertex2i(59,15);
        glVertex2i(59,17);
        glVertex2i(60,17);
        glVertex2i(57,16);
        glVertex2i(58,16);
        glEnd();
        glFlush();

    }else if(mouseX > 1130 && mouseX <1210  && mouseY > 200 && mouseY < 240){//blue shape 20
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(56,9);
        glVertex2i(56,8);
        glVertex2i(57,10);
        glVertex2i(57,9);
        glVertex2i(58,10);
        glVertex2i(58,9);
        glVertex2i(60,9);
        glVertex2i(60,8);
// Horizontal lines
        glVertex2i(56,9);
        glVertex2i(57,9);
        glVertex2i(57,10);
        glVertex2i(58,10);
        glVertex2i(58,9);
        glVertex2i(60,9);
        glVertex2i(56,8);
        glVertex2i(60,8);
        glEnd();
        glFlush();

    }else if(mouseX > 1200 && mouseX <1210  && mouseY > 260 && mouseY < 360){//blue shape 21
        glLineWidth(3.0);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(59,7);
        glVertex2i(59,2);
        glVertex2i(60,7);
        glVertex2i(60,2);
// Horizontal lines
        glVertex2i(59,7);
        glVertex2i(60,7);
        glVertex2i(59,2);
        glVertex2i(60,2);
        glEnd();
        glFlush();
    }

    s2.draw(p1.pieceColor,b);

    b.DrawBoard();
    //Create Player Area
    std::string message1 = "Player 1's Pieces!";
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2i(28, 19);
    for (char c : message1) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
    std::string message2 = "Player 2's Pieces!";
    glColor3f(0.0, 0.0, 1.0);
    glRasterPos2i(48, 19);
    for (char c : message2) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }

    glFlush();
}

void displayEnd(){

}
/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void display() {
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
    widthGlobal=width;
    heightGlobal=height;
    glViewport(0, 0, width, height);
    glLoadIdentity();
    gluOrtho2D(0, width / s1.block_size, 0, height / s1.block_size);
}


void timer(int value);

void flush(int value);

void shift(int y);

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
        case GLUT_KEY_F1:
            s2.drawToBoard(b);
            break;
    }
}

void cursor(int x, int y) {
    mouseX=x;
    mouseY=y;


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
    glutInitWindowPosition(0, 0); // Position the window's initial top-left corner
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
