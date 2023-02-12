//
// Created by beloin on 11/02/23.
//

#include <glad/glad.h>
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

float initialT[]{
        0.f, .01f, 0.f,
        0.f, .0f, 0.f,
        .01f, .0f, 0.f,
        .01f, .01f, 0.f,
};

void drawSquare(int x, int y, char size) {
    float copy[12];
    for (int i = 0; i < 12; i++) {
        copy[i] = initialT[i];
    }



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

