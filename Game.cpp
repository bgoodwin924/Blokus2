//
// Created by Alexandre Verville on 4/7/18.
//
#include <iostream>
#include <fstream>
#include "Game.h"
using namespace std;



//
/////////////////////////Square CLASS/////////////////////////

//Constructors
Square::Square() {
    posX = 0;
    posY = 0;
    rotationOfSquare=rotate0;

}
Square::Square(squareRotate newRotation){
    posX = 0;
    posY = 0;
    rotationOfSquare=newRotation;
}
Square::Square(int newPosX, int newPosY) {
    posX = newPosX;
    posY = newPosY;
    rotationOfSquare=rotate0;

}
Square::Square(int newPosX, int newPosY, squareRotate newRotation):Square( newRotation) {
    posX = newPosX;
    posY = newPosY;
    rotationOfSquare=newRotation;

}
//Getters
int     Square::getPosX() const {
    return posX;

}
int     Square::getPosY()  const {
    return posY;
}
squareRotate Square::getRotationOfSquare() const{
    return rotationOfSquare;
}
//Setters
void Square::setPosX(int newPosX){
    posX=newPosX;
}
void Square::setPosY(int newPosY){
    posX=newPosY;
}
void Square::setRotationOfSquare(squareRotate newRotation) {
    rotationOfSquare = newRotation;
}
/////////////////////////Piece CLASS/////////////////////////
//Constructors
Piece::Piece() : Square() {
    colorOfPiece = unknownColor;
    length = 0.0;
    height = 0.0;
}
Piece::Piece(pieceColors colorOfPiece) : Square(){
    this->colorOfPiece = colorOfPiece;
    length = 0.0;
    height = 0.0;
}
Piece::Piece(double newLength, double newHeight) : Square(){
    colorOfPiece = unknownColor;
    length = newLength;
    height = newHeight;
}
Piece::Piece(pieceColors newPieceColor, squareRotate newRotation): Square(newRotation){
    colorOfPiece = newPieceColor;
    length = 0.0;
    height = 0.0;
}
//Getters
pieceColors     Piece::getPieceColor() const{
    return colorOfPiece;
}
double          Piece::getLength()     const{
    return length;
}
double          Piece::getHeight()     const{
    return height;
}
//Setters
void        Piece::setPieceColor(pieceColors newPieceColor){
    colorOfPiece= newPieceColor;
}
void        Piece::setLength(double newLength){
    length=newLength;
}
void        Piece::setHeight(double newHeight){
    height=newHeight;
}

/////////////////////////Board CLASS/////////////////////////
//Constructors
Board::Board() {
    boardSizeX=20;
    boardSizeY=20;
}

Board::Board(int newBoardSizeX, int newBoardSizeY){
    int boardSizeX=newBoardSizeX;
    int boardSizeY=newBoardSizeY;
}

//Getters
int Board::getBoardSizeX()  const {
    return boardSizeX;
}
int Board::getBoardSizeY()  const{
    return boardSizeY;
}

//Setters
void Board::setBoardSizeX(int newBoardSizeX){
    boardSizeX=newBoardSizeX;
}
void Board::setBoardSizeY(int newBoardSizeY){
    boardSizeY= newBoardSizeY;
}


/////////////////////////Blokus CLASS/////////////////////////
//Constructors
Blokus::Blokus() {


}
//Getters
//Setters

/////////////////////////Computer CLASS/////////////////////////
//Constructors
Computer::Computer() {


}

/////////////////////////Player CLASS/////////////////////////
//Constructors
Player::Player() {
   playerScore=0;
   pieceColor=unknownColor;
}
Player::Player(pieceColors newPieceColor){
    playerScore=0;
    pieceColor=newPieceColor;

}
Player::Player(pieceColors newPieceColor, int newPlayerScore){
    playerScore=newPlayerScore;
    pieceColor=newPieceColor;

}

//Getters
int Player::getPlayerScore() const{
    return playerScore;
}
pieceColors Player::getPieceColor() const{
    return pieceColor;
}

//Setters
void Player::setPlayerScore(int newScore) {
    playerScore=newScore;
}
void Player::setPieceColor(pieceColors newPieceColor){
    pieceColor=newPieceColor;
}
void Player::saveScore(){
    fstream fOut;
    fOut.open("Score.txt");
    fOut << "Player Score: " << playerScore << endl;
    fOut.close();

}


