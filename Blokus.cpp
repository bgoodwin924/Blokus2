//
// Created by might on 4/19/2018.
//

#include "Blokus.h"

Shape::Shape(){
    memcpy(curr_block, tetrominos[rand() % 1], 5 * 5 * sizeof(int));
    curr_pos[0] = init_pos[0];
    curr_pos[1] = init_pos[1];
}
void Shape::init_curr_block(int i){
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

bool Shape::isInShape(int x, int y, Board b, Shape s1, double widthGlobal, double heightGlobal) {
    positionCoord posPiece1;
    posPiece1.xpos = s1.curr_pos[0] + 20;
    cout << "POP PIECE 1 " << posPiece1.xpos << endl;
    posPiece1.ypos = b.column_count - (s1.curr_pos[1]) - 2;
    cout << posPiece1.ypos << endl;
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
    if(x > 490 && x < 510 && y > 62 && y < 72){
        cout << "                    HOVER" << endl;
    }

    if (x > posPiece1.xpos && y > posPiece1.ypos && x > pos2Piece1.xpos && y > pos2Piece1.ypos && x > pos3Piece1.xpos &&
        y > pos3Piece1.ypos && x > pos4Piece1.xpos && y > pos4Piece1.ypos) {
        cout << "Hovering" << endl;

//        int posPiece2 = (s1.curr_pos[0] + 20, b.column_count - (s1.curr_pos[1] )-4);
//        int pos2Piece2 = (s1.curr_pos[0] + 20, b.column_count - (s1.curr_pos[1] + 1)-4);
//        int pos3Piece2 = (s1.curr_pos[0] + 1+20, b.column_count - (s1.curr_pos[1] + 1)-4);
//        int pos4Piece2 = (s1.curr_pos[0] + 1+20, b.column_count - (s1.curr_pos[1])-4);
//        int posPiece3 = (s1.curr_pos[0] +50, b.column_count - (s1.curr_pos[1] )-7);
//        int pos2Piece3 = (s1.curr_pos[0] +50, b.column_count - (s1.curr_pos[1] + 1)-7);
//        int pos3Piece3 = (s1.curr_pos[0] + 1+50, b.column_count - (s1.curr_pos[1] )-7);
//        int posPiece4 = (s1.curr_pos[0] +48, b.column_count - (s1.curr_pos[1] )-12);
//        int pos2Piece4 = (s1.curr_pos[0] +48, b.column_count - (s1.curr_pos[1] + 1)-12);
//        int pos3Piece4 = (s1.curr_pos[0] +1+48, b.column_count - (s1.curr_pos[1] + 1)-12);
//        int pos4Piece4 = (s1.curr_pos[0] + 1+48, b.column_count - (s1.curr_pos[1] )-12);
//        int posPiece5 = (s1.curr_pos[0] +48, b.column_count - (s1.curr_pos[1] )-16);
//        int pos2Piece5= (s1.curr_pos[0] +48, b.column_count - (s1.curr_pos[1] + 1)-16);
//        int pos3Piece5= (s1.curr_pos[0] + 1+48, b.column_count - (s1.curr_pos[1] + 1)-16);
//        int pos4Piece5= (s1.curr_pos[0] + 1+48, b.column_count - (s1.curr_pos[1])-16);
//        int posPiece6 = (s1.curr_pos[0] +53, b.column_count - (s1.curr_pos[1] )-1);
//        int pos2Piece6= (s1.curr_pos[0] +53, b.column_count - (s1.curr_pos[1] + 1)-1);
//        int pos3Piece6= (s1.curr_pos[0] + 1+53, b.column_count - (s1.curr_pos[1] + 1)-1);
//        int pos4Piece6= (s1.curr_pos[0] + 1+53, b.column_count - (s1.curr_pos[1] )-1);
//        int posPiece7 =(s1.curr_pos[0] +53, b.column_count - (s1.curr_pos[1] )-5);
//        int pos2Piece7=(s1.curr_pos[0] +53, b.column_count - (s1.curr_pos[1] + 1)-5);
//        int pos3Piece7=(s1.curr_pos[0] + 1+53, b.column_count - (s1.curr_pos[1] + 1)-5);
//        int pos4Piece7=(s1.curr_pos[0] + 1+53, b.column_count - (s1.curr_pos[1] )-5);
//        int posPiece8 = (s1.curr_pos[0] +53, b.column_count - (s1.curr_pos[1])-9);
//        int pos2Piece8=(s1.curr_pos[0] +53, b.column_count - (s1.curr_pos[1] + 1)-9);
//        int pos3Piece8=(s1.curr_pos[0] +1+53, b.column_count - (s1.curr_pos[1] + 1)-9);
//        int pos4Piece8= (s1.curr_pos[0] + 1+53, b.column_count - (s1.curr_pos[1] )-9);
//        int posPiece9 =(s1.curr_pos[0] +52, b.column_count - (s1.curr_pos[1] )-13);
//        int pos2Piece9=(s1.curr_pos[0] +52, b.column_count - (s1.curr_pos[1] + 1)-13);
//        int pos3Piece9=(s1.curr_pos[0] + 1+52, b.column_count - (s1.curr_pos[1] + 1)-13);
//        int pos4Piece9=(s1.curr_pos[0] + 1+52, b.column_count - (s1.curr_pos[1] )-13);
    }

//    else cout << "Not hovering" << endl;
}

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

void Shape::draw(PieceColor pieceColor, Board b) {
    //glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
    for (int i = 0; i < b.column_count; i++) {
        for (int j = 0; j < b.row_count; j++) {
            if (b.blocks[i][j]) {
                glVertex2f(j, b.column_count - i);
                glVertex2f(j, b.column_count - i - 1);
                glVertex2f(j + 1, b.column_count - i - 1);
                glVertex2f(j + 1, b.column_count - i);
                //cout << "draw 1st j = " << j << " - column =" << b.column_count << endl;
            }
        }
    }
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
                glVertex2f(curr_pos[0] + j, b.column_count - (curr_pos[1] + i));
                glVertex2f(curr_pos[0] + j, b.column_count - (curr_pos[1] + i + 1));
                glVertex2f(curr_pos[0] + j + 1, b.column_count - (curr_pos[1] + i + 1));
                glVertex2f(curr_pos[0] + j + 1, b.column_count - (curr_pos[1] + i));
//                cout << "draw: 2nd curr_pos[0] + j = " << curr_pos[0] + j
//                     << " - b.column_count - (curr_pos[1] + i) =" << b.column_count - (curr_pos[1] + i)
//                     << " * 20 j: " <<   (curr_pos[0] + j ) * 20 << " - " << (curr_pos[0] + j + 1) * 20
//                     << " * 20 i: " <<   (b.column_count - (curr_pos[1] + i)  ) * 20 << " - " << (b.column_count - (curr_pos[1] + i + 1) ) * 20
//                        << endl;
        }
    }

    glEnd();
}

Board::Board() {

}

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
