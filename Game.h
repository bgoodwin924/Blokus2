//
// Created by Alexandre Verville on 4/7/18.
//

#ifndef BLOCKUS_GAME_H
#define BLOCKUS_GAME_H

#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <string>
// enum for color of pieces
enum pieceColors {red, blue, yellow, green, unknownColor};
enum squareRotate {rotate0, rotate90, rotate180, rotate270};


//abstract class
class Square {
private:
int          posX = 0;
int          posY = 0;
squareRotate rotationOfSquare=rotate0;

public:
//Constructors
Square();
Square(squareRotate newRotation);
Square(int newPosX, int newPosY);
Square(int newPosX, int newPosY, squareRotate newRotation);

//Getters
int          getPosX()             const ;
int          getPosY()             const ;
squareRotate getRotationOfSquare() const ;


//Setters
void setPosX(int newPosX);
void setPosY(int newPosY);
void setRotationOfSquare(squareRotate newRotation);
};


class Piece: public Square{   //pieces are made of squares so, it will inherent from square
private:
    pieceColors colorOfPiece;
    double length = 0.0;
    double height = 0.0;

public:
//Constructors
Piece();
Piece(pieceColors newPieceColor);
Piece(pieceColors newPieceColor, squareRotate newRotation);
Piece(double newLength, double newHeight);


//Getters
pieceColors     getPieceColor() const;
double          getLength()     const;
double          getHeight()     const;

//Setters
void        setPieceColor(pieceColors newPieceColor);
void        setLength(double newLength);
void        setHeight(double newHeight);
};

class Board: public Square{
private:
    int boardSizeX=20;
    int boardSizeY=20;

public:


//Constructors
Board();
Board(int newBoardSizeX, int newBoardSizeY);

//Getters
int getBoardSizeX()  const;
int getBoardSizeY()  const;

//Setters
void setBoardSizeX(int newBoardSizeX);
void setBoardSizeY(int newBoardSizeY);
};


class Blokus: public Board {
private:


public:
//Constructors
    Blokus();

//Getters


//Setters
};

class Computer{
private:


public:
//Constructors
    Computer();
//Getters



//Setters

};

class Player { //unrelated class will interact with the game pieces and game board
private:
    int playerScore=0;
    pieceColors pieceColor=unknownColor;

public:
//Constructors
    Player();
    Player(pieceColors newPieceColor);
    Player(pieceColors newPieceColor, int newPlayerScore);
    void saveScore();

//Getters
    int getPlayerScore() const;
    pieceColors getPieceColor() const;


//Setters
    void setPlayerScore(int newScore);
    void setPieceColor(pieceColors newPieceColor);
};



// Program initialization NOT OpenGL/GLUT dependent,
// as we haven't created a GLUT window yet
void init(void);

// Initialize OpenGL Graphics
void InitGL(void);

// Callback functions for GLUT */

// Draw the window - this is where all the GL actions are
void display(void);

// Trap and process alphanumeric keyboard events
void kbd(unsigned char key, int x, int y);

// Trap and process special keyboard events
void kbdS(int key, int x, int y);

// Handle "mouse cursor moved" events
void cursor(int x, int y);

// Calls itself after a specified time
void timer(int extra);

// Handle mouse button pressed and released events
void mouse(int button, int state, int x, int y);






















#endif //BLOCKUS_GAME_H
