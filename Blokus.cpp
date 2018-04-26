//
// Created by might on 4/19/2018.
//

#include "Blokus.h"

Shape::Shape(){
    memcpy(curr_block, tetrominos[rand() % 1], 5 * 5 * sizeof(int));
    curr_pos[0] = init_pos[0];
    curr_pos[1] = init_pos[1];
}
void Shape::init_curr_block(){
    memcpy(curr_block, tetrominos[rand() %21], 5 * 5 * sizeof(int));
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
    init_curr_block();
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