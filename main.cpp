#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "implementation.h"

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_SPACE) {

        if (action == GLFW_PRESS) {
            std::cout << "Fuck off" << std::endl;
        }
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::cout << bolsonaro << std::endl;
    glfwInit();
    GLFWwindow *window = glfwCreateWindow(640, 320, "Emulato 8BIT", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    float t[] = {
            0.4f, .5f, 0.f,
            -.1f, -.5f, 0.f,
            .9f, -.5f, 0.f,
    };

    float t2[] = {
            -0.4f, .2f, 0.f,
            -.6f, -.2f, 0.f,
            -.2f, -.2f, 0.f,

    };
    glViewport(0, 0, 640, 320);
    glfwSetKeyCallback(window, keyCallback);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);

        // First triangle
        GLuint v;
        glGenBuffers(1, &v);
        glBindBuffer(GL_ARRAY_BUFFER, v);

        GLsizeiptr i = sizeof(t) * (sizeof(t) / sizeof(t[0]));
        glBufferData(GL_ARRAY_BUFFER, i, &t[0], GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);

        glDrawArrays(GL_POLYGON, 0, 3);

        GLsizeiptr i2 = sizeof(t2) * (sizeof(t2) / sizeof(t2[0]));
        glBufferData(GL_ARRAY_BUFFER, i2, &t2[0], GL_STATIC_DRAW);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, nullptr);

        glDrawArrays(GL_TRIANGLES, 0, 3); // Or GL_POLYGON

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
