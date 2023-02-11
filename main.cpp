#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main() {
    std::cout << "Hello, World!" << std::endl;
    glfwInit();
    GLFWwindow *window = glfwCreateWindow(64, 32, "Emulato 8BIT", nullptr, nullptr);
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    float t[] = {
            -.5f, -.5f, 0.f,
            0.f, .5f, 0.f,
            .5f, -.5f, 0.f,

    };
    uint32_t v;
    glGenBuffers(1, &v);
    glBindBuffer(GL_ARRAY_BUFFER, v);
    size_t i = sizeof(t) * (sizeof(t) / sizeof(t[0]));
    glBufferData(GL_ARRAY_BUFFER, i, &t[0], GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, (void *) 0);
    glEnableVertexAttribArray(0);

    while (!glfwWindowShouldClose(window)) {
        glClear(GL_COLOR_BUFFER_BIT);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(window);
        glfwPollEvents();
    }


    return 0;
}
