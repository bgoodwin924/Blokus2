//
// Created by might on 4/19/2018.
//

#include "Blokus.h"
int turn = 0;
Shape::Shape(){
    memcpy(curr_block, tetrominos[rand() % 1], 5 * 5 * sizeof(int));
    curr_pos[0] = init_pos[0];
    curr_pos[1] = init_pos[1];
}
void Shape::init_curr_block(int i){
    if (turn % 2 == 0) { //If turn mod 2 = 0, It is player 1s turn
        i += 21; //Set tetrominos to red (shapes apear as 1s on the board)
    }
    if (turn % 2 != 0) { //If turn mod 2 != 0, It is player 2s turn
        i -= 21; //Set tetrominos to red (shapes apear as 2s on the board)
    }
    memcpy(curr_block, tetrominos[i], 5 * 5 * sizeof(int));
    curr_pos[0] = init_pos[0];
    curr_pos[1] = init_pos[1];

}
bool Shape::isempty(Board b, int next_x, int next_y){
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

bool Shape::isInShape(int x, int y, Board b, double widthGlobal, double heightGlobal) {
    positionCoord posPiece1;
    posPiece1.xpos = curr_pos[0] + 20;
    cout << "POP PIECE 1 " << posPiece1.xpos << endl;
    posPiece1.ypos = b.column_count - (curr_pos[1]) - 2;
    cout << posPiece1.ypos << endl;
    positionCoord pos2Piece1;
    pos2Piece1.xpos = curr_pos[0] + 20;
    pos2Piece1.ypos = b.column_count - (curr_pos[1] + 1) - 2;
    positionCoord pos3Piece1;
    pos3Piece1.xpos = curr_pos[0] + 1 + 20;
    pos3Piece1.ypos = b.column_count - (curr_pos[1] + 1) - 2;
    positionCoord pos4Piece1;
    pos4Piece1.xpos = curr_pos[0] + 1 + 20;
    pos4Piece1.ypos = b.column_count - (curr_pos[1]) - 2;
//    x /= widthGlobal/s1.block_size;
//    y /= heightGlobal/s1.block_size;
    if(x > 485 && x < 505 && y > 60 && y < 80){
        cout << "                    HOVER" << endl;
        glLineWidth(3.0);
        //glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 1.0, 0.0);

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
    }

//    else cout << "Not hovering" << endl;
//}

bool Shape::move(Board b,int x, int y){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (curr_block[i][j]) {
                int next_x = curr_pos[0] + j + x;
                int next_y = curr_pos[1] + i + y;
                if (!isempty(b,next_x, next_y)) {
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
void Shape::rotate(Board b){
    int tmp[5][5] = {};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (curr_block[i][j]) {
                int next_x = curr_pos[0] + i;
                int next_y = curr_pos[1] + 4 - j;
                if (!isempty(b,next_x, next_y)) {
                    return;
                }
                tmp[5 - j][i] = 1;
            }
        }
    }
    memcpy(curr_block, tmp, 5 * 5 * sizeof(int));
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
    const int interval = 500;
    glutTimerFunc(interval, timer, 0);
}

void Shape::throw_new_block(Board b){
    init_curr_block(rand() % 21);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (curr_block[i][j] && b.blocks[curr_pos[1] + i][curr_pos[0] + j]) {
                //game_over();
                return;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(interval, timer, 0);
}

void Shape::draw(PieceColor pieceColor, Board gameBoard) {
    //glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (curr_block[i][j]) {
                if(pieceColor==red){
                    glColor3f(1,0,0);
                }else if(pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(pieceColor==green)
                    glColor3f(0,1,0);
                }else{
                    glColor3f(0.847f, 0.749f, 0.847f);
                }
                glVertex2f(curr_pos[0] + j, gameBoard.column_count - (curr_pos[1] + i));
                glVertex2f(curr_pos[0] + j, gameBoard.column_count - (curr_pos[1] + i + 1));
                glVertex2f(curr_pos[0] + j + 1, gameBoard.column_count - (curr_pos[1] + i + 1));
                glVertex2f(curr_pos[0] + j + 1, gameBoard.column_count - (curr_pos[1] + i));
//                cout << "draw: 2nd curr_pos[0] + j = " << curr_pos[0] + j
//                     << " - b.column_count - (curr_pos[1] + i) =" << b.column_count - (curr_pos[1] + i)
//                     << " * 20 j: " <<   (curr_pos[0] + j ) * 20 << " - " << (curr_pos[0] + j + 1) * 20
//                     << " * 20 i: " <<   (b.column_count - (curr_pos[1] + i)  ) * 20 << " - " << (b.column_count - (curr_pos[1] + i + 1) ) * 20
//                        << endl;
        }
    }
    for (int i = 0; i < gameBoard.column_count; i++) {
        for (int j = 0; j < gameBoard.row_count; j++) {
            if (gameBoard.blocks[i][j]) {
                if(gameBoard.blocks[i][j] == 1){
                    glColor3f(1,0,0);
                }else if(gameBoard.blocks[i][j] == 2) {
                    glColor3f(0, 0, 1);
                }
                glVertex2f(j, gameBoard.column_count - i);
                glVertex2f(j, gameBoard.column_count - i - 1);
                glVertex2f(j + 1, gameBoard.column_count - i - 1);
                glVertex2f(j + 1, gameBoard.column_count - i);
                //cout << "draw 1st j = " << j << " - column =" << b.column_count << endl;
            }
        }
    }
    glEnd();
}
/*drawToBoard takes param b, sets ints x and y to
 *curr_position, and loops through the matrice
 *and draws to the board if there is nothing there
 * already, then adds 1 to int turn */
void Shape::drawToBoard(Board &b) {
    int x = curr_pos[1]; //Set x to curr_pos at index 1
    int y = curr_pos[0]; // Set y to curr_pos at index 2
    for(int i = x; i < x+5; i++) { //Loop through the matrice
        for(int j = y; j < y+5; j++) { //Create nested loop
            if (!b.blocks[i][j]) { //If there is no block at curr_pos
                b.blocks[i][j] = curr_block[i-x][j-y]; //Draw the block at curr_pos
            }
        }
    }
    turn++; //Add 1 to turn accumulator
}

Board::Board(){}
void Board::DrawBoard() {
    glLineWidth(2.5);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
// Vertical lines
    for(int i=0;i<21;i++){
        glVertex2i(i,0);
        glVertex2i(i,21);
    }

// Horitzontal lines

    for (int i = 0; i < 21; i++) {
        glVertex2i(0, i);
        glVertex2i(20, i);
    }

    //divide inventory
    glVertex2i(42,20);
    glVertex2i(42,0);
    glEnd();
}




Player::Player() {
    pieceColor=unknownColor;
    playerScore=0;
}

Player::Player(PieceColor pc) {
    pieceColor=pc;
    for(int i=1;i<22;i++){
        PieceInventory.push_back(i);
    }
}
/*
void Player::DrawPlayerInv(Shape s, Board b) {
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
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s.curr_block[i][j]) {
                if(pieceColor==red){
                    glColor3f(1,0,0);
                }else if(pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s.curr_pos[0] + j+20, b.column_count - (s.curr_pos[1] + i));
            cout<<"1: "<<s.curr_pos[0] + j<<','<< b.column_count - (s.curr_pos[1] + i)<<endl;

            glVertex2f(s.curr_pos[0] + j+20, b.column_count - (s.curr_pos[1] + i + 1));
            cout<<"2: "<<s.curr_pos[0] + j<<','<< b.column_count - (s.curr_pos[1] + i + 1)<<endl;

            glVertex2f(s.curr_pos[0] + j + 1+20, b.column_count - (s.curr_pos[1] + i + 1));
            cout<<"3: "<<s.curr_pos[0] + j + 1<<','<< b.column_count - (s.curr_pos[1] + i + 1)<<endl;

            glVertex2f(s.curr_pos[0] + j + 1+20, b.column_count - (s.curr_pos[1] + i));
            cout<<"4: "<<s.curr_pos[0] + j + 1<<','<< b.column_count - (s.curr_pos[1] + i)<<endl;
        }
    }
    glEnd();
}*/
void Player::drawIntro(Shape s1,Player p1, Player p2,Player p3,Player p4,Board b) {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    s1.init_curr_block(7);
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
            glVertex2f(s1.curr_pos[0] + j+2, b.column_count - (s1.curr_pos[1] + i)-5);
            glVertex2f(s1.curr_pos[0] + j+2, b.column_count - (s1.curr_pos[1] + i + 1)-5);
            glVertex2f(s1.curr_pos[0] + j + 1+2, b.column_count - (s1.curr_pos[1] + i + 1)-5);
            glVertex2f(s1.curr_pos[0] + j + 1+2, b.column_count - (s1.curr_pos[1] + i)-5);
        }
    }
    glEnd();
    glBegin(GL_QUADS);
    s1.init_curr_block(5);
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
            glVertex2f(s1.curr_pos[0] + j+8, b.column_count - (s1.curr_pos[1] + i)-10);
            glVertex2f(s1.curr_pos[0] + j+8, b.column_count - (s1.curr_pos[1] + i + 1)-10);
            glVertex2f(s1.curr_pos[0] + j + 1+8, b.column_count - (s1.curr_pos[1] + i + 1)-10);
            glVertex2f(s1.curr_pos[0] + j + 1+8, b.column_count - (s1.curr_pos[1] + i)-10);
        }
    }
    glEnd();
    glBegin(GL_QUADS);
    s1.init_curr_block(8);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p3.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p3.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p3.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p3.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+25, b.column_count - (s1.curr_pos[1] + i)-5);
            glVertex2f(s1.curr_pos[0] + j+25, b.column_count - (s1.curr_pos[1] + i + 1)-5);
            glVertex2f(s1.curr_pos[0] + j + 1+25, b.column_count - (s1.curr_pos[1] + i + 1)-5);
            glVertex2f(s1.curr_pos[0] + j + 1+25, b.column_count - (s1.curr_pos[1] + i)-5);
        }
    }
    glEnd();
    glBegin(GL_QUADS);
    s1.init_curr_block(15);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p4.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p4.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p4.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p4.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+45, b.column_count - (s1.curr_pos[1] + i)-12);
            glVertex2f(s1.curr_pos[0] + j+45, b.column_count - (s1.curr_pos[1] + i + 1)-12);
            glVertex2f(s1.curr_pos[0] + j + 1+45, b.column_count - (s1.curr_pos[1] + i + 1)-12);
            glVertex2f(s1.curr_pos[0] + j + 1+45, b.column_count - (s1.curr_pos[1] + i)-12);
        }
    }
    glEnd();
    glBegin(GL_QUADS);
    s1.init_curr_block(1);
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
            glVertex2f(s1.curr_pos[0] + j+30, b.column_count - (s1.curr_pos[1] + i)-5);
            glVertex2f(s1.curr_pos[0] + j+30, b.column_count - (s1.curr_pos[1] + i + 1)-5);
            glVertex2f(s1.curr_pos[0] + j + 1+30, b.column_count - (s1.curr_pos[1] + i + 1)-5);
            glVertex2f(s1.curr_pos[0] + j + 1+30, b.column_count - (s1.curr_pos[1] + i)-5);
        }
    }
    glEnd();
    glBegin(GL_QUADS);
    s1.init_curr_block(2);
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
            glVertex2f(s1.curr_pos[0] + j+18, b.column_count - (s1.curr_pos[1] + i)-17);
            glVertex2f(s1.curr_pos[0] + j+18, b.column_count - (s1.curr_pos[1] + i + 1)-17);
            glVertex2f(s1.curr_pos[0] + j + 1+18, b.column_count - (s1.curr_pos[1] + i + 1)-17);
            glVertex2f(s1.curr_pos[0] + j + 1+18, b.column_count - (s1.curr_pos[1] + i)-17);
        }
    }
    glEnd();
    glBegin(GL_QUADS);
    s1.init_curr_block(13);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p3.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p3.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p3.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p3.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+31, b.column_count - (s1.curr_pos[1] + i)-3);
            glVertex2f(s1.curr_pos[0] + j+31, b.column_count - (s1.curr_pos[1] + i + 1)-3);
            glVertex2f(s1.curr_pos[0] + j + 1+31, b.column_count - (s1.curr_pos[1] + i + 1)-3);
            glVertex2f(s1.curr_pos[0] + j + 1+31, b.column_count - (s1.curr_pos[1] + i)-3);
        }
    }
    glEnd();
    glBegin(GL_QUADS);
    s1.init_curr_block(17);
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (s1.curr_block[i][j]) {
                if(p4.pieceColor==red){
                    glColor3f(1,0,0);
                }else if(p4.pieceColor==blue){
                    glColor3f(0,0,1);
                }else if(p4.pieceColor==yellow){
                    glColor3f(1,1,0);
                }else if(p4.pieceColor==green)
                    glColor3f(0,1,0);
            }else{
                glColor3f(0.847f, 0.749f, 0.847f);
            }
            glVertex2f(s1.curr_pos[0] + j+46, b.column_count - (s1.curr_pos[1] + i)-1);
            glVertex2f(s1.curr_pos[0] + j+46, b.column_count - (s1.curr_pos[1] + i + 1)-1);
            glVertex2f(s1.curr_pos[0] + j + 1+46, b.column_count - (s1.curr_pos[1] + i + 1)-1);
            glVertex2f(s1.curr_pos[0] + j + 1+46, b.column_count - (s1.curr_pos[1] + i)-1);
        }
    }
    glEnd();
    glBegin(GL_QUADS);
    s1.init_curr_block(16);
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
            glVertex2f(s1.curr_pos[0] + j+19, b.column_count - (s1.curr_pos[1] + i)-16);
            glVertex2f(s1.curr_pos[0] + j+19, b.column_count - (s1.curr_pos[1] + i + 1)-16);
            glVertex2f(s1.curr_pos[0] + j + 1+19, b.column_count - (s1.curr_pos[1] + i + 1)-16);
            glVertex2f(s1.curr_pos[0] + j + 1+19, b.column_count - (s1.curr_pos[1] + i)-16);
        }
    }
    glEnd();
    glBegin(GL_QUADS);
    s1.init_curr_block(20);
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
            glVertex2f(s1.curr_pos[0] + j+25, b.column_count - (s1.curr_pos[1] + i)-12);
            glVertex2f(s1.curr_pos[0] + j+25, b.column_count - (s1.curr_pos[1] + i + 1)-12);
            glVertex2f(s1.curr_pos[0] + j + 1+25, b.column_count - (s1.curr_pos[1] + i + 1)-12);
            glVertex2f(s1.curr_pos[0] + j + 1+25, b.column_count - (s1.curr_pos[1] + i)-12);
        }
    }
    glEnd();
    glBegin(GL_QUADS);
    s1.init_curr_block(18);
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
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i)-16);
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i + 1)-16);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i + 1)-16);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i)-16);
        }
    }
    glEnd();
}
void Player::drawInventory(Shape s1,Player p1, Player p2, Board b) {
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
            int test = s1.curr_pos[0] + j+20;
            int test2 = b.column_count - (s1.curr_pos[1] + i)-6;
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
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i)-18);
            glVertex2f(s1.curr_pos[0] + j+20, b.column_count - (s1.curr_pos[1] + i + 1)-18);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i + 1)-18);
            glVertex2f(s1.curr_pos[0] + j + 1+20, b.column_count - (s1.curr_pos[1] + i)-18);
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
            glVertex2f(s1.curr_pos[0] + j+40, b.column_count - (s1.curr_pos[1] + i)-18);
            glVertex2f(s1.curr_pos[0] + j+40, b.column_count - (s1.curr_pos[1] + i + 1)-18);
            glVertex2f(s1.curr_pos[0] + j + 1+40, b.column_count - (s1.curr_pos[1] + i + 1)-18);
            glVertex2f(s1.curr_pos[0] + j + 1+40, b.column_count - (s1.curr_pos[1] + i)-18);
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
}
