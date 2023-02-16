//
// Created by beloin on 11/02/23.
//

#include <glad/glad.h>
#include <cstdlib>
#include "bitscreen.h"

/**
 * @param scr - Input Pointer to a 64*32 1D array WxH
 */
void updateScreen(const char *scr) {
    // TODO: How to draw?
    // Create 10x10 Squares?
    char size = 10;

    // 64 columns, 32 rows
    for (int i = 0; i < 64; ++i) {
        for (int j = 0; j < 32; ++j) {
            int index = i + (j * 64);
            if (scr[index]) {
                drawSquare(i, j, size);
            }
        }
    }
}

void emptySquare(float *pDouble);

void updateScreen2(const char *scr, float **buffer) {
    char size = 1;
    // 64 columns, 32 rows
    for (int i = 0; i < 64; ++i) {
        for (int j = 0; j < 32; ++j) {
            int index = i + (j * 64);
            if (scr[index]) {
                drawSquare2(i, j*64, size, buffer[i]);
            } else {
                emptySquare(buffer[i]);
            }
        }
    }
}

void emptySquare(float *pDouble) {
    for (int i = 0; i < 12; i++) {
        pDouble[i] = 0;
    }
}

float initialT[]{
        -1.f, -.99f, 0.f, // P0 Top left, goes anticlockwise
        -1.f, -1.f, 0.f, // P1
        -.99f, -1.f, 0.f, // P2
        -.99f, -.99f, 0.f, // P3
};


void drawSquare2(int x, int y, char size, float *buffer) {
    int i;
    float *copy = buffer;
    float _x = (((float) x) / 100) * ((float) size);
    float _y = (((float) y) / 100) * ((float) size);
    for (i = 0; i < 12; i++) {
        copy[i] = initialT[i];
    }
    int ix = 0;
//    for (i = 0; i < 12; i++) {
//        if (ix == 0) {
//            copy[i] = _x + copy[i];
//            ix++;
//        } else if (ix == 1) {
//            copy[i] = _y + copy[i];
//            ix++;
//        } else if (ix == 2) {
//            ix = 0;
//        }
//    }
}

void drawSquare(int x, int y, char size) {
    float halfway = ((float) size) / 2;
    halfway = halfway / 100;
    float _x = ((float) x) / 100;
    float _y = ((float) y) / 100;

    glColor3d(0, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2d(_x + halfway, _y + halfway);
    glVertex2d(_x + halfway, _y - halfway);
    glVertex2d(_x - halfway, _y - halfway);
    glVertex2d(_x - halfway, _y + halfway);

    glEnd();
}

