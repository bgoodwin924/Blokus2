//
// Created by Alexandre Verville on 4/7/18.
//

#ifndef BLOCKUS_GAME_H
#define BLOCKUS_GAME_H

#include <string>
// enum for color of pieces
enum pieceColors {red, blue, yellow, green, unknownColor};

class Player { //unrelated class
private:
pieceColors colorOfPiece=unknownColor;

public:
//Constructors
Player();
Player(pieceColors newPieceColors);


};


class Square {
private:


public:
//Constructors
Square();

};


class Piece: public Square{   //pieces are made of squares so, it will inherent from square
private:


public:
//Constructors
Piece();

};

class Board: public Square{
private:


public:
//Constructors
Board();


};


class Blokus: public Board {
private:



public:
//Constructors
    Blokus();
};

class Computer{
private:


public:
//Constructors
    Computer();

};

























#endif //BLOCKUS_GAME_H
