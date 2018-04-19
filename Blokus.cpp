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
bool Shape::isempty(int next_x, int next_y){
    if (next_x < 0 || row_count <= next_x) {
        return false;
    }
    if (next_y < 0 || column_count <= next_y) {
        return false;
    }
    if (blocks[next_y][next_x]) {
        return false;
    }
    return true;
}
bool Shape::move(int x, int y){
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (curr_block[i][j]) {
                int next_x = curr_pos[0] + j + x;
                int next_y = curr_pos[1] + i + y;
                if (!isempty(next_x, next_y)) {
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
void rotate();
void throw_new_block();