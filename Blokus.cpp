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
    memcpy(curr_block, tetrominos[rand() % 21], 5 * 5 * sizeof(int));
    curr_pos[0] = init_pos[0];
    curr_pos[1] = init_pos[1];
}
bool Shape::isempty(Board b, int next_x, int next_y){
    if (next_x < 0 || row_count <= next_x) {
        return false;
    }
    if (next_y < 0 || column_count <= next_y) {
        return false;
    }
    if (b.blocks[next_y][next_x]) {
        return false;
    }
    return true;
}
bool Shape::move(Board b,int x, int y){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
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
    int tmp[4][4] = {};
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (curr_block[i][j]) {
                int next_x = curr_pos[0] + i;
                int next_y = curr_pos[1] + 4 - j;
                if (!isempty(b,next_x, next_y)) {
                    return;
                }
                tmp[4 - j][i] = 1;
            }
        }
    }
    memcpy(curr_block, tmp, 4 * 4 * sizeof(int));
    glutPostRedisplay();
}
void Shape::throw_new_block(Board b){
    init_curr_block();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (curr_block[i][j] && b.blocks[curr_pos[1] + i][curr_pos[0] + j]) {
                //game_over();
                return;
            }
        }
    }
    glutPostRedisplay();
    glutTimerFunc(interval, timer, 0);
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

Board::Board(){
    /*glBegin(GL_LINES);
    glColor3f(1.0f, 0.0f, 0.0f); // Red (RGB)
    for (float x = 0; x < 600; x += 30) {
        glVertex3f(x, 0.0f, 0.0f);
        glVertex3f(x, float(600), 0.0f);
    }
    for (float y = 0; y < 600; y += 30) {
        glVertex3f(0.0f, y, 0.0f);
        glVertex3f(float(600), y, 0.0f);
    }
    glEnd();*/
}