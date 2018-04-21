//
// Created by might on 4/19/2018.
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

using namespace std;
//////////////Board Class////////////
class Board{
public:
    static const int column_count = 20;
    static const int row_count = 20;
    int blocks[column_count][row_count] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };
    Board();
};
//////////////Shapes Class///////////
class Shape { ;
public:
    const int interval = 500;
    const int block_size = 20;
    const int init_pos[2] = {3, 0};
    int curr_block[5][5] = {};
    int curr_pos[2] = {};

    const int tetrominos[21][5][5] = {
            {       {0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0}},

            {       {0, 0, 0, 0, 0},
                    {0, 1, 1, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0}},


            {       {0, 0, 0, 0, 0},
                    {0, 1, 1, 0, 0},
                    {0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0}},

            {       {0, 0, 0, 0, 0},
                    {0, 1, 1, 1, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0}},

            {       {0, 0, 0, 0, 0},
                    {0, 1, 1, 0, 0},
                    {0, 1, 1, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0}},

            {       {0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0},
                    {0, 1, 1, 1, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0}},

            {       {0, 0, 0, 0, 0},
                    {0, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0}},

            {       {0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0}},

            {       {0, 0, 0, 0, 0},
                    {0, 0, 1, 1, 0},
                    {0, 1, 1, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0}},

            {       {0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0},
                    {0, 1, 1, 1, 1},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0}},

            {       {0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0},
                    {0, 0, 1, 0, 0},
                    {0, 1, 1, 1, 0},
                    {0, 0, 0, 0, 0}},

            {       {0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0},
                    {0, 1, 0, 0, 0},
                    {0, 1, 1, 1, 0},
                    {0, 0, 0, 0, 0}},

            {       {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 1, 1, 1},
                    {0, 1, 1, 0, 0},
                    {0, 0, 0, 0, 0}},

            {       {0, 0, 0, 0, 0},
                    {0, 0, 0, 1, 0},
                    {0, 1, 1, 1, 0},
                    {0, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0}},

            {       {0, 0, 0, 0, 1},
                    {0, 0, 0, 0, 1},
                    {0, 0, 0, 0, 1},
                    {0, 0, 0, 0, 1},
                    {0, 0, 0, 0, 1}},

            {       {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0},
                    {1, 1, 0, 0, 0},
                    {1, 1, 0, 0, 0}},

            {       {0, 0, 0, 0, 0},
                    {0, 0, 1, 1, 0},
                    {0, 1, 1, 0, 0},
                    {0, 1, 0, 0, 0},
                    {0, 0, 0, 0, 0}},

            {       {0, 0, 0, 0, 0},
                    {0, 1, 1, 0, 0},
                    {0, 1, 0, 0, 0},
                    {0, 1, 1, 0, 0},
                    {0, 0, 0, 0, 0}},

            {       {0, 0, 0, 0, 0},
                    {0, 0, 1, 1, 0},
                    {0, 1, 1, 0, 0},
                    {0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0}},

            {       {0, 0, 0, 0, 0},
                    {0, 0, 1, 0, 0},
                    {0, 1, 1, 1, 0},
                    {0, 0, 1, 0, 0},
                    {0, 0, 0, 0, 0}},

            {       {0, 0, 0, 0, 0},
                    {0, 1, 0, 0, 0},
                    {1, 1, 1, 1, 0},
                    {0, 0, 0, 0, 0},
                    {0, 0, 0, 0, 0}},

    };
public:
    Shape();
    void init_curr_block();
    bool isempty(Board b,int next_x, int next_y);
    bool move(Board b,int x, int y);
    void rotate(Board b);
    void throw_new_block(Board b);
    //void timer(int value);
};

#endif //BLOK_BOYS_BLOKUS_H
