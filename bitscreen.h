//
// Created by beloin on 12/02/23.
//

#ifndef OPENGL_EXAMPLE_BITSCREEN_H
#define OPENGL_EXAMPLE_BITSCREEN_H

void drawSquare(int x, int y, char size);

void drawSquare2(int x, int y, char size, float *buffer);

void updateScreen(const char *scr);

void updateScreen2(const char *scr, float **buffer);

#endif //OPENGL_EXAMPLE_BITSCREEN_H
