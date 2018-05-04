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
    glOrtho(0.0, 0.0, 0.0, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.847f, 0.749f, 0.847f ,0.0f);

    p1.drawInventory(s1,p1,p2,b);

    positionCoord posPiece1;
    posPiece1.xpos = s1.curr_pos[0] + 20;
    //cout << "POP PIECE 1 " << posPiece1.xpos << endl;
    posPiece1.ypos = b.column_count - (s1.curr_pos[1]) - 2;
    //cout << posPiece1.ypos << endl;
    positionCoord pos2Piece1;
    pos2Piece1.xpos = s1.curr_pos[0] + 20;
    pos2Piece1.ypos = b.column_count - (s1.curr_pos[1] + 1) - 2;
    positionCoord pos3Piece1;
    pos3Piece1.xpos = s1.curr_pos[0] + 1 + 20;
    pos3Piece1.ypos = b.column_count - (s1.curr_pos[1] + 1) - 2;
    positionCoord pos4Piece1;
    pos4Piece1.xpos = s1.curr_pos[0] + 1 + 20;
    pos4Piece1.ypos = b.column_count - (s1.curr_pos[1]) - 2;
//    x /= widthGlobal/s1.block_size;
//    y /= heightGlobal/s1.block_size;
    if(mouseX > 485 && mouseX < 505 && mouseY > 60 && mouseY < 80){
        cout << "                    HOVER" << endl;
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(24,16);
        glVertex2i(24,17);
        glVertex2i(25,16);
        glVertex2i(25,17);
// Horitzontal lines
        glVertex2i(24,16);
        glVertex2i(25,16);
        glVertex2i(24,17);
        glVertex2i(25,17);
        glEnd();
        glFlush();
    }


    else if(mouseX > 887 && mouseX <910  && mouseY > 60 && mouseY < 80) {
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(44, 16);
        glVertex2i(44, 17);
        glVertex2i(45, 16);
        glVertex2i(45, 17);
// Horitzontal lines
        glVertex2i(44, 16);
        glVertex2i(45, 16);
        glVertex2i(44, 17);
        glVertex2i(45, 17);
        glEnd();
        glFlush();
    }else if(mouseX > 887 && mouseX <930  && mouseY > 100 && mouseY < 120){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
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
    }else if(mouseX > 890 && mouseX <930  && mouseY > 140 && mouseY < 180){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
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
    }else if(mouseX > 887 && mouseX <950  && mouseY > 200 && mouseY < 220){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
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
    }else if(mouseX > 887 && mouseX <920  && mouseY > 240 && mouseY < 280){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
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
    }else if(mouseX > 887 && mouseX <950  && mouseY > 300 && mouseY < 335){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
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
    }else if(mouseX > 887 && mouseX <970  && mouseY > 380 && mouseY < 400){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
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
    else if(mouseX > 970 && mouseX <1030  && mouseY > 40 && mouseY < 80){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
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
    }else if(mouseX > 970 && mouseX <1030  && mouseY > 100 && mouseY < 140){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
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
    }else if(mouseX > 970 && mouseX <1050  && mouseY > 160 && mouseY < 200){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
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
    }else if(mouseX > 970 && mouseX <1030  && mouseY > 220 && mouseY < 280){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
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
    }else if(mouseX > 970 && mouseX <1030  && mouseY > 300 && mouseY < 360){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
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
    }else if(mouseX > 1050 && mouseX <1130  && mouseY > 40 && mouseY < 80){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
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
    }else if(mouseX > 1050 && mouseX <1110  && mouseY > 100 && mouseY < 160){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
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
    }else if(mouseX > 1070 && mouseX <1110  && mouseY > 180 && mouseY < 240){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
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
    }else if(mouseX > 1050 && mouseX <1110  && mouseY > 260 && mouseY < 320){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
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
    }else if(mouseX > 1050 && mouseX <1090  && mouseY > 340 && mouseY < 400){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
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
    }else if(mouseX > 1150 && mouseX <1210  && mouseY > 40 && mouseY < 100){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
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
    }else if(mouseX > 1150 && mouseX <1210  && mouseY > 120 && mouseY < 180){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
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
    }else if(mouseX > 1150 && mouseX <1210  && mouseY > 40 && mouseY < 100){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
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
    }else if(mouseX > 1130 && mouseX <1210  && mouseY > 200 && mouseY < 240){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
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
// Horitzontal lines
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
    }else if(mouseX > 1200 && mouseX <1210  && mouseY > 260 && mouseY < 360){
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_LINES);
// Vertical lines
        glVertex2i(59,7);
        glVertex2i(59,2);
        glVertex2i(60,7);
        glVertex2i(60,2);
// Horitzontal lines
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
    std::string message = "Player 1's Pieces!";
    glColor3f(1.0, 0.0, 0.0);
    glRasterPos2i(28, 19);
    for (char c : message) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);
    }
    message = "Player 2's Pieces!";
    glColor3f(0.0, 0.0, 1.0);
    glRasterPos2i(48, 19);
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
    widthGlobal=width;
    heightGlobal=height;
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
    //s1.isInShape(x,y, b, widthGlobal, heightGlobal);


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
