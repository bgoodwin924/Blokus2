#include <iostream>
#include "Game.h"

using namespace std;

bool testPieceEnums() { // testing both enums
    cout << "Testing: pieceColors enums" << endl;
    bool passed = true;
    Piece p;
    Player s;

    p.setPieceColor(red);
    if (p.getPieceColor() != red ) {
        passed = false;
        cout << "FAILED red enum test" << endl;
    }
    if (passed) cout << "Passed red enum test" << endl;

    p.setPieceColor(blue);
    if (p.getPieceColor() != blue ) {
        passed = false;
        cout << "FAILED blue enum test" << endl;
    }
    if (passed) cout << "Passed blue enum test" << endl;

    p.setPieceColor(yellow);
    if (p.getPieceColor() != yellow ) {
        passed = false;
        cout << "FAILED yellow enum test" << endl;
    }
    if (passed) cout << "Passed yellow enum test" << endl;

    p.setPieceColor(green);
    if (p.getPieceColor() != green ){
        passed = false;
        cout << "FAILED green enum test" << endl;
    }
    if (passed) cout << "Passed green enum test" << endl;

    p.setPieceColor(unknownColor);
    if (p.getPieceColor() != unknownColor ) {
        passed = false;
        cout << "FAILED unknownColor enum test" << endl;
    }
    if (passed) cout << "Passed unknownColor enum test" << endl;

    p.setRotationOfSquare(rotate0);
    if (p.getRotationOfSquare() != rotate0 ) {
        passed = false;
        cout << "FAILED rotate0 enum test" << endl;
    }
    if (passed) cout << "Passed rotate0 enum test" << endl;

    p.setRotationOfSquare(rotate90);
    if (p.getRotationOfSquare() != rotate90 ) {
        passed = false;
        cout << "FAILED rotate90 enum test" << endl;
    }
    if (passed) cout << "Passed rotate90 enum test" << endl;

    p.setRotationOfSquare(rotate180);
    if (p.getRotationOfSquare() != rotate180 ) {
        passed = false;
        cout << "FAILED rotate180 enum test" << endl;
    }
    if (passed) cout << "Passed rotate180 enum test" << endl;

    p.setRotationOfSquare(rotate270);
    if (p.getRotationOfSquare() != rotate270 ) {
        passed = false;
        cout << "FAILED rotate270 enum test" << endl;
    }
    if (passed) {
        cout << "Passed rotate270 enum test" << endl;
    }

    s.saveScore();
    return passed;


}

bool testConstructors() {
    bool passed = true;

    // default constructor
    cout << "*** testConstructors() - Pieces - Testing Default Constructor ***" << endl;
    Piece p;

    cout << "Default Piece - Color: " << p.getPieceColor() << " - Default Piece - Rotation: " << p.getRotationOfSquare() << endl;

    Piece pR0(red, rotate0);
    if (pR0.getPieceColor()!=red && pR0.getRotationOfSquare()!=rotate0){
        passed = false;
        cout << "FAILED red rotate0 test - Color:" << pR0.getPieceColor() << " - Rotation: "<< pR0.getRotationOfSquare() << endl;
    }
    if (passed) cout << "Passed red rotate0 test - Color:" << pR0.getPieceColor() << " - Rotation: "<< pR0.getRotationOfSquare() << endl;

    Piece pB90(blue, rotate90);
    if (pB90.getPieceColor()!=blue && pB90.getRotationOfSquare()!=rotate90) {
        passed = false;
        cout << "FAILED blue rotate90 test - Color:" << pB90.getPieceColor() << " - Rotation: "<< pB90.getRotationOfSquare() << endl;
    }
    if (passed) cout << "Passed blue rotate90 test - Color:" << pB90.getPieceColor() << " - Rotation: "<< pB90.getRotationOfSquare() << endl;


    // double checking Setters / Getters on this same object - going to unknown and rotate0
    pB90.setPieceColor(unknownColor);
    pB90.setRotationOfSquare(rotate0);
    if (pB90.getPieceColor()!=unknownColor && pB90.getRotationOfSquare()!=rotate0) {
        passed = false;
        cout << "Piece Getters/Setters: FAILED unknownColor rotate0 test - Color:" << pB90.getPieceColor() << " - Rotation: "<< pB90.getRotationOfSquare() << endl;
    }
    if (passed) cout << "Piece Getters/Setters: Passed unknownColor rotate0 test - Color:" << pB90.getPieceColor() << " - Rotation: "<< pB90.getRotationOfSquare() << endl;

    // double checking Setters / Getters on this same object - and back to blue and rotate90
    pB90.setPieceColor(blue);
    pB90.setRotationOfSquare(rotate90);
    if (pB90.getPieceColor()!=blue && pB90.getRotationOfSquare()!=rotate90) {
        passed = false;
        cout << "Piece Getters/Setters: FAILED blue rotate90 test - Color:" << pB90.getPieceColor() << " - Rotation: "<< pB90.getRotationOfSquare() << endl;
    }
    if (passed) cout << "Piece Getters/Setters: Passed blue rotate90 test - Color:" << pB90.getPieceColor() << " - Rotation: "<< pB90.getRotationOfSquare() << endl;


    Piece pY180(yellow, rotate180);
    if (pY180.getPieceColor()!=yellow && pY180.getRotationOfSquare()!=rotate180){
        passed = false;
        cout << "FAILED yellow rotate180 test - Color:" << pY180.getPieceColor() << " - Rotation: "<< pY180.getRotationOfSquare() << endl;
    }
    if (passed) cout << "Passed yellow rotate180 test - Color:" << pY180.getPieceColor() << " - Rotation: "<< pY180.getRotationOfSquare() << endl;

    Piece pG270(green, rotate270);
    if (pG270.getPieceColor()!=green && pG270.getRotationOfSquare()!=rotate270){
        passed = false;
        cout << "FAILED green rotate270 test - Color:" << pG270.getPieceColor() << " - Rotation: "<< pG270.getRotationOfSquare() << endl;
    }
    if (passed) cout << "Passed green rotate270 test - Color:" << pG270.getPieceColor() << " - Rotation: "<< pG270.getRotationOfSquare() << endl;

    Piece pU0(unknownColor, rotate0);
    if (pU0.getPieceColor()!=unknownColor && pU0.getRotationOfSquare()!=rotate0){
        passed = false;
        cout << "FAILED unknownColor rotate0 test - Color:" << pU0.getPieceColor() << " - Rotation: "<< pU0.getRotationOfSquare() << endl;
    }
    if (passed) cout << "Passed unknownColor rotate0 test - Color:" << pU0.getPieceColor() << " - Rotation: "<< pU0.getRotationOfSquare() << endl;

    return passed;

}

int main() {
    cout << "*** testing.cpp - main() ***" << endl;
    // to test constructors, getters, and setters
    if (testConstructors()) cout << "Passed all tests in testConstructors!" << endl;

    // to test square and piece - enums
    if (testPieceEnums() ) cout << "Passed all tests in testPieceEnums()! "<< endl;


    return 0;

}