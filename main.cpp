#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "implementation.h"
#include "bitscreen.h"

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_SPACE) {

        if (action == GLFW_PRESS) {
            std::cout << "Fuck off" << std::endl;
        }
    }
}

int main() {
    char screen[64 * 32];

    for (char &i: screen) {
        i = 0;
    }

    // Draw:
    // * * * *
    //         * * * * * * * * * // Index = x + 64
    // * * * * // x + (2 * 64)

    // * * * *
    screen[0] = 1;
    screen[1] = 1;
    screen[2] = 1;
    screen[3] = 1;
    //         * * * * * * * * * // Index = x + 64
    screen[0 + 4 + 64] = 1;
    screen[1 + 4 + 64] = 1;
    screen[2 + 4 + 64] = 1;
    screen[3 + 4 + 64] = 1;
    screen[4 + 4 + 64] = 1;
    screen[5 + 4 + 64] = 1;
    screen[6 + 4 + 64] = 1;
    screen[7 + 4 + 64] = 1;
    // * * * * // x + (2 * 64)
    screen[0 + 2 * 64] = 1;
    screen[1 + 2 * 64] = 1;
    screen[2 + 2 * 64] = 1;
    screen[3 + 2 * 64] = 1;

    std::cout << "Hello, World!" << std::endl;
    std::cout << bolsonaro << std::endl;
    glfwInit();
    GLFWwindow *window = glfwCreateWindow(640, 320, "Emulato 8BIT", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    float t[]{
            0.4f, .5f, 0.f,
            -.1f, -.5f, 0.f,
            .9f, -.5f, 0.f,
            .9f, .5f, 0.f,
    };

    float t2[] = {
            -0.4f, .2f, 0.f,
            -.6f, -.2f, 0.f,
            -.2f, -.2f, 0.f,

    };
    glViewport(0, 0, 640, 320);
    glfwSetKeyCallback(window, keyCallback);
    auto **buffer = (float **) malloc(sizeof(float *) * 64 * 32);
    for (int i = 0; i < 64 * 32; ++i) {
        buffer[i] = (float *) malloc(sizeof(float) * 12);
    }
    float initialT[]{
            -1.f, -.99f, 0.f, // P0 Top left, goes anticlockwise
            -1.f, -1.f, 0.f, // P1
            -.99f, -1.f, 0.f, // P2
            -.99f, -.99f, 0.f, // P3
    };

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // First triangle
        GLuint v;
        glGenBuffers(1, &v);
        glBindBuffer(GL_ARRAY_BUFFER, v);

//        glBufferData(GL_ARRAY_BUFFER, i, &t[0], GL_STATIC_DRAW);
//        glEnableVertexAttribArray(0);
//        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);
//
//        glDrawArrays(GL_POLYGON, 0, 4);
//
//        GLsizeiptr i2 = sizeof(t2) * (sizeof(t2) / sizeof(t2[0]));
//        glBufferData(GL_ARRAY_BUFFER, i2, &t2[0], GL_STATIC_DRAW);
//        glEnableVertexAttribArray(0);
//        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);
//        glDrawArrays(GL_TRIANGLES, 0, 3); // Or GL_POLYGON

//            glBufferData(GL_ARRAY_BUFFER, i, &initialT[0], GL_STATIC_DRAW);
//            glEnableVertexAttribArray(0);
//            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);
//            glDrawArrays(GL_POLYGON, 0, 4);


//        updateScreen(screen);
        // TODO read: https://stackoverflow.com/questions/40060212/rendering-a-bit-array-with-opengl if does not work:
        //  watch: https://www.youtube.com/watch?v=45MIykWJ-C4&ab_channel=freeCodeCamp.org
        updateScreen2(screen, buffer);
        for (int j = 0; j < 64 * 32; ++j) {
            float *bff = buffer[j];
            // Always the size is 12
            GLsizeiptr sz = (sizeof(float) * 12) * (sizeof(float) * 12) / sizeof(bff[0]);
            glBufferData(GL_ARRAY_BUFFER, sz, &bff[0], GL_STATIC_DRAW);
            glEnableVertexAttribArray(0);
            glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);

            glDrawArrays(GL_POLYGON, 0, 4);
        }




        // To draw freely
        // glColor3d(0,0,0);
        // glBegin(GL_POLYGON);
        // glVertex2d(...); ...
        // glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    return 0;
}
